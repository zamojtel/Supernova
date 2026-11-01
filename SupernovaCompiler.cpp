
SupernovaCompiler::SupernovaCompiler() {}

void SupernovaCompiler::compile(const std::string& source_code) {
	IRPrinter printer;

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
	if (errorListener.m_syntax_error) {
		throw std::runtime_error("error1 -------------");
	}

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

	m_ir_program.set_checker_listener(&error_collector);
	ASTConverter converter{ prog, &m_ir_program, m_ir_program.get_dtm_manager() };

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

	m_ir_program.check_program();
	printer.print_ir_representation(m_ir_program);
	printer.print_errors(error_collector);

	IRInliner inliner;
	size_t expected_inline_expansions = 0;

	const size_t expansions_before = inliner.m_inline_instance_counter;

	if (inliner.m_inline_instance_counter != 0 &&
		inliner.m_inline_instance_counter - expansions_before < expected_inline_expansions) {
		std::cout << "not all inline function calls were expanded\n";
		throw std::runtime_error("error2 ----------- not all functions were inlined");
	}
	IRToLLVMIRConverter ir_to_llvm_converter(&m_ir_program);
	IRPrinter printer_new;

	m_ir_program.sort_blocks();
	printer_new.print_ir_representation(m_ir_program);

	auto llvm_module = ir_to_llvm_converter.convert();
	auto jit_result = llvm::orc::LLJITBuilder().create();

	if (!jit_result) {
		llvm::errs() << llvm::toString(jit_result.takeError()) << '\n';
		throw std::runtime_error("error 3 ---------- jit related");
	}

	m_jit = std::move(*jit_result);

	bool invalid_module = llvm_module.withModuleDo(
		[&](llvm::Module& module) {
			module.setDataLayout(m_jit->getDataLayout());
			module.setTargetTriple(m_jit->getTargetTriple().str());
			bool broken = llvm::verifyModule(module, &llvm::errs());
			if (!broken)
				print_module_assembly(module);
				return broken;
		}
	);

	if (invalid_module)
		throw std::runtime_error("error 3 ----- invalid module ");

	if (auto error = m_jit->addIRModule(std::move(llvm_module))) {
		llvm::errs() << llvm::toString(std::move(error)) << '\n';
		throw std::runtime_error("error 4 ---- problem with adding module");
	}
}

template <class T>
    T SupernovaCompiler::get_function(const std::string& fn_name,const std::vector<TypeRef>& argument_types) {
    IRBaseFunction* fn = m_ir_program.get_function(fn_name,argument_types);
    std::string llvm_function_name;

    if (fn->is_internal()) {
        llvm_function_name = FunctionNames::get_internal_name(fn_name);
    }
    else
        throw std::runtime_error("external function cannot be provided");

    llvm::Expected<llvm::orc::ExecutorAddr> function = m_jit->lookup(llvm_function_name);
    auto compiled_function = function->toPtr<T>();
    return compiled_function;
}