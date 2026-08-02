
Tester::Tester(const std::string& s_d,const std::string& e_d) :m_source_dir{ s_d }, m_expected_dir{ e_d } {
    for (int i = 0; i < (int)ErrorType::ERROR_COUNT;i++) {
        ErrorType e_type = ErrorType{i};
        m_error_name_to_error_type[ErrorTraits::get_name(e_type)] = e_type;
    }
}


std::string Tester::read_entire_file(const fs::path& file_path) {
    std::vector<std::string> lines;
	std::ifstream file(file_path);
	if (!file.is_open())
		return {};

    std::string line;
    while (std::getline(file, line)) {

        if (line == "#------------------")
            break;

        line = line + '\n';
        lines.push_back(line);
    }

    std::string read_source_code;
    for (auto &line : lines) {
        read_source_code += line;
    }

    return read_source_code;
}

std::vector<std::string> Tester::read_expected_lines(const fs::path& file_path) {
	std::vector<std::string> lines;
	std::ifstream file(file_path);
	
	std::string line;
	while (std::getline(file,line)){
        if (line=="#------------------") {
            std::string expected_value;
            while (std::getline(file,expected_value))
            {
                if (expected_value.empty())
                    continue;

                lines.push_back(expected_value);
            }
            break;
        }
	}

	return lines;
}

void Tester::run_all_tests(const std::vector<std::string>& test_names,const std::vector<std::string>& test_error_names) {
    if (!fs::exists(m_source_dir)) {
        std::cout << "source directory does not exit\n";
        return;
    }

    if (!fs::exists(m_expected_dir)) {
        std::cout << "expected outputs directory does not exit\n";
        return;
    }

    size_t tests_passed = 0;
    size_t tests_failed = 0;
    for (const std::string &test_name : test_names) {
        fs::path test_path =  m_source_dir + "\\" + test_name + ".txt";
    
        std::cout << "Running test: " << test_path.filename().string() << "...\n";

        std::cout << "===========================\n";
        if (run_single_test(test_path, "",false)) {
            std::cout << "Passed\n";
            tests_passed++;
        }
        else {
            std::cout << "Failed\n";
            tests_failed++;
        }
        std::cout << "===========================\n";

    }
    std::cout << "Wrap up: " << std::endl;
    std::cout << "Number of tests passed: " << tests_passed << std::endl;
    std::cout << "Number of tests failed: " << tests_failed << std::endl;

    size_t error_tests_passed = 0;
    size_t error_tests_failed = 0;
    std::cout << "\n\n\n";

    for (const std::string &test_error_name : test_error_names) {
        fs::path test_path =  m_source_dir + "\\" + test_error_name + ".txt";
    
        std::cout << "Running error test: " << test_path.filename().string() << "...\n";

        std::cout << "===========================\n";
        if (run_single_test(test_path, "",true)) {
            std::cout << "Passed\n";
            error_tests_passed++;
        }
        else {
            std::cout << "Failed\n";
            error_tests_failed++;
        }
        std::cout << "===========================\n";
    }

    std::cout << "Wrap up: " << std::endl;
    std::cout << "Number of error tests passed: " << error_tests_passed << std::endl;
    std::cout << "Number of error tests failed: " << error_tests_failed << std::endl;
}

