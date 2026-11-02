#include <iostream>
#include <vector>
#include <array>
#include <variant>
#include <queue>
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
#include <algorithm>
#include <memory>
#include <cmath>
#include <chrono>
#include <queue>
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
// for jit
#include <llvm/ExecutionEngine/Orc/ThreadSafeModule.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/Error.h>

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
#pragma comment(lib, "zstd.lib")
#pragma comment(lib, "zlibd.lib")

class MyContextSuperClass : public antlr4::ParserRuleContext {
public:
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

// for printing 
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/TargetParser/Host.h>

#include "Includes.cpp"

void func() {
	llvm::LLVMContext* context = new llvm::LLVMContext{};
	auto module = std::make_unique<llvm::Module>("MyModule", *context);
	llvm::IRBuilder<> builder(*context);

	llvm::Type* i32Ty = llvm::Type::getInt32Ty(*context);

	std::vector<llvm::Type*> paramTypes{ i32Ty, i32Ty };
	llvm::FunctionType* fnType =
		llvm::FunctionType::get(
			i32Ty,
			paramTypes,
			false
		);

	llvm::Function* addFn = llvm::Function::Create(
		fnType,
		llvm::Function::ExternalLinkage,
		"add",
		module.get()
	);

	auto argsIter = addFn->arg_begin();
	llvm::Argument* argA = argsIter++;
	argA->setName("a");
	llvm::Argument* argB = argsIter++;
	argB->setName("b");

	llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(*context, "entry", addFn);
	builder.SetInsertPoint(entryBB);

	llvm::Value* sum = builder.CreateAdd(argA, argB, "sum");

	builder.CreateRet(sum);

	module->print(llvm::outs(), nullptr);
}

// move to one place
std::string read_entire_file(const fs::path& file_path) {
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
	for (auto& line : lines) {
		read_source_code += line;
	}

	return read_source_code;
}

std::vector<std::string> read_expected_lines(const fs::path& file_path) {
	std::vector<std::string> lines;
	std::ifstream file(file_path);

	std::string line;
	while (std::getline(file, line)) {
		if (line == "#------------------") {
			std::string expected_value;
			while (std::getline(file, expected_value))
			{
				lines.push_back(expected_value);
			}
			break;
		}
	}

	return lines;
}

// dodawanie struktur z poziomu C++
void supernova_jit_tests(const fs::path& source_file) {
	std::string source_code = read_entire_file(source_file);
	SupernovaCompiler supernova{};
	supernova.compile(source_code);

	auto dtm = supernova.m_ir_program.get_dtm_manager();
	using function = int (*)(int);
	std::vector<TypeRef> parameters{ dtm->get_int() };
	auto compiled_function = supernova.get_function<function>("func_4", parameters);
	if (compiled_function) {
		std::cout << "SupernovaCompiler: " << compiled_function(2) << std::endl;
	}
	std::cout << compiled_function(2) << std::endl;
	assert(compiled_function(2)==1);

	// situations when we declare structures in two places should not occur 
	struct A {
		int m_a;
		int m_b;
	};
	A a;
	a.m_a = 10;
	a.m_b = 20;
	uint8_t* p = (uint8_t *) &a;
	uint8_t* member_b = (uint8_t*) &a.m_b;
	int diff = member_b - p;
	std::cout << "Address diff: " << diff << std::endl;

	using function_2 = int (*)(A);
	auto structure_type = dtm->get_struct("A");
	size_t size = structure_type.get_size();
	std::vector<TypeRef> parameters_2{ structure_type };
	auto compiled_function_2 = supernova.get_function<function_2>("func_1", parameters_2);
	if (compiled_function_2) {
		std::cout << "SupernovaCompiler: " << compiled_function_2(a) << std::endl;
	}
	assert(compiled_function_2(a) == 10);

	struct B {
		int m_t[10];
	};
	B b;
	b.m_t[0] = 1;
	b.m_t[1] = 1;
	b.m_t[2] = 1;
	b.m_t[3] = 1;
	b.m_t[4] = 1;
	b.m_t[5] = 1;
	b.m_t[6] = 1;
	b.m_t[7] = 1;
	b.m_t[8] = 1;
	b.m_t[9] = 10;

	int a_v = 10;
	int b_v = 20;
	int c_v = 30;
	using function_4 = int (*)(int,int,int);
	std::vector<TypeRef> parameters4{ dtm->get_int(),dtm->get_int(),dtm->get_int() };
	auto compiled_function_5 = supernova.get_function<function_4>("function_three_arguments",parameters4);
	if (compiled_function_5) {
		std::cout << "SupernovaCompiler: " << compiled_function_5(a_v,b_v,c_v) << std::endl;
	}
	assert(compiled_function_5(a_v,b_v,c_v) == 30);
	
	// reference tests
	// reference1_test
	int x = 1;
	using function_6 = void (*)(int&);
	std::vector<TypeRef> parameters6{ dtm->add_reference(dtm->get_int()) };
	auto compiled_function_6 = supernova.get_function<function_6>("reference1_test", parameters6);

	if (compiled_function_6)
		compiled_function_6(x);
	assert(x == 4);

	// reference2_test
	A item;
	using function_7 = void (*)(A&);
	const TypeRef struct_A = dtm->add_reference(dtm->get_struct("A"));
	std::vector<TypeRef> parameters7{ struct_A };
	auto compiled_function_7 = supernova.get_function<function_7>("reference2_test", parameters7);
	if (compiled_function_7)
		compiled_function_7(item);
	assert(item.m_a == 10 && item.m_b==20);

	// reference3_test
	int val1 = 10;
	int val2 = 20;
	dtm->add_reference(dtm->get_struct("C"));
	using function_8 = void (*)(int&,int&);
	std::vector<TypeRef> parameters8{ dtm->add_reference(dtm->get_int()),dtm->add_reference(dtm->get_int())};
	auto compiled_function_8 = supernova.get_function<function_8>("reference3_test", parameters8);
	if (compiled_function_8)
		compiled_function_8(val1,val2);
	assert(val1==20 && val2 ==10);

	// reference4_test
	struct C {
		int m_tab[3];
	};

	C c;
	c.m_tab[0] = 1;
	c.m_tab[1] = 2;
	c.m_tab[2] = 3;

	using function_9 = void (*)(C&);
	const TypeRef struct_C = dtm->add_reference(dtm->get_struct("C"));
	std::vector<TypeRef> parameters9{ struct_C };
	auto compiled_function_9 = supernova.get_function<function_9>("reference4_test", parameters9);
	if (compiled_function_9)
		compiled_function_9(c);
	assert(c.m_tab[1] == 10);

	// reference5_test
	int test_value = 0;
	using function_10 = void (*)(int&);
	std::vector<TypeRef> parameters10{ dtm->add_reference(dtm->get_int()) };
	auto compiled_function_10 = supernova.get_function<function_10>("reference5_test", parameters10);
	if (compiled_function_10)
		compiled_function_10(test_value);
	assert(test_value == 5);

	A test6_item_a;
	C test6_item_c;
	const TypeRef test_struct_a = dtm->get_struct("A");
	const TypeRef test_struct_c = dtm->get_struct("C");
	using function_11 = void (*)(A&,C&);
	std::vector<TypeRef> parameters11{ dtm->add_reference(test_struct_a) ,dtm->add_reference(test_struct_c)};
	auto compiled_function_11 = supernova.get_function<function_11>("reference6_test", parameters11);
	if (compiled_function_11)
		compiled_function_11(test6_item_a,test6_item_c);
	assert(test6_item_a.m_a ==33 && test6_item_c.m_tab[2]==100);

	A test7_item_a;
	test7_item_a.m_a = 10;
	test7_item_a.m_b = 20;
	const TypeRef test7_struct_a = dtm->get_struct("A");
	using function_12 = void (*)(A&);
	std::vector<TypeRef> parameters12{ dtm->add_reference(test7_struct_a) };
	auto compiled_function_12 = supernova.get_function<function_12>("reference7_test", parameters12);
	if (compiled_function_12)
		compiled_function_12(test7_item_a);
	assert(test7_item_a.m_a==20 && test7_item_a.m_b==10);

	struct D {
		A m_inner;
		int m_element;
	};

	D test8_item_d;
	test8_item_d.m_inner.m_a = 1;
	test8_item_d.m_inner.m_b = 2;
	test8_item_d.m_element = 30;

	const TypeRef test8_struct_d = dtm->get_struct("D");
	using function_13 = void (*)(D&);
	std::vector<TypeRef> parameters13{ dtm->add_reference(test8_struct_d) };
	auto compiled_function_13 = supernova.get_function<function_13>("reference8_test", parameters13);
	if (compiled_function_13)
		compiled_function_13(test8_item_d);
	assert(test8_item_d.m_inner.m_a == 10 && test8_item_d.m_inner.m_b == 20);

	C test9_item_c;
	test9_item_c.m_tab[0] = 1;
	test9_item_c.m_tab[1] = 2;
	test9_item_c.m_tab[2] = 3;

	const TypeRef test9_struct_c = dtm->get_struct("C");
	using function_14 = void (*)(C&);
	std::vector<TypeRef> parameters14{ dtm->add_reference(test9_struct_c) };
	auto compiled_function_14 = supernova.get_function<function_14>("reference9_test", parameters14);
	if (compiled_function_14)
		compiled_function_14(test9_item_c);
	assert(test9_item_c.m_tab[0] == 11 && test9_item_c.m_tab[1] == 12 && test9_item_c.m_tab[2] == 13);

	int inc = 0;
	using function_15 = void (*)(int&);
	std::vector<TypeRef> parameters15{ dtm->add_reference(dtm->get_int())};
	auto compiled_function_15 = supernova.get_function<function_15>("reference10_test", parameters15);
	if (compiled_function_15)
		compiled_function_15(inc);
	assert(inc == 1);

	int dec = 1;
	using function_16 = void (*)(int&);
	std::vector<TypeRef> parameters16{ dtm->add_reference(dtm->get_int())};
	auto compiled_function_16 = supernova.get_function<function_16>("reference11_test", parameters16);
	if (compiled_function_16)
		compiled_function_16(dec);
	assert(dec == 0);

	int passed_value = 0;
	using function_17 = void (*)(int&);
	std::vector<TypeRef> parameters17{ dtm->add_reference(dtm->get_int())};
	auto compiled_function_17 = supernova.get_function<function_17>("reference12_test", parameters17);
	if (compiled_function_17)
		compiled_function_17(passed_value);
	assert(passed_value == 20);

}

void check_asserts() {
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
	parser.m_parser_helper = new ParserHelper{};

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

	IRFunction* global_function = ir_program.get_function("_global_function", {});
	std::vector<IROperand> fn_arguments{};
	Interpreter interpreter{ &ir_program,global_function,fn_arguments };
	interpreter.start(global_function);

	IRFunction* main_fn = ir_program.get_function("main", {});
	IRInterpreterForTests* ir_intereter_listener = new IRInterpreterForTests{};
	interpreter.set_listener(ir_intereter_listener);
	interpreter.start(main_fn);

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
		std::vector<ASTConverterError> m_errors;
		void error(const ASTConverterError& err) override { std::cout << "ASTConverterError: Line " << err.get_line_number() << " : " << err.get_msg() << std::endl; }
	};

