
Tester::Tester(const std::string& s_d,const std::string& e_d) :m_source_dir{ s_d }, m_expected_dir{ e_d } {}

// wPISdu
std::string Tester::read_entire_file(const fs::path& file_path) {
    std::vector<std::string> lines;
	std::fstream file(file_path);
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

void Tester::run_all_tests(const std::vector<std::string>& test_names) {
    if (!fs::exists(m_source_dir)) {
        std::cout << "source directory does not exit\n";
        return;
    }

    if (!fs::exists(m_expected_dir)) {
        std::cout << "expected outputs directory does not exit\n";
        return;
    }

    size_t passed = 0;
    size_t failed = 0;
    for (const std::string &test_name : test_names) {
        fs::path test_path =  m_source_dir + "\\" + test_name + ".txt";
        //fs::path expected_test_path =  m_source_dir +"\\" + test_name + "_output.txt";
    
        std::cout << "Running test: " << test_path.filename().string() << "...\n";

        //if (!fs::exists(expected_test_path)) {
        //    std::cout << "Test skipped, no expected file\n";
        //    continue;
        //}

        std::cout << "===========================\n";
        if (run_single_test(test_path, "")) {
            std::cout << "Passed\n";
            passed++;
        }
        else {
            std::cout << "Failed\n";
            failed++;
        }
        std::cout << "===========================\n";

    }

    //test_1.txt
    //test_1_output.txt
    
    //for (const auto& entry : fs::directory_iterator(m_source_dir)) {
    //    if (entry.is_regular_file()) {
    //        fs::path source_path = entry.path();
    //        fs::path expected_path = fs::path(m_expected_dir) / source_path.filename();

    //        std::cout << "Running test: " << source_path.filename().string() << "...\n";

    //        if (!fs::exists(expected_path)) {
    //            std::cout << "Test skipped, no expected file\n";
    //            continue;
    //        }

    //        if (run_single_test(source_path, expected_path)) {
    //            std::cout << "Passed\n";
    //            passed++;
    //        }
    //        else {
    //            std::cout << "Failed\n";
    //            failed++;
    //        }

    //    }
    //}

    std::cout << "Wrap up: " << std::endl;
    std::cout << "Number of tests passed: " << passed << std::endl;
    std::cout << "Number of tests failed: " << failed << std::endl;
}


bool Tester::run_single_test(const fs::path& source_file, const fs::path& expected_path) {
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
        void error(const ASTConverterError& err) override { 
            has_error = true;
            std::cout << "ASTConverterError: Line " << err.get_line_number() << " : " << err.get_msg() << std::endl; }
    };

    ASTConverterImpl ast_conv_impl{};
    converter.convert(&ast_conv_impl);

    if (ast_conv_impl.has_error) 
        return false;

    ir_program.check_program();
    //printer.
    printer.print_ir_representation(ir_program);

    std::vector<IROperand> fn_arguments{};
    IRFunction* fn = ir_program.get_function("main", fn_arguments);
    
    if (!fn) {
        std::cout << "there's no main function in the source file";
        return false;
    }

    TestInterpreterListener test_listener;
    Interpreter interpreter{ &ir_program,fn,fn_arguments };
    interpreter.set_listener(&test_listener);
    
    interpreter.start();

    auto& actual_outputs = test_listener.get_messages();

    if (actual_outputs.size() != expected_outputs.size()) {
        std::cout << "differenet number of results, expected: " << expected_outputs.size() << "\n ";
        std::cout << "Got: " << actual_outputs.size() << "\n";
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

    return true;
}