bool Tester::run_single_test(const fs::path& source_file, const fs::path& expected_path,bool is_error_test) {
    IRPrinter printer;
    std::string source_code = read_entire_file(source_file);
    std::vector<std::string> expected_outputs = read_expected_lines(source_file);

    antlr4::ANTLRInputStream stream(source_code);
    GrammarLexer lexer(&stream);
    antlr4::CommonTokenStream tokens(&lexer);
    GrammarParser parser(&tokens);

    class MyErrorListener : public antlr4::ANTLRErrorListener {
    public:
        bool m_syntax_error = false;
        void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line,
            size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override {
            m_syntax_error = true;
            std::cout << "Syntax error: " << line << ": " << charPositionInLine << ": " << msg << std::endl;
        }

        void reportAmbiguity(antlr4::Parser*, const dfa::DFA&, size_t, size_t, bool, const antlrcpp::BitSet&, atn::ATNConfigSet*) override {}
        void reportAttemptingFullContext(antlr4::Parser*, const dfa::DFA&, size_t, size_t, const antlrcpp::BitSet&, atn::ATNConfigSet*) override {}
        void reportContextSensitivity(antlr4::Parser*, const dfa::DFA&, size_t, size_t, size_t, atn::ATNConfigSet*) override {}
    };

    MyErrorListener errorListener;
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    antlr4::tree::ParseTree* tree = parser.prog();
    if (errorListener.m_syntax_error) return false;

    ReferencePtr<ProgNode> prog = static_cast<MyContextSuperClass*>(tree)->m_node.cast<ProgNode>();

    class Listener : public antlr4::tree::ParseTreeListener {
    public:
        void enterEveryRule(antlr4::ParserRuleContext* ctx) override {
            auto my_ctx = static_cast<MyContextSuperClass*>(ctx);
            if (my_ctx && my_ctx->m_node) {
                my_ctx->m_node->set_line_number(my_ctx->getStart()->getLine());
            }
        }
        void exitEveryRule(antlr4::ParserRuleContext*) override {}
        void visitErrorNode(antlr4::tree::ErrorNode*) override {}
        void visitTerminal(antlr4::tree::TerminalNode*) override {}
    };

    antlr4::tree::IterativeParseTreeWalker walker;
    Listener listener;
    walker.walk(&listener, tree);

    IRErrorCollector error_collector{};
    IRProgram ir_program;
    ir_program.set_checker_listener(&error_collector);
    ASTConverter converter{ prog, &ir_program, ir_program.get_dtm_manager() };

    class ASTConverterImpl : public ASTConverterListener {
    public:
        bool has_error = false;
        std::vector<ASTConverterError> m_errors;
        void error(const ASTConverterError& err) override { 
            has_error = true;
            m_errors.push_back(err);
            std::cout << "ASTConverterError: Line " << err.get_line_number() << " : " << err.get_msg() << std::endl; 
        }
        const std::vector<ASTConverterError>& get_errors() const { return m_errors; }
    };

    ASTConverterImpl ast_conv_impl{};
    converter.convert(&ast_conv_impl);

    ir_program.check_program();
    printer.print_ir_representation(ir_program);

    
    IRInliner inliner;
    std::vector<IROperand> fn_arguments{};
    IRFunction* main_fn = ir_program.get_function("main", fn_arguments);

    if (!main_fn) {
        std::cout << "there's no main function in the source file";
        return false;
    }

    size_t expected_inline_expansions = 0;

    for (IRBasicBlock* block : main_fn->get_basic_blocks()) {
        for (IRTriple* triple : block->get_all_triples()) {
            if (triple->get_ir_operation() != IROperation::FUNCTION_CALL)
                continue;

            IRFunction* callee = triple->m_operands[0].get_function();

            if (callee != main_fn && callee->is_inline())
                expected_inline_expansions++;
        }
    }

    const size_t expansions_before = inliner.m_inline_instance_counter;

    if (!is_error_test)
        inliner.expand_functions(main_fn);

    if (!is_error_test &&
        inliner.m_inline_instance_counter - expansions_before < expected_inline_expansions) {
        std::cout << "not all inline function calls were expanded\n";
        return false;
    }


    if (is_error_test) {
        auto expected_errors = ast_conv_impl.get_errors();
        if (expected_outputs.size() != expected_errors.size())
            return false;

        for (int i = 0; i < expected_errors.size();i++) {
            std::istringstream stream{expected_outputs[i]};
            int output_line_number;
            stream >> output_line_number;
            std::string output_error_type_str;
            stream >> output_error_type_str;
            ErrorType output_error_type = m_error_name_to_error_type.at(output_error_type_str);

            int expeceted_line_number = expected_errors[i].get_line_number();
            ErrorType expected_error_type = expected_errors[i].get_error_type();
            
            if (output_line_number != expeceted_line_number || output_error_type != expected_error_type) {
                std::cout << "wrong result at the line :" << (i + 1) << "\n";
                std::cout << "expected :" << expected_errors[i].get_msg() << "\n";
                std::cout << "at the line: " << expeceted_line_number << "\n";

                std::cout << "received :" << output_error_type_str << "\n";
                std::cout << "at the line: " << output_line_number << "\n";

                system("pause");

                return false;

            }
        }

        return true;
    }
    else {
        TestInterpreterListener test_listener;
        Interpreter interpreter{ &ir_program,main_fn,fn_arguments };
        interpreter.set_listener(&test_listener);
    
        interpreter.start();

        auto& actual_outputs = test_listener.get_messages();

        if (actual_outputs.size() != expected_outputs.size()) {
            std::cout << "differenet number of results, expected: " << expected_outputs.size() << "\n ";
            std::cout << "Got: " << actual_outputs.size() << "\n";
            return false;
        }

        for (size_t i = 0; i < expected_outputs.size(); i++) {
            if (actual_outputs[i] != expected_outputs[i]) {
                std::cout << "wrong result at the line :" << (i + 1) << "\n";
                std::cout << "expected :" << expected_outputs[i] << "\n";
                std::cout << "received :" << actual_outputs[i] << "\n";
                system("pause");
                return false;
            }
        }
    }

    return true;
}
