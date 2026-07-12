#include <array>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <variant>
#include <vector>

#define ANTLR4CPP_STATIC
#undef ERROR

#include <ParserRuleContext.h>

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"

#include "Includes.h"
#include "ParserContext.h"

#include "GeneratedCLikeLanguage/GrammarBaseListener.h"
#include "GeneratedCLikeLanguage/GrammarLexer.h"
#include "GeneratedCLikeLanguage/GrammarListener.h"
#include "GeneratedCLikeLanguage/GrammarParser.h"

#include "GeneratedCLikeLanguage/GrammarBaseListener.cpp"
#include "GeneratedCLikeLanguage/GrammarLexer.cpp"
#include "GeneratedCLikeLanguage/GrammarParser.cpp"

#include <Tree/IterativeParseTreeWalker.h>
#include <Tree/ParseTreeListener.h>
#include <tree/ErrorNode.h>

#include "Includes.cpp"

