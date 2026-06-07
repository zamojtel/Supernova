
#include <iostream>
#include <vector>
#include <array>
#include <variant>
#include <string>
#include <format>
#include <fstream>
#include <typeinfo>
#include <optional>
#include <type_traits>
#include <functional>
#include <unordered_map>
#include <filesystem>
#include <sstream>

#define ANTLR4CPP_STATIC
#pragma comment(lib,"antlr4-runtime.lib")
#undef ERROR

#include <ParserRuleContext.h>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Verifier.h"

#include "Includes.h"

#pragma comment(lib, "LLVMCore.lib")
#pragma comment(lib, "LLVMExecutionEngine.lib")
#pragma comment(lib, "LLVMIRReader.lib")
#pragma comment(lib, "LLVMJITLink.lib")
#pragma comment(lib, "LLVMObject.lib")
#pragma comment(lib, "LLVMOrcDebugging.lib")
#pragma comment(lib, "LLVMOrcJIT.lib")
#pragma comment(lib, "LLVMOrcShared.lib")
#pragma comment(lib, "LLVMOrcTargetProcess.lib")
#pragma comment(lib, "LLVMPasses.lib")
#pragma comment(lib, "LLVMRuntimeDyld.lib")
#pragma comment(lib, "LLVMSupport.lib")
#pragma comment(lib, "LLVMTargetParser.lib")
#pragma comment(lib, "LLVMX86CodeGen.lib")
#pragma comment(lib, "LLVMX86AsmParser.lib")
#pragma comment(lib, "LLVMX86Desc.lib")
#pragma comment(lib, "LLVMX86Disassembler.lib")
#pragma comment(lib, "LLVMX86Info.lib")
//#pragma comment(lib, "llvm_gtest_main.lib")
//#pragma comment(lib, "llvm_gtest.lib")
//#pragma comment(lib, "LLVMTestingSupport.lib")
#pragma comment(lib, "LLVMCoroutines.lib")
#pragma comment(lib, "LLVMHipStdPar.lib")
#pragma comment(lib, "LLVMipo.lib")
#pragma comment(lib, "LLVMFrontendOpenMP.lib")
#pragma comment(lib, "LLVMFrontendOffloading.lib")
#pragma comment(lib, "LLVMObjectYAML.lib")
//#pragma comment(lib, "LLVMFrontendAtomic.lib")
//#pragma comment(lib, "LLVMFrontendDirective.lib")
#pragma comment(lib, "LLVMLinker.lib")
#pragma comment(lib, "LLVMVectorize.lib")
//#pragma comment(lib, "LLVMSandboxIR.lib")
#pragma comment(lib, "LLVMWindowsDriver.lib")
#pragma comment(lib, "LLVMOption.lib")
#pragma comment(lib, "LLVMCFGuard.lib")
#pragma comment(lib, "LLVMGlobalISel.lib")
#pragma comment(lib, "LLVMIRPrinter.lib")
#pragma comment(lib, "LLVMInstrumentation.lib")
#pragma comment(lib, "LLVMAsmPrinter.lib")
#pragma comment(lib, "LLVMSelectionDAG.lib")
#pragma comment(lib, "LLVMCodeGen.lib")
#pragma comment(lib, "LLVMTarget.lib")
#pragma comment(lib, "LLVMObjCARCOpts.lib")
#pragma comment(lib, "LLVMScalarOpts.lib")
#pragma comment(lib, "LLVMAggressiveInstCombine.lib")
#pragma comment(lib, "LLVMInstCombine.lib")
#pragma comment(lib, "LLVMTransformUtils.lib")
//#pragma comment(lib, "LLVMCGData.lib")
#pragma comment(lib, "LLVMBitWriter.lib")
#pragma comment(lib, "LLVMAnalysis.lib")
#pragma comment(lib, "LLVMProfileData.lib")
#pragma comment(lib, "LLVMSymbolize.lib")
#pragma comment(lib, "LLVMDebugInfoGSYM.lib")
#pragma comment(lib, "LLVMDebugInfoDWARF.lib")
//#pragma comment(lib, "LLVMDebugInfoDWARFLowLevel.lib")
#pragma comment(lib, "LLVMDebugInfoPDB.lib")
#pragma comment(lib, "LLVMAsmParser.lib")
#pragma comment(lib, "LLVMBitReader.lib")
#pragma comment(lib, "LLVMRemarks.lib")
#pragma comment(lib, "LLVMBitstreamReader.lib")
#pragma comment(lib, "LLVMTextAPI.lib")
#pragma comment(lib, "LLVMDebugInfoCodeView.lib")
#pragma comment(lib, "LLVMDebugInfoMSF.lib")
#pragma comment(lib, "LLVMDebugInfoBTF.lib")
#pragma comment(lib, "LLVMCodeGenTypes.lib")
#pragma comment(lib, "LLVMMCParser.lib")
#pragma comment(lib, "LLVMMCDisassembler.lib")
#pragma comment(lib, "LLVMMC.lib")
#pragma comment(lib, "LLVMBinaryFormat.lib")
#pragma comment(lib, "LLVMDemangle.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "uuid.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "delayimp.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "comdlg32.lib")