	ASTConverterImpl ast_conv_impl{};
	converter.convert(&ast_conv_impl);

	ir_program.check_program();
	IRPrinter ir_printer;
	ir_printer.print_errors(error_collector);

	IRFunction* fn = ir_program.get_function("main", {});

	IRInterpreterForTests ir_interpreter_listener = IRInterpreterForTests{};
	std::vector<IROperand> fn_arguments{};
	Interpreter interpreter{ &ir_program,fn,fn_arguments };
	interpreter.set_listener(&ir_interpreter_listener);
	interpreter.start(fn);

	assert(ir_interpreter_listener.get_messages().size() == messages.size());
	auto collected_msgs = ir_interpreter_listener.get_messages();
	for (size_t i = 0; i < collected_msgs.size(); i++)
		assert(collected_msgs[i] == messages[i]);
}

int fib(int n) {
	if (n <= 1)
		return n;

	return fib(n-2)+fib(n-1);
}

int main(int argc,char* argv[]) {

	const fs::path tests_path = argc > 1 ? fs::path{ argv[1] } : fs::path{ "SourceTests" };

	if (!fs::is_directory(tests_path)) {
		std::cout << "test directory not found: "<< fs::absolute(tests_path) << '\n';
		return 1;
	}

	const std::string test_folder = tests_path.string();
	const std::string expected_outputs_folder = test_folder;

	if (llvm::InitializeNativeTarget() || llvm::InitializeNativeTargetAsmPrinter()) {
		std::cout << "failed to initialize LLVM native target\n";
		return 1;
	}

	//std::vector<std::string> test_names{
	//	"member_1",
	//	"member_access_1",
	//	"implicit_type_widening",
	//	"useless_statements_1",
	//	"implicit_unsigned_widening",
	//	"implicit_assignment_widening",
	//	"implicit_float_to_double",
	//	"implicit_reference_widening",
	//	"add_function_call",
	//	"many_blocks",
	//	"inline_expanding_1",
	//	"inline_function_1",
	//	"inline_recursive_call_1",
	//	"inline_reference_1",
	//	"inline_one_return_1",
	//	"inline_function_2",
	//	"recursion_limit_1",
	//	"unreachable_blk_1",
	//	"bitwise_operations_1",
	//	"constant_replacement_1",
	//	"post_incrementation_1",
	//	"post_incrementation_2",
	//	"pre_incrementation_1",
	//	"constant_conversion_1",
	//	"modulo_division",
	//	"return_promotion_1",
	//	"promotion_core_logic_1",
	//	"return_pointer_1",
	//	"character_1",
	//	"pointer_const_to_non_const_1",
	//	"left_bitwise_shift_1",
	//	"left_bitwise_shift_with_cast_1",
	//	"right_bitwise_shift_1",
	//	"logical_vs_arithmetical_shift_1",
	//	"add_function_call",
	//	"overload_4",
	//	"overloading_1",
	//	"overloading_2",
	//	"overloading_3",
	//	"overloading_single_argument_1",
	//	"overloading_single_argument_2",
	//	"overloading_multiple_arguments_1",
	//	"overloading_multiple_arguments_2",
	//	"string_1",
	//	"string_2",
	//	"string_5",
	//	"string_6",
	//	"string_7",
	//	"string_8",
	//	"array_to_pointer_1",
		//"array_to_pointer_2",
	//	"memcpy_1",
	//	"malloc_1",
	//	"member_point_1",
	//	// -------- works --------------
	//	"print_array_2",
	//	"member_access_jit_1",
	//	"struct_return_1",
	//	"struct_return_2",
	//	"struct_return_3",
	//	"table_return_1",
	//	"table_return_2" // TODO something does not work
	//	"broadcasting_1",
	//	"simple_cast_1",
	//	"array_cast_1",
	//	"array_cast_2"
	//};

	std::vector<std::string> test_names{
		//"member_1",
		//"member_access_1",
		//"implicit_type_widening",
		//"useless_statements_1",
		//"implicit_unsigned_widening",
		//"implicit_assignment_widening",
		//"implicit_float_to_double",
		//"implicit_reference_widening",
		//"add_function_call",
		//"many_blocks",
		//"inline_expanding_1",
		//"inline_function_1",
		//"inline_recursive_call_1",
		//"inline_reference_1",
		//"inline_one_return_1",
		//"inline_function_2",
		//"recursion_limit_1",
		//"unreachable_blk_1",
		//"bitwise_operations_1",
		//"constant_replacement_1",
		//"post_incrementation_1",
		//"post_incrementation_2",
		//"pre_incrementation_1",
		//"constant_conversion_1",
		//"modulo_division",
		//"return_promotion_1",
		//"promotion_core_logic_1",
		//"return_pointer_1",
		//"character_1",
		//"pointer_const_to_non_const_1",
		//"left_bitwise_shift_1",
		//"left_bitwise_shift_with_cast_1",
		//"right_bitwise_shift_1",
		//"logical_vs_arithmetical_shift_1",
		//"add_function_call",
		//"overload_4",
		//"overloading_1",
		//"overloading_2",
		//"overloading_3",
		//"overloading_single_argument_1",
		//"overloading_single_argument_2",
		//"overloading_multiple_arguments_1",
		//"overloading_multiple_arguments_2",
		//"string_1",
		//"string_2",
		//"string_5",
		//"string_6",
		//"string_7",
		//"string_8",
		//"string_10",
		//"string_11",
		//"address_of_3",
		//"print_char_1",
		//"array_to_pointer_1",
		//"array_to_pointer_2",
		//"array_3",
		//"memcpy_1",
		//"malloc_1",
		//"member_point_1",
		//"print_array_2",
		//"member_access_jit_1",
		//"struct_return_1",
		//"struct_return_2",
		//"struct_return_3",
		//"table_return_1",
		//"broadcasting_1",
		//"simple_cast_1",
		//"array_cast_1",
		//"array_cast_2",
		//"table_return_2",
		//// -------- works --------------
		////"domination_frontiers_1"
		//// -------- broadcasting tests--------------
		//"array_operation_1",
		//"select_7",
		//"select_8",
		//"bool_value_1",
		//"bool_value_2",
		//"broadcasting_1",
		//"broadcasting_2",
		//"broadcasting_3",
		//"broadcasting_4", // shorter vector than 7
		//"broadcasting_5", // shorter vector than 9
		//// ----------- select tests ------------------
		//"basic_select_1",
		//"basic_select_1_v2",
		//"basic_select_1_v3",
		//"basic_select_1_v4",
		//"basic_select_4",
		//"basic_select_5",
		//"basic_select_2",
		//"intermediate_select_1",
		//"intermediate_select_2",
		//"advanced_select_1"
		//"jit_compiled_function_1",
		//"jit_compiled_function_with_args_1",
		//"reference_1"
		//"supernova_tests"
		// tablice przez wartość
		//"array_passed_by_value_1",
		//"struct_passed_by_value_1",
		//"reference_2",
		//"reference_3"
		//"reference_4",
		//"reference_5"
	};
	
	std::vector<std::string> jit_test{
		//"dereference_jit_1",
		//"member_access_point_jit_1",
		//"array_jit_1",
		//"simple_jit_1",
		//"simple_jit_2",
		//"simple_jit_3",
		//"simple_jit_4",
		//"simple_jit_5",
		//"simple_jit_6",
		//"external_function_call_1",
		//"external_function_call_2",
		//"external_function_call_3",
		//"mixed_function_call_1",
		//"member_access_point_jit_1",
		//"struct_jit_1",
		//"member_access_jit_1",
		//"union_jit_1"
		//"pointer_to_a_struct_field"
		//"member_access_jit_1"
	};

	std::vector<std::string> test_errors{
		//"implicit_error_1",
		//"implicit_cast_not_allowed_error_1",
		//"implicit_narrowing_error",
		//"implicit_signed_to_unsigned_error",
		//"implicit_double_to_float_error",
		//"implicit_assignment_error",
		//"no_return_1",
		//"return_promotion_error"
		//"pointer_const_to_non_const_2",
		//"pointer_const_to_non_const_3"
		//"invalid_conversion_1"
		//"left_bitwise_shift_cast_error_1"
		//"right_bitwise_shift_cast_error_1"
		//"overloading_single_argument_error_1",
		//"overloading_ambiguous_1",
		//"overloading_no_match_1",
		//"overloading_single_argument_error_2"
		//"string_3",
		//"string_4"
		//"string_9"
		//"potential_error_1"
		//"pointer_to_reference_error_1",
		//"table_of_references_error_1"
	};

	PrintMessageCollector print_message_collector;

	std::cout << "Interpreter Tests: " << std::endl;
	Tester interpreter_tester(
		test_folder,
		expected_outputs_folder,
		TestMode::INTERPRETER_OUTPUT
	);

	std::cout << "JIT Tests: " << std::endl;
	Tester jit_tester(
		test_folder,
		expected_outputs_folder,
		TestMode::JIT_OUTPUT
	);

	interpreter_tester.run_all_tests(test_names, {});
	jit_tester.run_all_tests(test_names, {});

	SupernovaCompiler supernova_compiler;
	supernova_jit_tests(tests_path / "supernova_tests.txt");

	return 0;
}