class MyContextSuperClass : public antlr4::ParserRuleContext {
public:
	//int value;

	//AbstractSyntaxTreeNode* m_node;
	ReferencePtr<AbstractSyntaxTreeNode> m_node;
	MyContextSuperClass() = default;
	MyContextSuperClass(ParserRuleContext* parent, size_t invoking_state) : ParserRuleContext{ parent,invoking_state } {}
};

#include "GeneratedCLikeLanguage/GrammarBaseListener.h"
#include "GeneratedCLikeLanguage/GrammarLexer.h"
#include "GeneratedCLikeLanguage/GrammarListener.h"
#include "GeneratedCLikeLanguage/GrammarParser.h"

#include "GeneratedCLikeLanguage/GrammarBaseListener.cpp"
#include "GeneratedCLikeLanguage/GrammarLexer.cpp"
#include "GeneratedCLikeLanguage/GrammarParser.cpp"


#include <Tree/ParseTreeListener.h>
#include <Tree/IterativeParseTreeWalker.h>
#include <tree/ErrorNode.h>
//#include "ASTConverter.cpp"
//#include "IRIncludes.cpp"
#include "Includes.cpp"


void func() {
	// 1. Kontekst i modu³
	llvm::LLVMContext* context = new llvm::LLVMContext{};
	auto module = std::make_unique<llvm::Module>("MyModule", *context);
	llvm::IRBuilder<> builder(*context);

	// 2. Typy: i32 (int32_t)
	llvm::Type* i32Ty = llvm::Type::getInt32Ty(*context);

	// 3. Sygnatura funkcji: i32 add(i32 a, i32 b)
	std::vector<llvm::Type*> paramTypes{ i32Ty, i32Ty };
	llvm::FunctionType* fnType =
		llvm::FunctionType::get(
			/*Result*/ i32Ty,
			/*Params*/ paramTypes,
			/*isVarArg*/ false);

	llvm::Function* addFn = llvm::Function::Create(
		fnType,
		llvm::Function::ExternalLinkage,
		"add",
		module.get()
	);

	// 4. Nazwij argumenty (³adniejsze IR)
	auto argsIter = addFn->arg_begin();
	llvm::Argument* argA = argsIter++;
	argA->setName("a");
	llvm::Argument* argB = argsIter++;
	argB->setName("b");

	// 5. Stwórz blok podstawowy "entry" i ustaw tam buildera
	llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(*context, "entry", addFn);
	builder.SetInsertPoint(entryBB);

	// 6. a + b
	llvm::Value* sum = builder.CreateAdd(argA, argB, "sum");

	// 7. return a+b
	builder.CreateRet(sum);

	// 8. Wypisz ca³y modu³ jako tekstowe LLVM IR
	module->print(llvm::outs(), nullptr);
}

void check_asserts() {

	// wczytanie source file 

	// interpretacja 

	// sprawdzenie interetacji 

	std::string line;
	std::ifstream myfile("auto_assert_1.txt");

	std::string entire_file;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
			entire_file += (line + '\n');
		myfile.close();
	}
	else
		std::cout << "Unable to open file";

	antlr4::ANTLRInputStream stream(entire_file);
	GrammarLexer lexer(&stream);
	antlr4::CommonTokenStream tokens(&lexer);
	GrammarParser parser(&tokens);

	class MyErrorListener : public antlr4::ANTLRErrorListener
	{
	private:
	public:
		bool m_syntax_error = false;
		void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line,
			size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override
		{
			m_syntax_error = true;
			std::cout << "Syntax error: " << line << ": " << charPositionInLine << ": " << msg << std::endl;
		}

		void reportAmbiguity(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex, bool exact,
			const antlrcpp::BitSet& ambigAlts, atn::ATNConfigSet* configs) override
		{
		}

		void reportAttemptingFullContext(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
			const antlrcpp::BitSet& conflictingAlts, atn::ATNConfigSet* configs) override
		{
		}

		void reportContextSensitivity(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
			size_t prediction, atn::ATNConfigSet* configs) override
		{
		}
	};

	MyErrorListener errorListener;
	parser.removeErrorListeners();
	parser.addErrorListener(&errorListener);
	antlr4::tree::ParseTree* tree = parser.prog();

	if (errorListener.m_syntax_error)
		return;

	TreePrinter tree_printer;

	tree_printer.print_tree(static_cast<MyContextSuperClass*>(tree)->m_node, 0);
	ReferencePtr<ProgNode> prog = static_cast<MyContextSuperClass*>(tree)->m_node.cast<ProgNode>();

	class Listener : public antlr4::tree::ParseTreeListener {
	public:
		void enterEveryRule(antlr4::ParserRuleContext* ctx) override {
			auto my_ctx = static_cast<MyContextSuperClass*>(ctx);
			TreeNodeType node_type = my_ctx->m_node->get_type();
			size_t line_number = my_ctx->getStart()->getLine();
			my_ctx->m_node->set_line_number(line_number);
		}
		void exitEveryRule(antlr4::ParserRuleContext* ctx) override {

		};
		void visitErrorNode(antlr4::tree::ErrorNode* ctx) override {

		};
		void visitTerminal(antlr4::tree::TerminalNode* node) override {

		};
	};

	antlr4::tree::IterativeParseTreeWalker walker;
	Listener listener;
	walker.walk(&listener, tree);

	IRErrorCollector error_collector{};
	IRProgram ir_program;
	ir_program.set_checker_listener(&error_collector);
	uint8_t CONST = 1;
	uint8_t VOLATILE = 2;
	ASTConverter converter{ prog, &ir_program, ir_program.get_dtm_manager() };

	class ASTConverterImpl : public ASTConverterListener {
	public:
		void error(const ASTConverterError& err) override { std::cout << "ASTConverterError: Line " << err.get_line_number() << " : " << err.get_msg() << std::endl; }
	};

	ASTConverterImpl ast_conv_impl{};
	converter.convert(&ast_conv_impl);

	ir_program.check_program();
	IRPrinter ir_printer;
	ir_printer.print_errors(error_collector);

	std::vector<IROperand> fn_arguments{};
	IRFunction* fn = ir_program.get_function("main", fn_arguments);
	IRInterpreterForTests* ir_intereter_listener = new IRInterpreterForTests{};
	Interpreter interpreter{ &ir_program,fn,fn_arguments };
	interpreter.set_listener(ir_intereter_listener);

	interpreter.start();

	auto results = ir_intereter_listener->get_results();
	assert(results[0] == true);
	assert(results[1] == true);
	assert(results[0] == true);
	assert(results[3] == true);

	assert(results[4] == false);
	assert(results[5] == false);
}


void check_prints(const std::string& file_name, const std::vector<std::string>& messages) {
	std::string line;
	std::ifstream myfile(file_name);

	std::string entire_file;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
			entire_file += (line + '\n');
		myfile.close();
	}
	else
		std::cout << "Unable to open file";

	antlr4::ANTLRInputStream stream(entire_file);
	GrammarLexer lexer(&stream);
	antlr4::CommonTokenStream tokens(&lexer);
	GrammarParser parser(&tokens);

	class MyErrorListener : public antlr4::ANTLRErrorListener
	{
	public:
		bool m_syntax_error = false;
		void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line,
			size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override
		{
			m_syntax_error = true;
			std::cout << "Syntax error: " << line << ": " << charPositionInLine << ": " << msg << std::endl;
		}

		void reportAmbiguity(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex, bool exact,
			const antlrcpp::BitSet& ambigAlts, atn::ATNConfigSet* configs) override
		{
		}

		void reportAttemptingFullContext(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
			const antlrcpp::BitSet& conflictingAlts, atn::ATNConfigSet* configs) override
		{
		}

		void reportContextSensitivity(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
			size_t prediction, atn::ATNConfigSet* configs) override
		{
		}
	};

	MyErrorListener errorListener;
	parser.removeErrorListeners();
	parser.addErrorListener(&errorListener);

	antlr4::tree::ParseTree* tree = parser.prog();

	TreePrinter tree_printer;

	tree_printer.print_tree(static_cast<MyContextSuperClass*>(tree)->m_node, 0);
	ReferencePtr<ProgNode> prog = static_cast<MyContextSuperClass*>(tree)->m_node.cast<ProgNode>();

	class Listener : public antlr4::tree::ParseTreeListener {
	public:
		void enterEveryRule(antlr4::ParserRuleContext* ctx) override {
			auto my_ctx = static_cast<MyContextSuperClass*>(ctx);
			TreeNodeType node_type = my_ctx->m_node->get_type();
			size_t line_number = my_ctx->getStart()->getLine();
			my_ctx->m_node->set_line_number(line_number);
		}
		void exitEveryRule(antlr4::ParserRuleContext* ctx) override {

		};
		void visitErrorNode(antlr4::tree::ErrorNode* ctx) override {

		};
		void visitTerminal(antlr4::tree::TerminalNode* node) override {

		};
	};

	antlr4::tree::IterativeParseTreeWalker walker;
	Listener listener;
	walker.walk(&listener, tree);

	IRErrorCollector error_collector{};
	IRProgram ir_program;
	ir_program.set_checker_listener(&error_collector);
	uint8_t CONST = 1;
	uint8_t VOLATILE = 2;
	ASTConverter converter{ prog, &ir_program, ir_program.get_dtm_manager() };

	class ASTConverterImpl : public ASTConverterListener {
	public:
		void error(const ASTConverterError& err) override { std::cout << "ASTConverterError: Line " << err.get_line_number() << " : " << err.get_msg() << std::endl; }
	};

	ASTConverterImpl ast_conv_impl{};
	converter.convert(&ast_conv_impl);

	ir_program.check_program();
	IRPrinter ir_printer;
	ir_printer.print_errors(error_collector);

	std::vector<IROperand> fn_arguments{};
	IRFunction* fn = ir_program.get_function("main", fn_arguments);

	IRInterpreterForTests ir_interpreter_listener = IRInterpreterForTests{};
	Interpreter interpreter{ &ir_program,fn,fn_arguments };
	interpreter.set_listener(&ir_interpreter_listener);
	interpreter.start();

	assert(ir_interpreter_listener.get_messages().size() == messages.size());
	auto collected_msgs = ir_interpreter_listener.get_messages();
	for (size_t i = 0; i < collected_msgs.size(); i++)
		assert(collected_msgs[i] == messages[i]);
}

int main() {

	// tests:
	std::string test_folder = "C:\\Users\\zamoj\\OneDrive\\Pulpit\\ProjectKompilator\\SourceTests";
	std::string expected_outputs_folder = "C:\\Users\\zamoj\\OneDrive\\Pulpit\\ProjectKompilator\\SourceTests";

	std::vector<std::string> test_names{
		//simple array tests:
	/*	"all_in_one",
		"arr_1",
		"arr_2",
		"arr_3",
		"arr_4",
		"arr_5",
		"address_of_1",
		"simple_test_1",
		"dereference_1",
		"double_swap_1",
		"pointer_1",
		"pointer_to_a_struct_field",
		"pointer_to_the_element_of_array",
		"read_array_from_pointers",
		"member_pointer",
		"regular_function_call",
		"simple_function_call_1",
		"simple_function_call_2",
		"reference_as_argument_in_function_call_1",
		"reference_to_reference",
		"vectorization_1"
		"print_arr_1"
		"print_pointer",
		"vectorization_2",
		"print_arr_2",
		"print_const_ptr_1",
		"vectorization_2",
		"vectorization_3",
		"vectorization_4",
		"vectorization_5",*/
		"select_6",
		"select_7",
		"select_8"
	};

	Tester compiler_tester(test_folder, expected_outputs_folder);
	compiler_tester.run_all_tests(test_names);

	//std::string file_name = "pointer_to_the_element_of_array.txt";
	//std::string file_name = "pointer_to_the_element_of_array";
	////std::string file_name = "arr_4.txt";
	//std::string line;

	//std::ifstream myfile(file_name);

	//std::string entire_file;
	//if (myfile.is_open())
	//{
	//	while (getline(myfile, line))
	//		entire_file += (line + '\n');
	//	myfile.close();
	//}
	//else
	//	std::cout << "Unable to open file";

	//antlr4::ANTLRInputStream stream(entire_file);
	//GrammarLexer lexer(&stream);
	//antlr4::CommonTokenStream tokens(&lexer);
	//GrammarParser parser(&tokens);

	//class MyErrorListener : public antlr4::ANTLRErrorListener
	//{
	//public:
	//	bool m_syntax_error = false;
	//	void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line,
	//		size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override
	//	{
	//		m_syntax_error = true;
	//		std::cout << "Syntax error: " << line << ": " << charPositionInLine << ": " << msg << std::endl;
	//	}

	//	void reportAmbiguity(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex, bool exact,
	//		const antlrcpp::BitSet& ambigAlts, atn::ATNConfigSet* configs) override
	//	{
	//	}

	//	void reportAttemptingFullContext(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
	//		const antlrcpp::BitSet& conflictingAlts, atn::ATNConfigSet* configs) override
	//	{
	//	}

	//	void reportContextSensitivity(antlr4::Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
	//		size_t prediction, atn::ATNConfigSet* configs) override
	//	{
	//	}
	//};

	//MyErrorListener errorListener;
	//parser.removeErrorListeners();
	//parser.addErrorListener(&errorListener);

	//antlr4::tree::ParseTree* tree = parser.prog();

	//if (errorListener.m_syntax_error) {
	//	return 1;
	//}
	//TreePrinter tree_printer;

	//tree_printer.print_tree(static_cast<MyContextSuperClass*>(tree)->m_node, 0);
	//ReferencePtr<ProgNode> prog = static_cast<MyContextSuperClass*>(tree)->m_node.cast<ProgNode>();

	//class Listener : public antlr4::tree::ParseTreeListener {
	//public:
	//	void enterEveryRule(antlr4::ParserRuleContext* ctx) override {
	//		auto my_ctx = static_cast<MyContextSuperClass*>(ctx);
	//		TreeNodeType node_type = my_ctx->m_node->get_type();
	//		size_t line_number = my_ctx->getStart()->getLine();
	//		my_ctx->m_node->set_line_number(line_number);
	//	}

	//	void exitEveryRule(antlr4::ParserRuleContext* ctx) override {

	//	};
	//	void visitErrorNode(antlr4::tree::ErrorNode* ctx) override {

	//	};
	//	void visitTerminal(antlr4::tree::TerminalNode* node) override {

	//	};
	//};

	//antlr4::tree::IterativeParseTreeWalker walker;
	//Listener listener;
	//walker.walk(&listener, tree);

	//IRErrorCollector error_collector{};
	//IRProgram ir_program;
	//ir_program.set_checker_listener(&error_collector);

	//// tutaj dodaæ 
	////IRDataTypeManager dtm;
	//uint8_t CONST = 1;
	//uint8_t VOLATILE = 2;
	////ir_program.get_dtm_manager();
	//ASTConverter converter{ prog, &ir_program, ir_program.get_dtm_manager() };

	//// TODO add datatype manager do checkera bo trzeba typy dodawac do triple
	//class ASTConverterImpl : public ASTConverterListener {
	//public:
	//	void error(const ASTConverterError& err) override { std::cout << "ASTConverterError: Line " << err.get_line_number() << " : " << err.get_msg() << std::endl; }
	//};

	//ASTConverterImpl ast_conv_impl{};
	//converter.convert(&ast_conv_impl);

	//ir_program.check_program();
	//IRPrinter ir_printer;
	//ir_printer.print_errors(error_collector);
	//ir_printer.print_ir_representation(ir_program);
	//std::cout << std::endl;
	////ir_printer.print_all_data_types_with_size(ir_program);
	//IRToLLVMIRConverter llvm_ir_converter{ &ir_program };
	//// zostaje na potem 
	//// converter do llvm 

	//llvm_ir_converter.convert();
	//std::vector<IROperand> fn_arguments{};
	//IRFunction* fn = ir_program.get_function("main", fn_arguments);

	//class IRInterpreterImpl : public IRInterpreterListener {
	//private:
	//	size_t m_assertions_falied;
	//	size_t m_assertions_succeded;
	//	std::vector<bool> m_results;
	//public:
	//	IRInterpreterImpl() : m_assertions_falied{ 0 }, m_assertions_succeded{ 0 } {}

	//	void assertion_failed(size_t line_number, const std::string& error_msg) {
	//		m_assertions_falied++;
	//		std::string msg = std::format("{}: {}", line_number, error_msg);
	//		std::cout << msg << std::endl;
	//	}

	//	void assertion_succeded() {
	//		m_assertions_succeded++;
	//	}

	//	std::vector<bool>& get_results() {
	//		return m_results;
	//	}

	//	void print_called(const ConstantValue& v) override {
	//		std::string msg = v.to_string();
	//		std::cout << "PRINT: " << msg << std::endl;
	//	}

	//	void function_call_start(const std::vector<ConstantValue>& args, IRFunction* fn) override {
	//		IRPrinter printer;
	//		std::cout << "Function : " << fn->get_name() << std::endl;
	//		for (size_t i = 0; i < args.size(); i++) {
	//			std::cout << args[i] << std::endl;
	//		}
	//	}

	//	void function_call_end(IRFunction* fn, const ConstantValue& val) override {
	//		std::string fn_name = fn ? fn->get_name() : "main";
	//		std::cout << "Got out of the function : " << fn_name << " returned value " << val << std::endl;
	//	}

	//	size_t get_number_of_assertions_falied() { return m_assertions_falied; }

	//};

	//class IRInterpreterImplForTest : public IRInterpreterListener {
	//private:
	//	size_t m_assertions_falied;
	//	size_t m_assertions_succeded;
	//	std::vector<bool> m_assertion_results;
	//public:
	//	IRInterpreterImplForTest() : m_assertions_falied{ 0 }, m_assertions_succeded{ 0 } {}

	//	void assertion_failed(size_t line_number, const std::string& error_msg) override {
	//		m_assertions_falied++;
	//		std::string msg = std::format("{}: {}", line_number, error_msg);
	//		std::cout << msg << std::endl;
	//		m_assertion_results.push_back(false);
	//	}

	//	void assertion_succeded() override {
	//		m_assertions_succeded++;
	//		m_assertion_results.push_back(true);
	//	}

	//	std::vector<bool>& get_results() {
	//		return m_assertion_results;
	//	}

	//	void print_called(const ConstantValue& v) override {
	//		std::cout << "PRINT: " << v << std::endl;
	//	}

	//	size_t get_number_of_assertions_falied() { return m_assertions_falied; }
	//	size_t get_asserts_passed() const { return m_assertions_succeded; }
	//	size_t get_asserts_failed() const { return m_assertions_falied; }
	//};

	//IRInterpreterImpl* ir_intereter_listener = new IRInterpreterImpl{};
	//Interpreter interpreter{ &ir_program,fn,fn_arguments };
	//interpreter.set_listener(ir_intereter_listener);

	//IRPrinter printer;
	//printer.print_ir_representation(ir_program);
	//printer.print_memory_layout(ir_program);

	////interpreter.start();


	return 0;
}

