
// Generated from Grammar.g4 by ANTLR 4.13.2


#include "GrammarListener.h"

#include "GrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GrammarParserStaticData final {
  GrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GrammarParserStaticData(const GrammarParserStaticData&) = delete;
  GrammarParserStaticData(GrammarParserStaticData&&) = delete;
  GrammarParserStaticData& operator=(const GrammarParserStaticData&) = delete;
  GrammarParserStaticData& operator=(GrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag grammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GrammarParserStaticData> grammarParserStaticData = nullptr;

void grammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (grammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(grammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GrammarParserStaticData>(
    std::vector<std::string>{
      "while", "doWhile", "for", "initStatments", "if", "prog", "progElement", 
      "function", "functionParameters", "functionParameter", "functionCall", 
      "argumentList", "block", "stmt", "blockDecl", "memberDecl", "declaration", 
      "declarationListItem", "structDecl", "unionDecl", "fundamentalType", 
      "dataType", "typeModifier", "basicType", "return", "sizeOf", "assertCondition", 
      "initializationList", "unnamedInitializationList", "unnamedListElements", 
      "unnamedListElement", "namedInitializationList", "namedListElements", 
      "namedListElement", "expr", "select", "number", "string_literal", 
      "char_literal", "identifier"
    },
    std::vector<std::string>{
      "", "'while'", "'('", "')'", "'do'", "';'", "'for'", "'if'", "'else'", 
      "'inline'", "','", "'{'", "'}'", "'print'", "'print_type'", "'='", 
      "'struct'", "'union'", "'*'", "'['", "']'", "'const'", "'volatile'", 
      "'&'", "'int'", "'int8'", "'int16'", "'int32'", "'int64'", "'uint8'", 
      "'uint16'", "'uint32'", "'uint64'", "'float'", "'double'", "'bool'", 
      "'void'", "'char'", "'return'", "'sizeof'", "'assert'", "'.'", "'->'", 
      "'++'", "'--'", "'-'", "'~'", "'!'", "'/'", "'%'", "'+'", "'>>'", 
      "'<<'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'^'", "'|'", 
      "'&&'", "'||'", "'reinterpret_cast'", "'select'", "", "", "", "", 
      "", "", "", "", "", "'continue'", "'break'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "LINE_COMMENT", 
      "WS", "INT", "FLOAT", "DOUBLE", "BOOL", "BINARY", "OCTAL", "HEX", 
      "CONTINUE", "BREAK", "ID", "STRING_LITERAL", "CHAR_LITERAL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,78,650,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,0,1,0,1,0,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,114,8,3,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,3,4,123,8,4,1,4,1,4,1,5,5,5,128,8,5,10,5,12,5,131,9,5,1,5,1,5,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,150,8,6,
  	1,7,3,7,153,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,5,8,166,8,
  	8,10,8,12,8,169,9,8,3,8,171,8,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	3,10,182,8,10,1,10,1,10,1,10,1,11,1,11,1,11,5,11,190,8,11,10,11,12,11,
  	193,9,11,1,11,1,11,1,12,1,12,5,12,199,8,12,10,12,12,12,202,9,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,257,8,13,1,14,
  	1,14,5,14,261,8,14,10,14,12,14,264,9,14,1,14,1,14,1,14,1,15,1,15,1,15,
  	1,15,1,15,1,16,1,16,1,16,1,16,5,16,278,8,16,10,16,12,16,281,9,16,1,16,
  	1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,3,17,300,8,17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,
  	1,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,318,8,20,1,21,1,21,5,21,322,8,
  	21,10,21,12,21,325,9,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,3,22,342,8,22,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,372,8,23,1,24,1,24,
  	3,24,376,8,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,3,27,399,8,27,1,28,
  	1,28,3,28,403,8,28,1,28,1,28,1,28,1,29,1,29,1,29,5,29,411,8,29,10,29,
  	12,29,414,9,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,
  	3,30,427,8,30,1,31,1,31,1,31,1,31,1,31,1,32,1,32,1,32,5,32,437,8,32,10,
  	32,12,32,440,9,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,
  	33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,462,8,33,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,3,34,537,8,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,5,34,616,8,
  	34,10,34,12,34,619,9,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,3,36,639,8,36,1,37,1,37,
  	1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,39,0,1,68,40,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,
  	62,64,66,68,70,72,74,76,78,0,5,2,0,18,18,48,49,2,0,45,45,50,50,1,0,51,
  	52,1,0,53,58,2,0,67,67,71,73,701,0,80,1,0,0,0,2,87,1,0,0,0,4,96,1,0,0,
  	0,6,113,1,0,0,0,8,115,1,0,0,0,10,129,1,0,0,0,12,149,1,0,0,0,14,152,1,
  	0,0,0,16,170,1,0,0,0,18,174,1,0,0,0,20,178,1,0,0,0,22,186,1,0,0,0,24,
  	196,1,0,0,0,26,256,1,0,0,0,28,258,1,0,0,0,30,268,1,0,0,0,32,273,1,0,0,
  	0,34,299,1,0,0,0,36,301,1,0,0,0,38,306,1,0,0,0,40,317,1,0,0,0,42,319,
  	1,0,0,0,44,341,1,0,0,0,46,371,1,0,0,0,48,373,1,0,0,0,50,380,1,0,0,0,52,
  	386,1,0,0,0,54,398,1,0,0,0,56,400,1,0,0,0,58,407,1,0,0,0,60,426,1,0,0,
  	0,62,428,1,0,0,0,64,433,1,0,0,0,66,461,1,0,0,0,68,536,1,0,0,0,70,620,
  	1,0,0,0,72,638,1,0,0,0,74,640,1,0,0,0,76,643,1,0,0,0,78,646,1,0,0,0,80,
  	81,5,1,0,0,81,82,5,2,0,0,82,83,3,68,34,0,83,84,5,3,0,0,84,85,3,26,13,
  	0,85,86,6,0,-1,0,86,1,1,0,0,0,87,88,5,4,0,0,88,89,3,26,13,0,89,90,5,1,
  	0,0,90,91,5,2,0,0,91,92,3,68,34,0,92,93,5,3,0,0,93,94,5,5,0,0,94,95,6,
  	1,-1,0,95,3,1,0,0,0,96,97,5,6,0,0,97,98,5,2,0,0,98,99,3,6,3,0,99,100,
  	5,5,0,0,100,101,3,68,34,0,101,102,5,5,0,0,102,103,3,68,34,0,103,104,5,
  	3,0,0,104,105,3,26,13,0,105,106,6,2,-1,0,106,5,1,0,0,0,107,108,3,32,16,
  	0,108,109,6,3,-1,0,109,114,1,0,0,0,110,111,3,68,34,0,111,112,6,3,-1,0,
  	112,114,1,0,0,0,113,107,1,0,0,0,113,110,1,0,0,0,114,7,1,0,0,0,115,116,
  	5,7,0,0,116,117,5,2,0,0,117,118,3,68,34,0,118,119,5,3,0,0,119,122,3,26,
  	13,0,120,121,5,8,0,0,121,123,3,26,13,0,122,120,1,0,0,0,122,123,1,0,0,
  	0,123,124,1,0,0,0,124,125,6,4,-1,0,125,9,1,0,0,0,126,128,3,12,6,0,127,
  	126,1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,132,1,
  	0,0,0,131,129,1,0,0,0,132,133,6,5,-1,0,133,11,1,0,0,0,134,135,3,14,7,
  	0,135,136,6,6,-1,0,136,150,1,0,0,0,137,138,3,32,16,0,138,139,5,5,0,0,
  	139,140,6,6,-1,0,140,150,1,0,0,0,141,142,3,38,19,0,142,143,5,5,0,0,143,
  	144,6,6,-1,0,144,150,1,0,0,0,145,146,3,36,18,0,146,147,5,5,0,0,147,148,
  	6,6,-1,0,148,150,1,0,0,0,149,134,1,0,0,0,149,137,1,0,0,0,149,141,1,0,
  	0,0,149,145,1,0,0,0,150,13,1,0,0,0,151,153,5,9,0,0,152,151,1,0,0,0,152,
  	153,1,0,0,0,153,154,1,0,0,0,154,155,3,42,21,0,155,156,3,78,39,0,156,157,
  	5,2,0,0,157,158,3,16,8,0,158,159,5,3,0,0,159,160,3,24,12,0,160,161,6,
  	7,-1,0,161,15,1,0,0,0,162,167,3,18,9,0,163,164,5,10,0,0,164,166,3,18,
  	9,0,165,163,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,
  	171,1,0,0,0,169,167,1,0,0,0,170,162,1,0,0,0,170,171,1,0,0,0,171,172,1,
  	0,0,0,172,173,6,8,-1,0,173,17,1,0,0,0,174,175,3,42,21,0,175,176,3,78,
  	39,0,176,177,6,9,-1,0,177,19,1,0,0,0,178,179,3,78,39,0,179,181,5,2,0,
  	0,180,182,3,22,11,0,181,180,1,0,0,0,181,182,1,0,0,0,182,183,1,0,0,0,183,
  	184,5,3,0,0,184,185,6,10,-1,0,185,21,1,0,0,0,186,191,3,68,34,0,187,188,
  	5,10,0,0,188,190,3,68,34,0,189,187,1,0,0,0,190,193,1,0,0,0,191,189,1,
  	0,0,0,191,192,1,0,0,0,192,194,1,0,0,0,193,191,1,0,0,0,194,195,6,11,-1,
  	0,195,23,1,0,0,0,196,200,5,11,0,0,197,199,3,26,13,0,198,197,1,0,0,0,199,
  	202,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,203,1,0,0,0,202,200,1,
  	0,0,0,203,204,5,12,0,0,204,205,6,12,-1,0,205,25,1,0,0,0,206,207,3,32,
  	16,0,207,208,5,5,0,0,208,209,6,13,-1,0,209,257,1,0,0,0,210,211,3,20,10,
  	0,211,212,5,5,0,0,212,213,6,13,-1,0,213,257,1,0,0,0,214,215,3,48,24,0,
  	215,216,6,13,-1,0,216,257,1,0,0,0,217,218,3,8,4,0,218,219,6,13,-1,0,219,
  	257,1,0,0,0,220,221,3,0,0,0,221,222,6,13,-1,0,222,257,1,0,0,0,223,224,
  	3,4,2,0,224,225,6,13,-1,0,225,257,1,0,0,0,226,227,3,2,1,0,227,228,6,13,
  	-1,0,228,257,1,0,0,0,229,230,3,24,12,0,230,231,6,13,-1,0,231,257,1,0,
  	0,0,232,233,5,75,0,0,233,234,5,5,0,0,234,257,6,13,-1,0,235,236,5,74,0,
  	0,236,237,5,5,0,0,237,257,6,13,-1,0,238,239,5,13,0,0,239,240,5,2,0,0,
  	240,241,3,68,34,0,241,242,5,3,0,0,242,243,5,5,0,0,243,244,6,13,-1,0,244,
  	257,1,0,0,0,245,246,5,14,0,0,246,247,5,2,0,0,247,248,3,68,34,0,248,249,
  	5,3,0,0,249,250,5,5,0,0,250,251,6,13,-1,0,251,257,1,0,0,0,252,253,3,68,
  	34,0,253,254,5,5,0,0,254,255,6,13,-1,0,255,257,1,0,0,0,256,206,1,0,0,
  	0,256,210,1,0,0,0,256,214,1,0,0,0,256,217,1,0,0,0,256,220,1,0,0,0,256,
  	223,1,0,0,0,256,226,1,0,0,0,256,229,1,0,0,0,256,232,1,0,0,0,256,235,1,
  	0,0,0,256,238,1,0,0,0,256,245,1,0,0,0,256,252,1,0,0,0,257,27,1,0,0,0,
  	258,262,5,11,0,0,259,261,3,30,15,0,260,259,1,0,0,0,261,264,1,0,0,0,262,
  	260,1,0,0,0,262,263,1,0,0,0,263,265,1,0,0,0,264,262,1,0,0,0,265,266,5,
  	12,0,0,266,267,6,14,-1,0,267,29,1,0,0,0,268,269,3,42,21,0,269,270,3,78,
  	39,0,270,271,5,5,0,0,271,272,6,15,-1,0,272,31,1,0,0,0,273,274,3,42,21,
  	0,274,279,3,34,17,0,275,276,5,10,0,0,276,278,3,34,17,0,277,275,1,0,0,
  	0,278,281,1,0,0,0,279,277,1,0,0,0,279,280,1,0,0,0,280,282,1,0,0,0,281,
  	279,1,0,0,0,282,283,6,16,-1,0,283,33,1,0,0,0,284,285,3,78,39,0,285,286,
  	6,17,-1,0,286,300,1,0,0,0,287,288,3,78,39,0,288,289,5,15,0,0,289,290,
  	3,68,34,0,290,291,1,0,0,0,291,292,6,17,-1,0,292,300,1,0,0,0,293,294,3,
  	78,39,0,294,295,5,15,0,0,295,296,3,54,27,0,296,297,1,0,0,0,297,298,6,
  	17,-1,0,298,300,1,0,0,0,299,284,1,0,0,0,299,287,1,0,0,0,299,293,1,0,0,
  	0,300,35,1,0,0,0,301,302,5,16,0,0,302,303,3,78,39,0,303,304,3,28,14,0,
  	304,305,6,18,-1,0,305,37,1,0,0,0,306,307,5,17,0,0,307,308,3,78,39,0,308,
  	309,3,28,14,0,309,310,6,19,-1,0,310,39,1,0,0,0,311,312,3,46,23,0,312,
  	313,6,20,-1,0,313,318,1,0,0,0,314,315,3,78,39,0,315,316,6,20,-1,0,316,
  	318,1,0,0,0,317,311,1,0,0,0,317,314,1,0,0,0,318,41,1,0,0,0,319,323,3,
  	40,20,0,320,322,3,44,22,0,321,320,1,0,0,0,322,325,1,0,0,0,323,321,1,0,
  	0,0,323,324,1,0,0,0,324,326,1,0,0,0,325,323,1,0,0,0,326,327,6,21,-1,0,
  	327,43,1,0,0,0,328,329,5,18,0,0,329,342,6,22,-1,0,330,331,5,19,0,0,331,
  	332,3,68,34,0,332,333,5,20,0,0,333,334,6,22,-1,0,334,342,1,0,0,0,335,
  	336,5,21,0,0,336,342,6,22,-1,0,337,338,5,22,0,0,338,342,6,22,-1,0,339,
  	340,5,23,0,0,340,342,6,22,-1,0,341,328,1,0,0,0,341,330,1,0,0,0,341,335,
  	1,0,0,0,341,337,1,0,0,0,341,339,1,0,0,0,342,45,1,0,0,0,343,344,5,24,0,
  	0,344,372,6,23,-1,0,345,346,5,25,0,0,346,372,6,23,-1,0,347,348,5,26,0,
  	0,348,372,6,23,-1,0,349,350,5,27,0,0,350,372,6,23,-1,0,351,352,5,28,0,
  	0,352,372,6,23,-1,0,353,354,5,29,0,0,354,372,6,23,-1,0,355,356,5,30,0,
  	0,356,372,6,23,-1,0,357,358,5,31,0,0,358,372,6,23,-1,0,359,360,5,32,0,
  	0,360,372,6,23,-1,0,361,362,5,33,0,0,362,372,6,23,-1,0,363,364,5,34,0,
  	0,364,372,6,23,-1,0,365,366,5,35,0,0,366,372,6,23,-1,0,367,368,5,36,0,
  	0,368,372,6,23,-1,0,369,370,5,37,0,0,370,372,6,23,-1,0,371,343,1,0,0,
  	0,371,345,1,0,0,0,371,347,1,0,0,0,371,349,1,0,0,0,371,351,1,0,0,0,371,
  	353,1,0,0,0,371,355,1,0,0,0,371,357,1,0,0,0,371,359,1,0,0,0,371,361,1,
  	0,0,0,371,363,1,0,0,0,371,365,1,0,0,0,371,367,1,0,0,0,371,369,1,0,0,0,
  	372,47,1,0,0,0,373,375,5,38,0,0,374,376,3,68,34,0,375,374,1,0,0,0,375,
  	376,1,0,0,0,376,377,1,0,0,0,377,378,5,5,0,0,378,379,6,24,-1,0,379,49,
  	1,0,0,0,380,381,5,39,0,0,381,382,5,2,0,0,382,383,3,42,21,0,383,384,5,
  	3,0,0,384,385,6,25,-1,0,385,51,1,0,0,0,386,387,5,40,0,0,387,388,5,2,0,
  	0,388,389,3,68,34,0,389,390,5,3,0,0,390,391,6,26,-1,0,391,53,1,0,0,0,
  	392,393,3,56,28,0,393,394,6,27,-1,0,394,399,1,0,0,0,395,396,3,62,31,0,
  	396,397,6,27,-1,0,397,399,1,0,0,0,398,392,1,0,0,0,398,395,1,0,0,0,399,
  	55,1,0,0,0,400,402,5,11,0,0,401,403,3,58,29,0,402,401,1,0,0,0,402,403,
  	1,0,0,0,403,404,1,0,0,0,404,405,5,12,0,0,405,406,6,28,-1,0,406,57,1,0,
  	0,0,407,412,3,60,30,0,408,409,5,10,0,0,409,411,3,60,30,0,410,408,1,0,
  	0,0,411,414,1,0,0,0,412,410,1,0,0,0,412,413,1,0,0,0,413,415,1,0,0,0,414,
  	412,1,0,0,0,415,416,6,29,-1,0,416,59,1,0,0,0,417,418,3,68,34,0,418,419,
  	6,30,-1,0,419,427,1,0,0,0,420,421,3,62,31,0,421,422,6,30,-1,0,422,427,
  	1,0,0,0,423,424,3,56,28,0,424,425,6,30,-1,0,425,427,1,0,0,0,426,417,1,
  	0,0,0,426,420,1,0,0,0,426,423,1,0,0,0,427,61,1,0,0,0,428,429,5,11,0,0,
  	429,430,3,64,32,0,430,431,5,12,0,0,431,432,6,31,-1,0,432,63,1,0,0,0,433,
  	438,3,66,33,0,434,435,5,10,0,0,435,437,3,66,33,0,436,434,1,0,0,0,437,
  	440,1,0,0,0,438,436,1,0,0,0,438,439,1,0,0,0,439,441,1,0,0,0,440,438,1,
  	0,0,0,441,442,6,32,-1,0,442,65,1,0,0,0,443,444,5,41,0,0,444,445,3,78,
  	39,0,445,446,5,15,0,0,446,447,3,68,34,0,447,448,6,33,-1,0,448,462,1,0,
  	0,0,449,450,5,41,0,0,450,451,3,78,39,0,451,452,5,15,0,0,452,453,3,62,
  	31,0,453,454,6,33,-1,0,454,462,1,0,0,0,455,456,5,41,0,0,456,457,3,78,
  	39,0,457,458,5,15,0,0,458,459,3,56,28,0,459,460,6,33,-1,0,460,462,1,0,
  	0,0,461,443,1,0,0,0,461,449,1,0,0,0,461,455,1,0,0,0,462,67,1,0,0,0,463,
  	464,6,34,-1,0,464,465,5,2,0,0,465,466,3,42,21,0,466,467,5,3,0,0,467,468,
  	3,68,34,34,468,469,6,34,-1,0,469,537,1,0,0,0,470,471,5,43,0,0,471,472,
  	3,68,34,29,472,473,6,34,-1,0,473,537,1,0,0,0,474,475,5,44,0,0,475,476,
  	3,68,34,27,476,477,6,34,-1,0,477,537,1,0,0,0,478,479,5,45,0,0,479,480,
  	3,68,34,26,480,481,6,34,-1,0,481,537,1,0,0,0,482,483,5,46,0,0,483,484,
  	3,68,34,25,484,485,6,34,-1,0,485,537,1,0,0,0,486,487,5,47,0,0,487,488,
  	3,68,34,24,488,489,6,34,-1,0,489,537,1,0,0,0,490,491,5,18,0,0,491,492,
  	3,68,34,23,492,493,6,34,-1,0,493,537,1,0,0,0,494,495,5,23,0,0,495,496,
  	3,68,34,22,496,497,6,34,-1,0,497,537,1,0,0,0,498,499,3,20,10,0,499,500,
  	6,34,-1,0,500,537,1,0,0,0,501,502,3,78,39,0,502,503,6,34,-1,0,503,537,
  	1,0,0,0,504,505,3,72,36,0,505,506,6,34,-1,0,506,537,1,0,0,0,507,508,5,
  	2,0,0,508,509,3,68,34,0,509,510,5,3,0,0,510,511,6,34,-1,0,511,537,1,0,
  	0,0,512,513,5,63,0,0,513,514,5,55,0,0,514,515,3,42,21,0,515,516,5,53,
  	0,0,516,517,5,2,0,0,517,518,3,68,34,0,518,519,5,3,0,0,519,520,6,34,-1,
  	0,520,537,1,0,0,0,521,522,3,50,25,0,522,523,6,34,-1,0,523,537,1,0,0,0,
  	524,525,3,52,26,0,525,526,6,34,-1,0,526,537,1,0,0,0,527,528,3,70,35,0,
  	528,529,6,34,-1,0,529,537,1,0,0,0,530,531,3,74,37,0,531,532,6,34,-1,0,
  	532,537,1,0,0,0,533,534,3,76,38,0,534,535,6,34,-1,0,535,537,1,0,0,0,536,
  	463,1,0,0,0,536,470,1,0,0,0,536,474,1,0,0,0,536,478,1,0,0,0,536,482,1,
  	0,0,0,536,486,1,0,0,0,536,490,1,0,0,0,536,494,1,0,0,0,536,498,1,0,0,0,
  	536,501,1,0,0,0,536,504,1,0,0,0,536,507,1,0,0,0,536,512,1,0,0,0,536,521,
  	1,0,0,0,536,524,1,0,0,0,536,527,1,0,0,0,536,530,1,0,0,0,536,533,1,0,0,
  	0,537,617,1,0,0,0,538,539,10,21,0,0,539,540,7,0,0,0,540,541,3,68,34,22,
  	541,542,6,34,-1,0,542,616,1,0,0,0,543,544,10,20,0,0,544,545,7,1,0,0,545,
  	546,3,68,34,21,546,547,6,34,-1,0,547,616,1,0,0,0,548,549,10,19,0,0,549,
  	550,7,2,0,0,550,551,3,68,34,20,551,552,6,34,-1,0,552,616,1,0,0,0,553,
  	554,10,18,0,0,554,555,7,3,0,0,555,556,3,68,34,19,556,557,6,34,-1,0,557,
  	616,1,0,0,0,558,559,10,17,0,0,559,560,5,23,0,0,560,561,3,68,34,18,561,
  	562,6,34,-1,0,562,616,1,0,0,0,563,564,10,16,0,0,564,565,5,59,0,0,565,
  	566,3,68,34,17,566,567,6,34,-1,0,567,616,1,0,0,0,568,569,10,15,0,0,569,
  	570,5,60,0,0,570,571,3,68,34,16,571,572,6,34,-1,0,572,616,1,0,0,0,573,
  	574,10,14,0,0,574,575,5,61,0,0,575,576,3,68,34,15,576,577,6,34,-1,0,577,
  	616,1,0,0,0,578,579,10,13,0,0,579,580,5,62,0,0,580,581,3,68,34,14,581,
  	582,6,34,-1,0,582,616,1,0,0,0,583,584,10,10,0,0,584,585,5,15,0,0,585,
  	586,3,68,34,11,586,587,6,34,-1,0,587,616,1,0,0,0,588,589,10,33,0,0,589,
  	590,5,19,0,0,590,591,3,68,34,0,591,592,5,20,0,0,592,593,6,34,-1,0,593,
  	616,1,0,0,0,594,595,10,32,0,0,595,596,5,41,0,0,596,597,3,78,39,0,597,
  	598,6,34,-1,0,598,616,1,0,0,0,599,600,10,31,0,0,600,601,5,42,0,0,601,
  	602,3,78,39,0,602,603,6,34,-1,0,603,616,1,0,0,0,604,605,10,30,0,0,605,
  	606,5,43,0,0,606,616,6,34,-1,0,607,608,10,28,0,0,608,609,5,44,0,0,609,
  	616,6,34,-1,0,610,611,10,9,0,0,611,612,5,15,0,0,612,613,3,54,27,0,613,
  	614,6,34,-1,0,614,616,1,0,0,0,615,538,1,0,0,0,615,543,1,0,0,0,615,548,
  	1,0,0,0,615,553,1,0,0,0,615,558,1,0,0,0,615,563,1,0,0,0,615,568,1,0,0,
  	0,615,573,1,0,0,0,615,578,1,0,0,0,615,583,1,0,0,0,615,588,1,0,0,0,615,
  	594,1,0,0,0,615,599,1,0,0,0,615,604,1,0,0,0,615,607,1,0,0,0,615,610,1,
  	0,0,0,616,619,1,0,0,0,617,615,1,0,0,0,617,618,1,0,0,0,618,69,1,0,0,0,
  	619,617,1,0,0,0,620,621,5,64,0,0,621,622,5,2,0,0,622,623,3,68,34,0,623,
  	624,5,10,0,0,624,625,3,68,34,0,625,626,5,10,0,0,626,627,3,68,34,0,627,
  	628,5,3,0,0,628,629,6,35,-1,0,629,71,1,0,0,0,630,631,7,4,0,0,631,639,
  	6,36,-1,0,632,633,5,68,0,0,633,639,6,36,-1,0,634,635,5,69,0,0,635,639,
  	6,36,-1,0,636,637,5,70,0,0,637,639,6,36,-1,0,638,630,1,0,0,0,638,632,
  	1,0,0,0,638,634,1,0,0,0,638,636,1,0,0,0,639,73,1,0,0,0,640,641,5,77,0,
  	0,641,642,6,37,-1,0,642,75,1,0,0,0,643,644,5,78,0,0,644,645,6,38,-1,0,
  	645,77,1,0,0,0,646,647,5,76,0,0,647,648,6,39,-1,0,648,79,1,0,0,0,29,113,
  	122,129,149,152,167,170,181,191,200,256,262,279,299,317,323,341,371,375,
  	398,402,412,426,438,461,536,615,617,638
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  grammarParserStaticData = std::move(staticData);
}

}

GrammarParser::GrammarParser(TokenStream *input) : GrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

GrammarParser::GrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  GrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *grammarParserStaticData->atn, grammarParserStaticData->decisionToDFA, grammarParserStaticData->sharedContextCache, options);
}

GrammarParser::~GrammarParser() {
  delete _interpreter;
}

const atn::ATN& GrammarParser::getATN() const {
  return *grammarParserStaticData->atn;
}

std::string GrammarParser::getGrammarFileName() const {
  return "Grammar.g4";
}

const std::vector<std::string>& GrammarParser::getRuleNames() const {
  return grammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& GrammarParser::getVocabulary() const {
  return grammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GrammarParser::getSerializedATN() const {
  return grammarParserStaticData->serializedATN;
}


//----------------- WhileContext ------------------------------------------------------------------

GrammarParser::WhileContext::WhileContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::WhileContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

GrammarParser::StmtContext* GrammarParser::WhileContext::stmt() {
  return getRuleContext<GrammarParser::StmtContext>(0);
}


size_t GrammarParser::WhileContext::getRuleIndex() const {
  return GrammarParser::RuleWhile;
}

void GrammarParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}

void GrammarParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}

GrammarParser::WhileContext* GrammarParser::while_() {
  WhileContext *_localctx = _tracker.createInstance<WhileContext>(_ctx, getState());
  enterRule(_localctx, 0, GrammarParser::RuleWhile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(GrammarParser::T__0);
    setState(81);
    match(GrammarParser::T__1);
    setState(82);
    antlrcpp::downCast<WhileContext *>(_localctx)->exprContext = expr(0);
    setState(83);
    match(GrammarParser::T__2);
    setState(84);
    antlrcpp::downCast<WhileContext *>(_localctx)->stmtContext = stmt();

    			_localctx->m_node = new WhileNode{antlrcpp::downCast<WhileContext *>(_localctx)->exprContext->m_node,antlrcpp::downCast<WhileContext *>(_localctx)->stmtContext->m_node};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoWhileContext ------------------------------------------------------------------

GrammarParser::DoWhileContext::DoWhileContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::StmtContext* GrammarParser::DoWhileContext::stmt() {
  return getRuleContext<GrammarParser::StmtContext>(0);
}

GrammarParser::ExprContext* GrammarParser::DoWhileContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::DoWhileContext::getRuleIndex() const {
  return GrammarParser::RuleDoWhile;
}

void GrammarParser::DoWhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoWhile(this);
}

void GrammarParser::DoWhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoWhile(this);
}

GrammarParser::DoWhileContext* GrammarParser::doWhile() {
  DoWhileContext *_localctx = _tracker.createInstance<DoWhileContext>(_ctx, getState());
  enterRule(_localctx, 2, GrammarParser::RuleDoWhile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(GrammarParser::T__3);
    setState(88);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->stmtContext = stmt();
    setState(89);
    match(GrammarParser::T__0);
    setState(90);
    match(GrammarParser::T__1);
    setState(91);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->exprContext = expr(0);
    setState(92);
    match(GrammarParser::T__2);
    setState(93);
    match(GrammarParser::T__4);

    			_localctx->m_node = new DoWhileNode{antlrcpp::downCast<DoWhileContext *>(_localctx)->exprContext->m_node,antlrcpp::downCast<DoWhileContext *>(_localctx)->stmtContext->m_node};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForContext ------------------------------------------------------------------

GrammarParser::ForContext::ForContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::InitStatmentsContext* GrammarParser::ForContext::initStatments() {
  return getRuleContext<GrammarParser::InitStatmentsContext>(0);
}

std::vector<GrammarParser::ExprContext *> GrammarParser::ForContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::ForContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}

GrammarParser::StmtContext* GrammarParser::ForContext::stmt() {
  return getRuleContext<GrammarParser::StmtContext>(0);
}


size_t GrammarParser::ForContext::getRuleIndex() const {
  return GrammarParser::RuleFor;
}

void GrammarParser::ForContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor(this);
}

void GrammarParser::ForContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor(this);
}

GrammarParser::ForContext* GrammarParser::for_() {
  ForContext *_localctx = _tracker.createInstance<ForContext>(_ctx, getState());
  enterRule(_localctx, 4, GrammarParser::RuleFor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(GrammarParser::T__5);
    setState(97);
    match(GrammarParser::T__1);
    setState(98);
    antlrcpp::downCast<ForContext *>(_localctx)->initStatmentsContext = initStatments();
    setState(99);
    match(GrammarParser::T__4);

    setState(100);
    antlrcpp::downCast<ForContext *>(_localctx)->condition = antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(101);
    match(GrammarParser::T__4);
    setState(102);
    antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(103);
    match(GrammarParser::T__2);
    setState(104);
    antlrcpp::downCast<ForContext *>(_localctx)->stmtContext = stmt();

    			ReferencePtr<AbstractSyntaxTreeNode> declarations_or_exprs = antlrcpp::downCast<ForContext *>(_localctx)->initStatmentsContext->m_node;
    			ReferencePtr<AbstractSyntaxTreeNode> cond = antlrcpp::downCast<ForContext *>(_localctx)->condition->m_node;
    			ReferencePtr<AbstractSyntaxTreeNode> expr = antlrcpp::downCast<ForContext *>(_localctx)->exprContext->m_node;
    			ReferencePtr<AbstractSyntaxTreeNode> stmt = antlrcpp::downCast<ForContext *>(_localctx)->stmtContext->m_node;

    			_localctx->m_node = new ForNode{declarations_or_exprs,cond,expr,stmt};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitStatmentsContext ------------------------------------------------------------------

GrammarParser::InitStatmentsContext::InitStatmentsContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DeclarationContext* GrammarParser::InitStatmentsContext::declaration() {
  return getRuleContext<GrammarParser::DeclarationContext>(0);
}

GrammarParser::ExprContext* GrammarParser::InitStatmentsContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::InitStatmentsContext::getRuleIndex() const {
  return GrammarParser::RuleInitStatments;
}

void GrammarParser::InitStatmentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitStatments(this);
}

void GrammarParser::InitStatmentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitStatments(this);
}

GrammarParser::InitStatmentsContext* GrammarParser::initStatments() {
  InitStatmentsContext *_localctx = _tracker.createInstance<InitStatmentsContext>(_ctx, getState());
  enterRule(_localctx, 6, GrammarParser::RuleInitStatments);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext = declaration();

      				_localctx->m_node = antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(110);
      antlrcpp::downCast<InitStatmentsContext *>(_localctx)->exprContext = expr(0);

      				_localctx->m_node = antlrcpp::downCast<InitStatmentsContext *>(_localctx)->exprContext->m_node;
      			
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfContext ------------------------------------------------------------------

GrammarParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::IfContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

std::vector<GrammarParser::StmtContext *> GrammarParser::IfContext::stmt() {
  return getRuleContexts<GrammarParser::StmtContext>();
}

GrammarParser::StmtContext* GrammarParser::IfContext::stmt(size_t i) {
  return getRuleContext<GrammarParser::StmtContext>(i);
}


size_t GrammarParser::IfContext::getRuleIndex() const {
  return GrammarParser::RuleIf;
}

void GrammarParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}

void GrammarParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}

GrammarParser::IfContext* GrammarParser::if_() {
  IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
  enterRule(_localctx, 8, GrammarParser::RuleIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(GrammarParser::T__6);
    setState(116);
    match(GrammarParser::T__1);
    setState(117);
    antlrcpp::downCast<IfContext *>(_localctx)->exprContext = expr(0);
    setState(118);
    match(GrammarParser::T__2);
    setState(119);
    antlrcpp::downCast<IfContext *>(_localctx)->stmt_1 = stmt();
    setState(122);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(120);
      match(GrammarParser::T__7);
      setState(121);
      antlrcpp::downCast<IfContext *>(_localctx)->stmt_2 = stmt();
      break;
    }

    default:
      break;
    }

    			_localctx->m_node = new IfNode{antlrcpp::downCast<IfContext *>(_localctx)->exprContext->m_node,antlrcpp::downCast<IfContext *>(_localctx)->stmt_1->m_node,antlrcpp::downCast<IfContext *>(_localctx)->stmt_2!=nullptr ? antlrcpp::downCast<IfContext *>(_localctx)->stmt_2->m_node : nullptr };
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

GrammarParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::ProgElementContext *> GrammarParser::ProgContext::progElement() {
  return getRuleContexts<GrammarParser::ProgElementContext>();
}

GrammarParser::ProgElementContext* GrammarParser::ProgContext::progElement(size_t i) {
  return getRuleContext<GrammarParser::ProgElementContext>(i);
}


size_t GrammarParser::ProgContext::getRuleIndex() const {
  return GrammarParser::RuleProg;
}

void GrammarParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void GrammarParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

GrammarParser::ProgContext* GrammarParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 10, GrammarParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 274861326848) != 0) || _la == GrammarParser::ID) {
      setState(126);
      antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext = progElement();
      antlrcpp::downCast<ProgContext *>(_localctx)->items.push_back(antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext);
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> items_list = new ListNode<AbstractSyntaxTreeNode>{};

    			for(auto *item : antlrcpp::downCast<ProgContext *>(_localctx)->items){
    				items_list->add(item->m_node);
    			}

    			_localctx->m_node = new ProgNode{items_list};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgElementContext ------------------------------------------------------------------

GrammarParser::ProgElementContext::ProgElementContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::FunctionContext* GrammarParser::ProgElementContext::function() {
  return getRuleContext<GrammarParser::FunctionContext>(0);
}

GrammarParser::DeclarationContext* GrammarParser::ProgElementContext::declaration() {
  return getRuleContext<GrammarParser::DeclarationContext>(0);
}

GrammarParser::UnionDeclContext* GrammarParser::ProgElementContext::unionDecl() {
  return getRuleContext<GrammarParser::UnionDeclContext>(0);
}

GrammarParser::StructDeclContext* GrammarParser::ProgElementContext::structDecl() {
  return getRuleContext<GrammarParser::StructDeclContext>(0);
}


size_t GrammarParser::ProgElementContext::getRuleIndex() const {
  return GrammarParser::RuleProgElement;
}

void GrammarParser::ProgElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgElement(this);
}

void GrammarParser::ProgElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgElement(this);
}

GrammarParser::ProgElementContext* GrammarParser::progElement() {
  ProgElementContext *_localctx = _tracker.createInstance<ProgElementContext>(_ctx, getState());
  enterRule(_localctx, 12, GrammarParser::RuleProgElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext = function();

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext->m_node;	
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(137);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext = declaration();
      setState(138);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(141);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext = unionDecl();
      setState(142);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(145);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->structDeclContext = structDecl();
      setState(146);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->structDeclContext->m_node;
      			
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

GrammarParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DataTypeContext* GrammarParser::FunctionContext::dataType() {
  return getRuleContext<GrammarParser::DataTypeContext>(0);
}

GrammarParser::IdentifierContext* GrammarParser::FunctionContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::FunctionParametersContext* GrammarParser::FunctionContext::functionParameters() {
  return getRuleContext<GrammarParser::FunctionParametersContext>(0);
}

GrammarParser::BlockContext* GrammarParser::FunctionContext::block() {
  return getRuleContext<GrammarParser::BlockContext>(0);
}


size_t GrammarParser::FunctionContext::getRuleIndex() const {
  return GrammarParser::RuleFunction;
}

void GrammarParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void GrammarParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

GrammarParser::FunctionContext* GrammarParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 14, GrammarParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T__8) {
      setState(151);
      antlrcpp::downCast<FunctionContext *>(_localctx)->inline_keyword = match(GrammarParser::T__8);
    }
    setState(154);
    antlrcpp::downCast<FunctionContext *>(_localctx)->dataTypeContext = dataType();
    setState(155);
    antlrcpp::downCast<FunctionContext *>(_localctx)->identifierContext = identifier();
    setState(156);
    match(GrammarParser::T__1);
    setState(157);
    antlrcpp::downCast<FunctionContext *>(_localctx)->functionParametersContext = functionParameters();
    setState(158);
    match(GrammarParser::T__2);
    setState(159);
    antlrcpp::downCast<FunctionContext *>(_localctx)->blockContext = block();

    			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<FunctionContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>();
    			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<FunctionContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
    			ReferencePtr<ListNode<FunctionParameterNode>> params = antlrcpp::downCast<FunctionContext *>(_localctx)->functionParametersContext->m_node.cast<ListNode<FunctionParameterNode>>();
    			ReferencePtr<BlockNode> blk = antlrcpp::downCast<FunctionContext *>(_localctx)->blockContext->m_node.cast<BlockNode>();
    			bool is_inline = antlrcpp::downCast<FunctionContext *>(_localctx)->inline_keyword != nullptr;
    			_localctx->m_node = new FunctionNode{is_inline,dtn,in,params,blk};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParametersContext ------------------------------------------------------------------

GrammarParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::FunctionParameterContext *> GrammarParser::FunctionParametersContext::functionParameter() {
  return getRuleContexts<GrammarParser::FunctionParameterContext>();
}

GrammarParser::FunctionParameterContext* GrammarParser::FunctionParametersContext::functionParameter(size_t i) {
  return getRuleContext<GrammarParser::FunctionParameterContext>(i);
}


size_t GrammarParser::FunctionParametersContext::getRuleIndex() const {
  return GrammarParser::RuleFunctionParameters;
}

void GrammarParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void GrammarParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

GrammarParser::FunctionParametersContext* GrammarParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 16, GrammarParser::RuleFunctionParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & 4503599627386879) != 0)) {
      setState(162);
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::T__9) {
        setState(163);
        match(GrammarParser::T__9);
        setState(164);
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
        setState(169);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }

    				ReferencePtr<ListNode<FunctionParameterNode>> list = new ListNode<FunctionParameterNode>{};
    				for(auto *parameter : antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters){
    					list->add(parameter->m_node.cast<FunctionParameterNode>());
    				}
    				_localctx->m_node = list;
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParameterContext ------------------------------------------------------------------

GrammarParser::FunctionParameterContext::FunctionParameterContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DataTypeContext* GrammarParser::FunctionParameterContext::dataType() {
  return getRuleContext<GrammarParser::DataTypeContext>(0);
}

GrammarParser::IdentifierContext* GrammarParser::FunctionParameterContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}


size_t GrammarParser::FunctionParameterContext::getRuleIndex() const {
  return GrammarParser::RuleFunctionParameter;
}

void GrammarParser::FunctionParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameter(this);
}

void GrammarParser::FunctionParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameter(this);
}

GrammarParser::FunctionParameterContext* GrammarParser::functionParameter() {
  FunctionParameterContext *_localctx = _tracker.createInstance<FunctionParameterContext>(_ctx, getState());
  enterRule(_localctx, 18, GrammarParser::RuleFunctionParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    antlrcpp::downCast<FunctionParameterContext *>(_localctx)->dataTypeContext = dataType();
    setState(175);
    antlrcpp::downCast<FunctionParameterContext *>(_localctx)->identifierContext = identifier();

    			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<FunctionParameterContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>();
    			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<FunctionParameterContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
    			_localctx -> m_node = new FunctionParameterNode{dtn,in};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

GrammarParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::FunctionCallContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::ArgumentListContext* GrammarParser::FunctionCallContext::argumentList() {
  return getRuleContext<GrammarParser::ArgumentListContext>(0);
}


size_t GrammarParser::FunctionCallContext::getRuleIndex() const {
  return GrammarParser::RuleFunctionCall;
}

void GrammarParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void GrammarParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

GrammarParser::FunctionCallContext* GrammarParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 20, GrammarParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    antlrcpp::downCast<FunctionCallContext *>(_localctx)->identifierContext = identifier();
    setState(179);
    match(GrammarParser::T__1);
    setState(181);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223097708694994940) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 29689) != 0)) {
      setState(180);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->argumentListContext = argumentList();
    }
    setState(183);
    match(GrammarParser::T__2);

    			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> argument_list = new ListNode<AbstractSyntaxTreeNode>{};
    			if(antlrcpp::downCast<FunctionCallContext *>(_localctx)->argumentListContext!=nullptr)
    				argument_list = antlrcpp::downCast<FunctionCallContext *>(_localctx)->argumentListContext->m_node.cast<ListNode<AbstractSyntaxTreeNode>>();
    			else
    				argument_list = new ListNode<AbstractSyntaxTreeNode>{};
    			ReferencePtr<IdentifierNode> id = antlrcpp::downCast<FunctionCallContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();

    			_localctx->m_node = new FunctionCallNode{id,argument_list};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

GrammarParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::ExprContext *> GrammarParser::ArgumentListContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::ArgumentListContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}


size_t GrammarParser::ArgumentListContext::getRuleIndex() const {
  return GrammarParser::RuleArgumentList;
}

void GrammarParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void GrammarParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}

GrammarParser::ArgumentListContext* GrammarParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 22, GrammarParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(187);
      match(GrammarParser::T__9);
      setState(188);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
    			for(auto *arg : antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments){
    				list->add(arg->m_node);
    			}
    			_localctx->m_node = list;
    		 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

GrammarParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::StmtContext *> GrammarParser::BlockContext::stmt() {
  return getRuleContexts<GrammarParser::StmtContext>();
}

GrammarParser::StmtContext* GrammarParser::BlockContext::stmt(size_t i) {
  return getRuleContext<GrammarParser::StmtContext>(i);
}


size_t GrammarParser::BlockContext::getRuleIndex() const {
  return GrammarParser::RuleBlock;
}

void GrammarParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void GrammarParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

GrammarParser::BlockContext* GrammarParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 24, GrammarParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(GrammarParser::T__10);
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223097158955931434) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 32761) != 0)) {
      setState(197);
      antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext = stmt();
      antlrcpp::downCast<BlockContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext);
      setState(202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(203);
    match(GrammarParser::T__11);

    			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
    			for(auto *node : antlrcpp::downCast<BlockContext *>(_localctx)->items){
    				list->add(node->m_node);
    			}

    			_localctx->m_node = new BlockNode{ list };
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

GrammarParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DeclarationContext* GrammarParser::StmtContext::declaration() {
  return getRuleContext<GrammarParser::DeclarationContext>(0);
}

GrammarParser::FunctionCallContext* GrammarParser::StmtContext::functionCall() {
  return getRuleContext<GrammarParser::FunctionCallContext>(0);
}

GrammarParser::ReturnContext* GrammarParser::StmtContext::return_() {
  return getRuleContext<GrammarParser::ReturnContext>(0);
}

GrammarParser::IfContext* GrammarParser::StmtContext::if_() {
  return getRuleContext<GrammarParser::IfContext>(0);
}

GrammarParser::WhileContext* GrammarParser::StmtContext::while_() {
  return getRuleContext<GrammarParser::WhileContext>(0);
}

GrammarParser::ForContext* GrammarParser::StmtContext::for_() {
  return getRuleContext<GrammarParser::ForContext>(0);
}

GrammarParser::DoWhileContext* GrammarParser::StmtContext::doWhile() {
  return getRuleContext<GrammarParser::DoWhileContext>(0);
}

GrammarParser::BlockContext* GrammarParser::StmtContext::block() {
  return getRuleContext<GrammarParser::BlockContext>(0);
}

tree::TerminalNode* GrammarParser::StmtContext::BREAK() {
  return getToken(GrammarParser::BREAK, 0);
}

tree::TerminalNode* GrammarParser::StmtContext::CONTINUE() {
  return getToken(GrammarParser::CONTINUE, 0);
}

GrammarParser::ExprContext* GrammarParser::StmtContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::StmtContext::getRuleIndex() const {
  return GrammarParser::RuleStmt;
}

void GrammarParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void GrammarParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

GrammarParser::StmtContext* GrammarParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 26, GrammarParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(256);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(206);
      antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext = declaration();
      setState(207);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(210);
      antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext = functionCall();
      setState(211);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(214);
      antlrcpp::downCast<StmtContext *>(_localctx)->returnContext = return_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->returnContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(217);
      antlrcpp::downCast<StmtContext *>(_localctx)->ifContext = if_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->ifContext->m_node;
      			
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(220);
      antlrcpp::downCast<StmtContext *>(_localctx)->whileContext = while_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->whileContext->m_node;
      			
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(223);
      antlrcpp::downCast<StmtContext *>(_localctx)->forContext = for_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->forContext->m_node;
      			
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(226);
      antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext = doWhile();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext->m_node;
      			
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(229);
      antlrcpp::downCast<StmtContext *>(_localctx)->blockContext = block();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->blockContext->m_node;
      			
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(232);
      match(GrammarParser::BREAK);
      setState(233);
      match(GrammarParser::T__4);

      				_localctx->m_node = new BreakNode{};
      			
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(235);
      match(GrammarParser::CONTINUE);
      setState(236);
      match(GrammarParser::T__4);

      				_localctx->m_node = new ContinueNode{};
      			
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(238);
      match(GrammarParser::T__12);
      setState(239);
      match(GrammarParser::T__1);
      setState(240);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(241);
      match(GrammarParser::T__2);
      setState(242);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(245);
      match(GrammarParser::T__13);
      setState(246);
      match(GrammarParser::T__1);
      setState(247);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(248);
      match(GrammarParser::T__2);
      setState(249);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintTypeNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(252);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(253);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node;
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockDeclContext ------------------------------------------------------------------

GrammarParser::BlockDeclContext::BlockDeclContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::MemberDeclContext *> GrammarParser::BlockDeclContext::memberDecl() {
  return getRuleContexts<GrammarParser::MemberDeclContext>();
}

GrammarParser::MemberDeclContext* GrammarParser::BlockDeclContext::memberDecl(size_t i) {
  return getRuleContext<GrammarParser::MemberDeclContext>(i);
}


size_t GrammarParser::BlockDeclContext::getRuleIndex() const {
  return GrammarParser::RuleBlockDecl;
}

void GrammarParser::BlockDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockDecl(this);
}

void GrammarParser::BlockDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockDecl(this);
}

GrammarParser::BlockDeclContext* GrammarParser::blockDecl() {
  BlockDeclContext *_localctx = _tracker.createInstance<BlockDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, GrammarParser::RuleBlockDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    match(GrammarParser::T__10);
    setState(262);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & 4503599627386879) != 0)) {
      setState(259);
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext = memberDecl();
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext);
      setState(264);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(265);
    match(GrammarParser::T__11);

    			ReferencePtr<ListNode<MemberDeclarationNode>> list = new ListNode<MemberDeclarationNode>{};

    			for(auto *item : antlrcpp::downCast<BlockDeclContext *>(_localctx)->items)
    				list->add(item->m_node.cast<MemberDeclarationNode>());

    			_localctx->m_node = list;
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberDeclContext ------------------------------------------------------------------

GrammarParser::MemberDeclContext::MemberDeclContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DataTypeContext* GrammarParser::MemberDeclContext::dataType() {
  return getRuleContext<GrammarParser::DataTypeContext>(0);
}

GrammarParser::IdentifierContext* GrammarParser::MemberDeclContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}


size_t GrammarParser::MemberDeclContext::getRuleIndex() const {
  return GrammarParser::RuleMemberDecl;
}

void GrammarParser::MemberDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberDecl(this);
}

void GrammarParser::MemberDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberDecl(this);
}

GrammarParser::MemberDeclContext* GrammarParser::memberDecl() {
  MemberDeclContext *_localctx = _tracker.createInstance<MemberDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, GrammarParser::RuleMemberDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->dataTypeContext = dataType();
    setState(269);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->identifierContext = identifier();
    setState(270);
    match(GrammarParser::T__4);

    			ReferencePtr<DataTypeNode> data_type = antlrcpp::downCast<MemberDeclContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>();
    			ReferencePtr<IdentifierNode> id = antlrcpp::downCast<MemberDeclContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();

    			_localctx->m_node = new MemberDeclarationNode{data_type,id};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

GrammarParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DataTypeContext* GrammarParser::DeclarationContext::dataType() {
  return getRuleContext<GrammarParser::DataTypeContext>(0);
}

std::vector<GrammarParser::DeclarationListItemContext *> GrammarParser::DeclarationContext::declarationListItem() {
  return getRuleContexts<GrammarParser::DeclarationListItemContext>();
}

GrammarParser::DeclarationListItemContext* GrammarParser::DeclarationContext::declarationListItem(size_t i) {
  return getRuleContext<GrammarParser::DeclarationListItemContext>(i);
}


size_t GrammarParser::DeclarationContext::getRuleIndex() const {
  return GrammarParser::RuleDeclaration;
}

void GrammarParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void GrammarParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

GrammarParser::DeclarationContext* GrammarParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, GrammarParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->dataTypeContext = dataType();
    setState(274);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
    antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
    setState(279);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(275);
      match(GrammarParser::T__9);
      setState(276);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
      antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
      setState(281);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<DeclarationContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>();
    			ReferencePtr<ListNode<DeclarationListItemNode>> list = new ListNode<DeclarationListItemNode>{};

    			for(auto *decl_list_item : antlrcpp::downCast<DeclarationContext *>(_localctx)->items)
    				list->add(decl_list_item->m_node.cast<DeclarationListItemNode>());

    			_localctx->m_node = new DeclarationNode{dtn,list};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListItemContext ------------------------------------------------------------------

GrammarParser::DeclarationListItemContext::DeclarationListItemContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::DeclarationListItemContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::ExprContext* GrammarParser::DeclarationListItemContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

GrammarParser::InitializationListContext* GrammarParser::DeclarationListItemContext::initializationList() {
  return getRuleContext<GrammarParser::InitializationListContext>(0);
}


size_t GrammarParser::DeclarationListItemContext::getRuleIndex() const {
  return GrammarParser::RuleDeclarationListItem;
}

void GrammarParser::DeclarationListItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationListItem(this);
}

void GrammarParser::DeclarationListItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationListItem(this);
}

GrammarParser::DeclarationListItemContext* GrammarParser::declarationListItem() {
  DeclarationListItemContext *_localctx = _tracker.createInstance<DeclarationListItemContext>(_ctx, getState());
  enterRule(_localctx, 34, GrammarParser::RuleDeclarationListItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(284);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			_localctx -> m_node = new DeclarationListItemNode{in};
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(287);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();
      setState(288);
      match(GrammarParser::T__14);
      setState(289);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->exprContext = expr(0);

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			ReferencePtr<AbstractSyntaxTreeNode> expr = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->exprContext->m_node;
      			_localctx->m_node = new DeclarationListItemNode{in,expr};
      		
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(293);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();
      setState(294);
      match(GrammarParser::T__14);
      setState(295);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->initializationListContext = initializationList();

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			_localctx->m_node = new DeclarationListItemNode{in,antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->initializationListContext->m_node};
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclContext ------------------------------------------------------------------

GrammarParser::StructDeclContext::StructDeclContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::StructDeclContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::BlockDeclContext* GrammarParser::StructDeclContext::blockDecl() {
  return getRuleContext<GrammarParser::BlockDeclContext>(0);
}


size_t GrammarParser::StructDeclContext::getRuleIndex() const {
  return GrammarParser::RuleStructDecl;
}

void GrammarParser::StructDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDecl(this);
}

void GrammarParser::StructDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDecl(this);
}

GrammarParser::StructDeclContext* GrammarParser::structDecl() {
  StructDeclContext *_localctx = _tracker.createInstance<StructDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, GrammarParser::RuleStructDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(GrammarParser::T__15);
    setState(302);
    antlrcpp::downCast<StructDeclContext *>(_localctx)->identifierContext = identifier();
    setState(303);
    antlrcpp::downCast<StructDeclContext *>(_localctx)->blockDeclContext = blockDecl();

    			ReferencePtr<IdentifierNode> id_node = antlrcpp::downCast<StructDeclContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
    			ReferencePtr<ListNode<MemberDeclarationNode>> decl_list = antlrcpp::downCast<StructDeclContext *>(_localctx)->blockDeclContext->m_node.cast<ListNode<MemberDeclarationNode>>();
    			
    			_localctx->m_node = new StructNode{id_node,decl_list};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnionDeclContext ------------------------------------------------------------------

GrammarParser::UnionDeclContext::UnionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::UnionDeclContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::BlockDeclContext* GrammarParser::UnionDeclContext::blockDecl() {
  return getRuleContext<GrammarParser::BlockDeclContext>(0);
}


size_t GrammarParser::UnionDeclContext::getRuleIndex() const {
  return GrammarParser::RuleUnionDecl;
}

void GrammarParser::UnionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnionDecl(this);
}

void GrammarParser::UnionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnionDecl(this);
}

GrammarParser::UnionDeclContext* GrammarParser::unionDecl() {
  UnionDeclContext *_localctx = _tracker.createInstance<UnionDeclContext>(_ctx, getState());
  enterRule(_localctx, 38, GrammarParser::RuleUnionDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(GrammarParser::T__16);
    setState(307);
    antlrcpp::downCast<UnionDeclContext *>(_localctx)->identifierContext = identifier();
    setState(308);
    antlrcpp::downCast<UnionDeclContext *>(_localctx)->blockDeclContext = blockDecl();

    			ReferencePtr<IdentifierNode> id_node =  antlrcpp::downCast<UnionDeclContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
    			ReferencePtr<ListNode<MemberDeclarationNode>> decl_list = antlrcpp::downCast<UnionDeclContext *>(_localctx)->blockDeclContext->m_node.cast<ListNode<MemberDeclarationNode>>();
    			
    			_localctx->m_node = new UnionNode{id_node,decl_list}; 
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FundamentalTypeContext ------------------------------------------------------------------

GrammarParser::FundamentalTypeContext::FundamentalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::BasicTypeContext* GrammarParser::FundamentalTypeContext::basicType() {
  return getRuleContext<GrammarParser::BasicTypeContext>(0);
}

GrammarParser::IdentifierContext* GrammarParser::FundamentalTypeContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}


size_t GrammarParser::FundamentalTypeContext::getRuleIndex() const {
  return GrammarParser::RuleFundamentalType;
}

void GrammarParser::FundamentalTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFundamentalType(this);
}

void GrammarParser::FundamentalTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFundamentalType(this);
}

GrammarParser::FundamentalTypeContext* GrammarParser::fundamentalType() {
  FundamentalTypeContext *_localctx = _tracker.createInstance<FundamentalTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, GrammarParser::RuleFundamentalType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__23:
      case GrammarParser::T__24:
      case GrammarParser::T__25:
      case GrammarParser::T__26:
      case GrammarParser::T__27:
      case GrammarParser::T__28:
      case GrammarParser::T__29:
      case GrammarParser::T__30:
      case GrammarParser::T__31:
      case GrammarParser::T__32:
      case GrammarParser::T__33:
      case GrammarParser::T__34:
      case GrammarParser::T__35:
      case GrammarParser::T__36: {
        enterOuterAlt(_localctx, 1);
        setState(311);
        antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext = basicType();
         _localctx->m_node = antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext->m_node; 
        break;
      }

      case GrammarParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(314);
        antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->identifierContext = identifier();
         _localctx->m_node = antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->identifierContext->m_node; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataTypeContext ------------------------------------------------------------------

GrammarParser::DataTypeContext::DataTypeContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::FundamentalTypeContext* GrammarParser::DataTypeContext::fundamentalType() {
  return getRuleContext<GrammarParser::FundamentalTypeContext>(0);
}

std::vector<GrammarParser::TypeModifierContext *> GrammarParser::DataTypeContext::typeModifier() {
  return getRuleContexts<GrammarParser::TypeModifierContext>();
}

GrammarParser::TypeModifierContext* GrammarParser::DataTypeContext::typeModifier(size_t i) {
  return getRuleContext<GrammarParser::TypeModifierContext>(i);
}


size_t GrammarParser::DataTypeContext::getRuleIndex() const {
  return GrammarParser::RuleDataType;
}

void GrammarParser::DataTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDataType(this);
}

void GrammarParser::DataTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDataType(this);
}

GrammarParser::DataTypeContext* GrammarParser::dataType() {
  DataTypeContext *_localctx = _tracker.createInstance<DataTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, GrammarParser::RuleDataType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    antlrcpp::downCast<DataTypeContext *>(_localctx)->ft = fundamentalType();
    setState(323);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15466496) != 0)) {
      setState(320);
      antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext = typeModifier();
      antlrcpp::downCast<DataTypeContext *>(_localctx)->modifier_list.push_back(antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext);
      setState(325);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
    			ReferencePtr<AbstractSyntaxTreeNode> fundamental_type = antlrcpp::downCast<DataTypeContext *>(_localctx)->ft->m_node;

    			for(auto *element : antlrcpp::downCast<DataTypeContext *>(_localctx)->modifier_list)
    				list->add(element->m_node);

    			_localctx->m_node = new DataTypeNode{fundamental_type,list};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeModifierContext ------------------------------------------------------------------

GrammarParser::TypeModifierContext::TypeModifierContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::TypeModifierContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::TypeModifierContext::getRuleIndex() const {
  return GrammarParser::RuleTypeModifier;
}

void GrammarParser::TypeModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeModifier(this);
}

void GrammarParser::TypeModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeModifier(this);
}

GrammarParser::TypeModifierContext* GrammarParser::typeModifier() {
  TypeModifierContext *_localctx = _tracker.createInstance<TypeModifierContext>(_ctx, getState());
  enterRule(_localctx, 44, GrammarParser::RuleTypeModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(341);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__17: {
        enterOuterAlt(_localctx, 1);
        setState(328);
        match(GrammarParser::T__17);
        _localctx->m_node = new PointerNode{}; 
        break;
      }

      case GrammarParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(330);
        match(GrammarParser::T__18);

        setState(331);
        antlrcpp::downCast<TypeModifierContext *>(_localctx)->e = expr(0);
        setState(332);
        match(GrammarParser::T__19);
         _localctx->m_node = new ArrayNode{ antlrcpp::downCast<TypeModifierContext *>(_localctx)->e->m_node }; 
        break;
      }

      case GrammarParser::T__20: {
        enterOuterAlt(_localctx, 3);
        setState(335);
        match(GrammarParser::T__20);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::CONST}; 
        break;
      }

      case GrammarParser::T__21: {
        enterOuterAlt(_localctx, 4);
        setState(337);
        match(GrammarParser::T__21);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::VOLATILE}; 
        break;
      }

      case GrammarParser::T__22: {
        enterOuterAlt(_localctx, 5);
        setState(339);
        match(GrammarParser::T__22);
         _localctx->m_node = new ReferenceNode{}; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

GrammarParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}


size_t GrammarParser::BasicTypeContext::getRuleIndex() const {
  return GrammarParser::RuleBasicType;
}

void GrammarParser::BasicTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicType(this);
}

void GrammarParser::BasicTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicType(this);
}

GrammarParser::BasicTypeContext* GrammarParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, GrammarParser::RuleBasicType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(371);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__23: {
        enterOuterAlt(_localctx, 1);
        setState(343);
        match(GrammarParser::T__23);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__24: {
        enterOuterAlt(_localctx, 2);
        setState(345);
        match(GrammarParser::T__24);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT8}; 
        break;
      }

      case GrammarParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(347);
        match(GrammarParser::T__25);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT16}; 
        break;
      }

      case GrammarParser::T__26: {
        enterOuterAlt(_localctx, 4);
        setState(349);
        match(GrammarParser::T__26);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__27: {
        enterOuterAlt(_localctx, 5);
        setState(351);
        match(GrammarParser::T__27);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT64}; 
        break;
      }

      case GrammarParser::T__28: {
        enterOuterAlt(_localctx, 6);
        setState(353);
        match(GrammarParser::T__28);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT8}; 
        break;
      }

      case GrammarParser::T__29: {
        enterOuterAlt(_localctx, 7);
        setState(355);
        match(GrammarParser::T__29);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT16}; 
        break;
      }

      case GrammarParser::T__30: {
        enterOuterAlt(_localctx, 8);
        setState(357);
        match(GrammarParser::T__30);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT32}; 
        break;
      }

      case GrammarParser::T__31: {
        enterOuterAlt(_localctx, 9);
        setState(359);
        match(GrammarParser::T__31);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT64}; 
        break;
      }

      case GrammarParser::T__32: {
        enterOuterAlt(_localctx, 10);
        setState(361);
        match(GrammarParser::T__32);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::FLOAT}; 
        break;
      }

      case GrammarParser::T__33: {
        enterOuterAlt(_localctx, 11);
        setState(363);
        match(GrammarParser::T__33);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::DOUBLE}; 
        break;
      }

      case GrammarParser::T__34: {
        enterOuterAlt(_localctx, 12);
        setState(365);
        match(GrammarParser::T__34);
         _localctx->m_node = new BasicTypeNode{IRBasicType::BOOL}; 
        break;
      }

      case GrammarParser::T__35: {
        enterOuterAlt(_localctx, 13);
        setState(367);
        match(GrammarParser::T__35);
         _localctx->m_node = new BasicTypeNode{IRBasicType::VOID}; 
        break;
      }

      case GrammarParser::T__36: {
        enterOuterAlt(_localctx, 14);
        setState(369);
        match(GrammarParser::T__36);
         _localctx->m_node = new BasicTypeNode{IRBasicType::CHAR}; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

GrammarParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::ReturnContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::ReturnContext::getRuleIndex() const {
  return GrammarParser::RuleReturn;
}

void GrammarParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void GrammarParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}

GrammarParser::ReturnContext* GrammarParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 48, GrammarParser::RuleReturn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(GrammarParser::T__37);
    setState(375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223097708694994940) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 29689) != 0)) {
      setState(374);
      antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext = expr(0);
    }
    setState(377);
    match(GrammarParser::T__4);
     _localctx -> m_node = new ReturnNode{ antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext ? antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext->m_node : nullptr }; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SizeOfContext ------------------------------------------------------------------

GrammarParser::SizeOfContext::SizeOfContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DataTypeContext* GrammarParser::SizeOfContext::dataType() {
  return getRuleContext<GrammarParser::DataTypeContext>(0);
}


size_t GrammarParser::SizeOfContext::getRuleIndex() const {
  return GrammarParser::RuleSizeOf;
}

void GrammarParser::SizeOfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSizeOf(this);
}

void GrammarParser::SizeOfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSizeOf(this);
}

GrammarParser::SizeOfContext* GrammarParser::sizeOf() {
  SizeOfContext *_localctx = _tracker.createInstance<SizeOfContext>(_ctx, getState());
  enterRule(_localctx, 50, GrammarParser::RuleSizeOf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(GrammarParser::T__38);
    setState(381);
    match(GrammarParser::T__1);
    setState(382);
    antlrcpp::downCast<SizeOfContext *>(_localctx)->dataTypeContext = dataType();
    setState(383);
    match(GrammarParser::T__2);
     
    			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<SizeOfContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>();
    			_localctx->m_node = new SizeOfNode{dtn}; 
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssertConditionContext ------------------------------------------------------------------

GrammarParser::AssertConditionContext::AssertConditionContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::AssertConditionContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::AssertConditionContext::getRuleIndex() const {
  return GrammarParser::RuleAssertCondition;
}

void GrammarParser::AssertConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssertCondition(this);
}

void GrammarParser::AssertConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssertCondition(this);
}

GrammarParser::AssertConditionContext* GrammarParser::assertCondition() {
  AssertConditionContext *_localctx = _tracker.createInstance<AssertConditionContext>(_ctx, getState());
  enterRule(_localctx, 52, GrammarParser::RuleAssertCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(GrammarParser::T__39);
    setState(387);
    match(GrammarParser::T__1);
    setState(388);
    antlrcpp::downCast<AssertConditionContext *>(_localctx)->exprContext = expr(0);
    setState(389);
    match(GrammarParser::T__2);

    			_localctx->m_node = new AssertNode{antlrcpp::downCast<AssertConditionContext *>(_localctx)->exprContext->m_node};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializationListContext ------------------------------------------------------------------

GrammarParser::InitializationListContext::InitializationListContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::UnnamedInitializationListContext* GrammarParser::InitializationListContext::unnamedInitializationList() {
  return getRuleContext<GrammarParser::UnnamedInitializationListContext>(0);
}

GrammarParser::NamedInitializationListContext* GrammarParser::InitializationListContext::namedInitializationList() {
  return getRuleContext<GrammarParser::NamedInitializationListContext>(0);
}


size_t GrammarParser::InitializationListContext::getRuleIndex() const {
  return GrammarParser::RuleInitializationList;
}

void GrammarParser::InitializationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializationList(this);
}

void GrammarParser::InitializationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializationList(this);
}

GrammarParser::InitializationListContext* GrammarParser::initializationList() {
  InitializationListContext *_localctx = _tracker.createInstance<InitializationListContext>(_ctx, getState());
  enterRule(_localctx, 54, GrammarParser::RuleInitializationList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(392);
      antlrcpp::downCast<InitializationListContext *>(_localctx)->unnamedInitializationListContext = unnamedInitializationList();

      					_localctx->m_node = antlrcpp::downCast<InitializationListContext *>(_localctx)->unnamedInitializationListContext->m_node;
      				
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(395);
      antlrcpp::downCast<InitializationListContext *>(_localctx)->namedInitializationListContext = namedInitializationList();

      					_localctx->m_node = antlrcpp::downCast<InitializationListContext *>(_localctx)->namedInitializationListContext->m_node;
      			
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnnamedInitializationListContext ------------------------------------------------------------------

GrammarParser::UnnamedInitializationListContext::UnnamedInitializationListContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::UnnamedListElementsContext* GrammarParser::UnnamedInitializationListContext::unnamedListElements() {
  return getRuleContext<GrammarParser::UnnamedListElementsContext>(0);
}


size_t GrammarParser::UnnamedInitializationListContext::getRuleIndex() const {
  return GrammarParser::RuleUnnamedInitializationList;
}

void GrammarParser::UnnamedInitializationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnnamedInitializationList(this);
}

void GrammarParser::UnnamedInitializationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnnamedInitializationList(this);
}

GrammarParser::UnnamedInitializationListContext* GrammarParser::unnamedInitializationList() {
  UnnamedInitializationListContext *_localctx = _tracker.createInstance<UnnamedInitializationListContext>(_ctx, getState());
  enterRule(_localctx, 56, GrammarParser::RuleUnnamedInitializationList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    match(GrammarParser::T__10);
    setState(402);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223097708694992892) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 29689) != 0)) {
      setState(401);
      antlrcpp::downCast<UnnamedInitializationListContext *>(_localctx)->unnamedListElementsContext = unnamedListElements();
    }
    setState(404);
    match(GrammarParser::T__11);

    				if(antlrcpp::downCast<UnnamedInitializationListContext *>(_localctx)->unnamedListElementsContext)
    					_localctx->m_node = new UnnamedInitializationListNode{ antlrcpp::downCast<UnnamedInitializationListContext *>(_localctx)->unnamedListElementsContext->m_node.cast<ListNode<AbstractSyntaxTreeNode>>() };
    				else
    					_localctx->m_node = new UnnamedInitializationListNode{ {} };
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnnamedListElementsContext ------------------------------------------------------------------

GrammarParser::UnnamedListElementsContext::UnnamedListElementsContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::UnnamedListElementContext *> GrammarParser::UnnamedListElementsContext::unnamedListElement() {
  return getRuleContexts<GrammarParser::UnnamedListElementContext>();
}

GrammarParser::UnnamedListElementContext* GrammarParser::UnnamedListElementsContext::unnamedListElement(size_t i) {
  return getRuleContext<GrammarParser::UnnamedListElementContext>(i);
}


size_t GrammarParser::UnnamedListElementsContext::getRuleIndex() const {
  return GrammarParser::RuleUnnamedListElements;
}

void GrammarParser::UnnamedListElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnnamedListElements(this);
}

void GrammarParser::UnnamedListElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnnamedListElements(this);
}

GrammarParser::UnnamedListElementsContext* GrammarParser::unnamedListElements() {
  UnnamedListElementsContext *_localctx = _tracker.createInstance<UnnamedListElementsContext>(_ctx, getState());
  enterRule(_localctx, 58, GrammarParser::RuleUnnamedListElements);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->unnamedListElementContext = unnamedListElement();
    antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->elements.push_back(antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->unnamedListElementContext);
    setState(412);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(408);
      match(GrammarParser::T__9);
      setState(409);
      antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->unnamedListElementContext = unnamedListElement();
      antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->elements.push_back(antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->unnamedListElementContext);
      setState(414);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    				ReferencePtr<ListNode<AbstractSyntaxTreeNode>> unnamed_list_elements = new ListNode<AbstractSyntaxTreeNode>{};
    				for(auto *element : antlrcpp::downCast<UnnamedListElementsContext *>(_localctx)->elements)
    					unnamed_list_elements->add(element->m_node);

    				_localctx->m_node = unnamed_list_elements;
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnnamedListElementContext ------------------------------------------------------------------

GrammarParser::UnnamedListElementContext::UnnamedListElementContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::UnnamedListElementContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

GrammarParser::NamedInitializationListContext* GrammarParser::UnnamedListElementContext::namedInitializationList() {
  return getRuleContext<GrammarParser::NamedInitializationListContext>(0);
}

GrammarParser::UnnamedInitializationListContext* GrammarParser::UnnamedListElementContext::unnamedInitializationList() {
  return getRuleContext<GrammarParser::UnnamedInitializationListContext>(0);
}


size_t GrammarParser::UnnamedListElementContext::getRuleIndex() const {
  return GrammarParser::RuleUnnamedListElement;
}

void GrammarParser::UnnamedListElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnnamedListElement(this);
}

void GrammarParser::UnnamedListElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnnamedListElement(this);
}

GrammarParser::UnnamedListElementContext* GrammarParser::unnamedListElement() {
  UnnamedListElementContext *_localctx = _tracker.createInstance<UnnamedListElementContext>(_ctx, getState());
  enterRule(_localctx, 60, GrammarParser::RuleUnnamedListElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(426);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(417);
      antlrcpp::downCast<UnnamedListElementContext *>(_localctx)->e = expr(0);

      					_localctx->m_node = antlrcpp::downCast<UnnamedListElementContext *>(_localctx)->e->m_node;
      				
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(420);
      antlrcpp::downCast<UnnamedListElementContext *>(_localctx)->namedInitializationListContext = namedInitializationList();

      				_localctx->m_node = antlrcpp::downCast<UnnamedListElementContext *>(_localctx)->namedInitializationListContext->m_node;
      				
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(423);
      antlrcpp::downCast<UnnamedListElementContext *>(_localctx)->unnamedInitializationListContext = unnamedInitializationList();

      				_localctx->m_node = antlrcpp::downCast<UnnamedListElementContext *>(_localctx)->unnamedInitializationListContext->m_node;
      			
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedInitializationListContext ------------------------------------------------------------------

GrammarParser::NamedInitializationListContext::NamedInitializationListContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::NamedListElementsContext* GrammarParser::NamedInitializationListContext::namedListElements() {
  return getRuleContext<GrammarParser::NamedListElementsContext>(0);
}


size_t GrammarParser::NamedInitializationListContext::getRuleIndex() const {
  return GrammarParser::RuleNamedInitializationList;
}

void GrammarParser::NamedInitializationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedInitializationList(this);
}

void GrammarParser::NamedInitializationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedInitializationList(this);
}

GrammarParser::NamedInitializationListContext* GrammarParser::namedInitializationList() {
  NamedInitializationListContext *_localctx = _tracker.createInstance<NamedInitializationListContext>(_ctx, getState());
  enterRule(_localctx, 62, GrammarParser::RuleNamedInitializationList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(GrammarParser::T__10);
    setState(429);
    antlrcpp::downCast<NamedInitializationListContext *>(_localctx)->namedListElementsContext = namedListElements();
    setState(430);
    match(GrammarParser::T__11);

    				_localctx->m_node = new NamedInitializationListNode{antlrcpp::downCast<NamedInitializationListContext *>(_localctx)->namedListElementsContext->m_node.cast<ListNode<NamedListElementNode>>()};
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedListElementsContext ------------------------------------------------------------------

GrammarParser::NamedListElementsContext::NamedListElementsContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::NamedListElementContext *> GrammarParser::NamedListElementsContext::namedListElement() {
  return getRuleContexts<GrammarParser::NamedListElementContext>();
}

GrammarParser::NamedListElementContext* GrammarParser::NamedListElementsContext::namedListElement(size_t i) {
  return getRuleContext<GrammarParser::NamedListElementContext>(i);
}


size_t GrammarParser::NamedListElementsContext::getRuleIndex() const {
  return GrammarParser::RuleNamedListElements;
}

void GrammarParser::NamedListElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedListElements(this);
}

void GrammarParser::NamedListElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedListElements(this);
}

GrammarParser::NamedListElementsContext* GrammarParser::namedListElements() {
  NamedListElementsContext *_localctx = _tracker.createInstance<NamedListElementsContext>(_ctx, getState());
  enterRule(_localctx, 64, GrammarParser::RuleNamedListElements);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    antlrcpp::downCast<NamedListElementsContext *>(_localctx)->namedListElementContext = namedListElement();
    antlrcpp::downCast<NamedListElementsContext *>(_localctx)->elements.push_back(antlrcpp::downCast<NamedListElementsContext *>(_localctx)->namedListElementContext);
    setState(438);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(434);
      match(GrammarParser::T__9);
      setState(435);
      antlrcpp::downCast<NamedListElementsContext *>(_localctx)->namedListElementContext = namedListElement();
      antlrcpp::downCast<NamedListElementsContext *>(_localctx)->elements.push_back(antlrcpp::downCast<NamedListElementsContext *>(_localctx)->namedListElementContext);
      setState(440);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    				ReferencePtr<ListNode<NamedListElementNode>> named_list_elements = new ListNode<NamedListElementNode>{};
    				for(auto *element : antlrcpp::downCast<NamedListElementsContext *>(_localctx)->elements){
    					named_list_elements->add(element->m_node.cast<NamedListElementNode>());
    				}

    				_localctx->m_node = named_list_elements;
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedListElementContext ------------------------------------------------------------------

GrammarParser::NamedListElementContext::NamedListElementContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::NamedListElementContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::ExprContext* GrammarParser::NamedListElementContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

GrammarParser::NamedInitializationListContext* GrammarParser::NamedListElementContext::namedInitializationList() {
  return getRuleContext<GrammarParser::NamedInitializationListContext>(0);
}

GrammarParser::UnnamedInitializationListContext* GrammarParser::NamedListElementContext::unnamedInitializationList() {
  return getRuleContext<GrammarParser::UnnamedInitializationListContext>(0);
}


size_t GrammarParser::NamedListElementContext::getRuleIndex() const {
  return GrammarParser::RuleNamedListElement;
}

void GrammarParser::NamedListElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedListElement(this);
}

void GrammarParser::NamedListElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedListElement(this);
}

GrammarParser::NamedListElementContext* GrammarParser::namedListElement() {
  NamedListElementContext *_localctx = _tracker.createInstance<NamedListElementContext>(_ctx, getState());
  enterRule(_localctx, 66, GrammarParser::RuleNamedListElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(461);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(443);
      match(GrammarParser::T__40);

      setState(444);
      antlrcpp::downCast<NamedListElementContext *>(_localctx)->id = identifier();
      setState(445);
      match(GrammarParser::T__14);

      setState(446);
      antlrcpp::downCast<NamedListElementContext *>(_localctx)->e = expr(0);

      					ReferencePtr<IdentifierNode> id_node = antlrcpp::downCast<NamedListElementContext *>(_localctx)->id->m_node.cast<IdentifierNode>();
      					_localctx->m_node = new NamedListElementNode{id_node,antlrcpp::downCast<NamedListElementContext *>(_localctx)->e->m_node};
      				
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(449);
      match(GrammarParser::T__40);

      setState(450);
      antlrcpp::downCast<NamedListElementContext *>(_localctx)->id = identifier();
      setState(451);
      match(GrammarParser::T__14);

      setState(452);
      antlrcpp::downCast<NamedListElementContext *>(_localctx)->named_initialization_list = namedInitializationList();

      					ReferencePtr<IdentifierNode> id_node = antlrcpp::downCast<NamedListElementContext *>(_localctx)->id->m_node.cast<IdentifierNode>();
      					_localctx->m_node = new NamedListElementNode{id_node,antlrcpp::downCast<NamedListElementContext *>(_localctx)->named_initialization_list->m_node};
      				
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(455);
      match(GrammarParser::T__40);

      setState(456);
      antlrcpp::downCast<NamedListElementContext *>(_localctx)->id = identifier();
      setState(457);
      match(GrammarParser::T__14);

      setState(458);
      antlrcpp::downCast<NamedListElementContext *>(_localctx)->unnamed_initialization_list = unnamedInitializationList();

      					ReferencePtr<IdentifierNode> id_node = antlrcpp::downCast<NamedListElementContext *>(_localctx)->id->m_node.cast<IdentifierNode>();
      					_localctx->m_node = new NamedListElementNode{id_node,antlrcpp::downCast<NamedListElementContext *>(_localctx)->unnamed_initialization_list->m_node};
      				
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

GrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::DataTypeContext* GrammarParser::ExprContext::dataType() {
  return getRuleContext<GrammarParser::DataTypeContext>(0);
}

std::vector<GrammarParser::ExprContext *> GrammarParser::ExprContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::ExprContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}

GrammarParser::FunctionCallContext* GrammarParser::ExprContext::functionCall() {
  return getRuleContext<GrammarParser::FunctionCallContext>(0);
}

GrammarParser::IdentifierContext* GrammarParser::ExprContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::NumberContext* GrammarParser::ExprContext::number() {
  return getRuleContext<GrammarParser::NumberContext>(0);
}

GrammarParser::SizeOfContext* GrammarParser::ExprContext::sizeOf() {
  return getRuleContext<GrammarParser::SizeOfContext>(0);
}

GrammarParser::AssertConditionContext* GrammarParser::ExprContext::assertCondition() {
  return getRuleContext<GrammarParser::AssertConditionContext>(0);
}

GrammarParser::SelectContext* GrammarParser::ExprContext::select() {
  return getRuleContext<GrammarParser::SelectContext>(0);
}

GrammarParser::String_literalContext* GrammarParser::ExprContext::string_literal() {
  return getRuleContext<GrammarParser::String_literalContext>(0);
}

GrammarParser::Char_literalContext* GrammarParser::ExprContext::char_literal() {
  return getRuleContext<GrammarParser::Char_literalContext>(0);
}

GrammarParser::InitializationListContext* GrammarParser::ExprContext::initializationList() {
  return getRuleContext<GrammarParser::InitializationListContext>(0);
}


size_t GrammarParser::ExprContext::getRuleIndex() const {
  return GrammarParser::RuleExpr;
}

void GrammarParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void GrammarParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


GrammarParser::ExprContext* GrammarParser::expr() {
   return expr(0);
}

GrammarParser::ExprContext* GrammarParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GrammarParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  GrammarParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, GrammarParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(464);
      match(GrammarParser::T__1);
      setState(465);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(466);
      match(GrammarParser::T__2);
      setState(467);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(34);

      			_localctx->m_node = new CastNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 2: {
      setState(470);
      match(GrammarParser::T__42);
      setState(471);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(29);

      			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 3: {
      setState(474);
      match(GrammarParser::T__43);
      setState(475);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(27);

      			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 4: {
      setState(478);
      match(GrammarParser::T__44);
      setState(479);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(26);

      			_localctx->m_node = new UnaryMinusNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 5: {
      setState(482);
      match(GrammarParser::T__45);
      setState(483);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(25);

      			_localctx->m_node = new BitwiseNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 6: {
      setState(486);
      match(GrammarParser::T__46);
      setState(487);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(24);

      			_localctx->m_node = new BooleanNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 7: {
      setState(490);
      match(GrammarParser::T__17);
      setState(491);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(23);

      			_localctx->m_node = new DereferenceNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 8: {
      setState(494);
      match(GrammarParser::T__22);
      setState(495);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(22);

      			_localctx->m_node = new AddressOfNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 9: {
      setState(498);
      antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext = functionCall();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext->m_node; 
      break;
    }

    case 10: {
      setState(501);
      antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext->m_node; 
      break;
    }

    case 11: {
      setState(504);
      antlrcpp::downCast<ExprContext *>(_localctx)->numberContext = number();
       _localctx -> m_node = antlrcpp::downCast<ExprContext *>(_localctx)->numberContext->m_node; 
      break;
    }

    case 12: {
      setState(507);
      match(GrammarParser::T__1);
      setState(508);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(509);
      match(GrammarParser::T__2);
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node; 
      break;
    }

    case 13: {
      setState(512);
      match(GrammarParser::T__62);
      setState(513);
      match(GrammarParser::T__54);
      setState(514);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(515);
      match(GrammarParser::T__52);
      setState(516);
      match(GrammarParser::T__1);
      setState(517);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(518);
      match(GrammarParser::T__2);

      			_localctx->m_node = new ReinterpretNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 14: {
      setState(521);
      antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext = sizeOf();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext->m_node; 
      break;
    }

    case 15: {
      setState(524);
      antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext = assertCondition();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext->m_node; 
      break;
    }

    case 16: {
      setState(527);
      antlrcpp::downCast<ExprContext *>(_localctx)->selectContext = select();

      			_localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->selectContext->m_node;
      		
      break;
    }

    case 17: {
      setState(530);
      antlrcpp::downCast<ExprContext *>(_localctx)->string_literalContext = string_literal();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->string_literalContext->m_node; 
      break;
    }

    case 18: {
      setState(533);
      antlrcpp::downCast<ExprContext *>(_localctx)->char_literalContext = char_literal();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->char_literalContext->m_node; 
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(617);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(615);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(538);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(539);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 844424930394112) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(540);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(22);
           
                    			char operation = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data()[0];
                    			OperationType basicType;
                    			switch(operation){
                    			case '*':
                    				basicType = OperationType::MUL;
                    				break;
                    			case '/':
                    				basicType = OperationType::DIV;
                    				break;
                    			case '%':
                    				basicType = OperationType::MOD;
                    				break;
                    			}
                    			_localctx -> m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node, basicType }; 
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(543);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(544);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__44

          || _la == GrammarParser::T__49)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(545);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(21);

                    			char operation = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data()[0];
                    			OperationType basicType;
                    			switch(operation){
                    			case '+':
                    				basicType = OperationType::ADD;
                    				break;
                    			case '-':
                    				basicType = OperationType::SUB;
                    				break;
                    			}

                    			_localctx -> m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node, basicType }; 
                    		
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(548);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(549);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__50

          || _la == GrammarParser::T__51)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(550);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(20);

                    			std::string oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data();
                    			OperationType op_type;

                    			if(oper == ">>")
                    				op_type = OperationType::RIGHT_SHIFT;
                    			else if (oper == "<<")
                    				op_type = OperationType::LEFT_SHIFT;

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,op_type};
                    		
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(553);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(554);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 567453553048682496) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(555);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(19);

                    			std::string oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data();
                    			OperationType basicType;

                    			if(oper == ">")
                    				basicType = OperationType::GT;
                    			else if (oper == ">=")
                    				basicType = OperationType::GE;
                    			else if (oper == "<")
                    				basicType = OperationType::LT;
                    			else if (oper == "<=")
                    				basicType = OperationType::LE;
                    			else if (oper == "==")
                    				basicType = OperationType::EQ;
                    			else if (oper == "!=")
                    				basicType = OperationType::NEQ;

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,basicType};
                    		
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(558);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(559);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__22);
          setState(560);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(18);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_AND};
                    		
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(563);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(564);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__58);
          setState(565);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(17);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_XOR};
                    		
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(568);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(569);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__59);
          setState(570);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(16);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_OR};
                    		
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(573);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(574);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__60);
          setState(575);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(15);

                    			_localctx->m_node = new AndNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(578);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(579);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__61);
          setState(580);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(14);

                    			_localctx->m_node = new OrNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left_expr = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(583);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(584);
          match(GrammarParser::T__14);
          setState(585);
          antlrcpp::downCast<ExprContext *>(_localctx)->right_expr = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(11);

                    			_localctx->m_node = new AssignmentNode{antlrcpp::downCast<ExprContext *>(_localctx)->left_expr->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right_expr->m_node};
                    		
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->array_id = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(588);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(589);
          match(GrammarParser::T__18);
          setState(590);
          antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
          setState(591);
          match(GrammarParser::T__19);

                    			_localctx->m_node = new ArrayAccessNode{antlrcpp::downCast<ExprContext *>(_localctx)->array_id->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
                    		
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->new_left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(594);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(595);
          match(GrammarParser::T__40);
          setState(596);
          antlrcpp::downCast<ExprContext *>(_localctx)->field = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
           // dotMemberAccess
                    			ReferencePtr<AbstractSyntaxTreeNode> expr_node = antlrcpp::downCast<ExprContext *>(_localctx)->new_left->m_node;
                    			ReferencePtr<IdentifierNode> field_id_node = antlrcpp::downCast<ExprContext *>(_localctx)->field->m_node.cast<IdentifierNode>(); 
                    			
                    			_localctx->m_node = new MemberAccessNode{expr_node,field_id_node,false};
                    		
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->new_left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(599);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(600);
          match(GrammarParser::T__41);
          setState(601);
          antlrcpp::downCast<ExprContext *>(_localctx)->field = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
           // arrowMemberAccess
                    			ReferencePtr<AbstractSyntaxTreeNode> expr_node = antlrcpp::downCast<ExprContext *>(_localctx)->new_left->m_node; 
                    			ReferencePtr<IdentifierNode> field_id_node = antlrcpp::downCast<ExprContext *>(_localctx)->field->m_node.cast<IdentifierNode>();
                    			
                    			_localctx->m_node = new MemberAccessNode{expr_node,field_id_node,true};
                    		
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(604);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(605);
          match(GrammarParser::T__42);

                    			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(607);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(608);
          match(GrammarParser::T__43);

                    			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        case 16: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left_expr = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(610);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(611);
          match(GrammarParser::T__14);
          setState(612);
          antlrcpp::downCast<ExprContext *>(_localctx)->initialization_list = initializationList();

                    			_localctx->m_node = new AssignmentNode{antlrcpp::downCast<ExprContext *>(_localctx)->left_expr->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->initialization_list->m_node};
                    		
          break;
        }

        default:
          break;
        } 
      }
      setState(619);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SelectContext ------------------------------------------------------------------

GrammarParser::SelectContext::SelectContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::ExprContext *> GrammarParser::SelectContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::SelectContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}


size_t GrammarParser::SelectContext::getRuleIndex() const {
  return GrammarParser::RuleSelect;
}

void GrammarParser::SelectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect(this);
}

void GrammarParser::SelectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect(this);
}

GrammarParser::SelectContext* GrammarParser::select() {
  SelectContext *_localctx = _tracker.createInstance<SelectContext>(_ctx, getState());
  enterRule(_localctx, 70, GrammarParser::RuleSelect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(620);
    match(GrammarParser::T__63);
    setState(621);
    match(GrammarParser::T__1);
    setState(622);
    antlrcpp::downCast<SelectContext *>(_localctx)->condition = expr(0);
    setState(623);
    match(GrammarParser::T__9);
    setState(624);
    antlrcpp::downCast<SelectContext *>(_localctx)->e_t = expr(0);
    setState(625);
    match(GrammarParser::T__9);
    setState(626);
    antlrcpp::downCast<SelectContext *>(_localctx)->e_f = expr(0);
    setState(627);
    match(GrammarParser::T__2);

    				_localctx->m_node = new SelectNode{antlrcpp::downCast<SelectContext *>(_localctx)->condition->m_node,antlrcpp::downCast<SelectContext *>(_localctx)->e_t->m_node,antlrcpp::downCast<SelectContext *>(_localctx)->e_f->m_node};
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

GrammarParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::NumberContext::INT() {
  return getToken(GrammarParser::INT, 0);
}

tree::TerminalNode* GrammarParser::NumberContext::HEX() {
  return getToken(GrammarParser::HEX, 0);
}

tree::TerminalNode* GrammarParser::NumberContext::BINARY() {
  return getToken(GrammarParser::BINARY, 0);
}

tree::TerminalNode* GrammarParser::NumberContext::OCTAL() {
  return getToken(GrammarParser::OCTAL, 0);
}

tree::TerminalNode* GrammarParser::NumberContext::FLOAT() {
  return getToken(GrammarParser::FLOAT, 0);
}

tree::TerminalNode* GrammarParser::NumberContext::DOUBLE() {
  return getToken(GrammarParser::DOUBLE, 0);
}

tree::TerminalNode* GrammarParser::NumberContext::BOOL() {
  return getToken(GrammarParser::BOOL, 0);
}


size_t GrammarParser::NumberContext::getRuleIndex() const {
  return GrammarParser::RuleNumber;
}

void GrammarParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void GrammarParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

GrammarParser::NumberContext* GrammarParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 72, GrammarParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(638);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INT:
      case GrammarParser::BINARY:
      case GrammarParser::OCTAL:
      case GrammarParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(630);
        antlrcpp::downCast<NumberContext *>(_localctx)->integerLiteral = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & 113) != 0))) {
          antlrcpp::downCast<NumberContext *>(_localctx)->integerLiteral = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
         
        				_localctx->m_node = m_parser_helper->parse_integer_literal(antlrcpp::downCast<NumberContext *>(_localctx)->integerLiteral->getText().data());
        			
        break;
      }

      case GrammarParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(632);
        antlrcpp::downCast<NumberContext *>(_localctx)->floatToken = match(GrammarParser::FLOAT);

        				_localctx -> m_node = new ConstantNode{(float) std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->floatToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::DOUBLE: {
        enterOuterAlt(_localctx, 3);
        setState(634);
        antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken = match(GrammarParser::DOUBLE);

        				_localctx -> m_node = new ConstantNode{ std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::BOOL: {
        enterOuterAlt(_localctx, 4);
        setState(636);
        antlrcpp::downCast<NumberContext *>(_localctx)->boolToken = match(GrammarParser::BOOL);

        				_localctx->m_node = new ConstantNode{ antlrcpp::downCast<NumberContext *>(_localctx)->boolToken -> getText() == "true" };
        			
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_literalContext ------------------------------------------------------------------

GrammarParser::String_literalContext::String_literalContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::String_literalContext::STRING_LITERAL() {
  return getToken(GrammarParser::STRING_LITERAL, 0);
}


size_t GrammarParser::String_literalContext::getRuleIndex() const {
  return GrammarParser::RuleString_literal;
}

void GrammarParser::String_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_literal(this);
}

void GrammarParser::String_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_literal(this);
}

GrammarParser::String_literalContext* GrammarParser::string_literal() {
  String_literalContext *_localctx = _tracker.createInstance<String_literalContext>(_ctx, getState());
  enterRule(_localctx, 74, GrammarParser::RuleString_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(640);
    antlrcpp::downCast<String_literalContext *>(_localctx)->stringLiteral = match(GrammarParser::STRING_LITERAL);

    				_localctx->m_node = m_parser_helper->parse_string_literal(antlrcpp::downCast<String_literalContext *>(_localctx)->stringLiteral->getText());
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Char_literalContext ------------------------------------------------------------------

GrammarParser::Char_literalContext::Char_literalContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Char_literalContext::CHAR_LITERAL() {
  return getToken(GrammarParser::CHAR_LITERAL, 0);
}


size_t GrammarParser::Char_literalContext::getRuleIndex() const {
  return GrammarParser::RuleChar_literal;
}

void GrammarParser::Char_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChar_literal(this);
}

void GrammarParser::Char_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChar_literal(this);
}

GrammarParser::Char_literalContext* GrammarParser::char_literal() {
  Char_literalContext *_localctx = _tracker.createInstance<Char_literalContext>(_ctx, getState());
  enterRule(_localctx, 76, GrammarParser::RuleChar_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(643);
    antlrcpp::downCast<Char_literalContext *>(_localctx)->charLiteral = match(GrammarParser::CHAR_LITERAL);

    				_localctx->m_node = m_parser_helper->parse_char_literal(antlrcpp::downCast<Char_literalContext *>(_localctx)->charLiteral->getText());
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

GrammarParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::IdentifierContext::ID() {
  return getToken(GrammarParser::ID, 0);
}


size_t GrammarParser::IdentifierContext::getRuleIndex() const {
  return GrammarParser::RuleIdentifier;
}

void GrammarParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void GrammarParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

GrammarParser::IdentifierContext* GrammarParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 78, GrammarParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(646);
    antlrcpp::downCast<IdentifierContext *>(_localctx)->idToken = match(GrammarParser::ID);

    				_localctx -> m_node = new IdentifierNode{ antlrcpp::downCast<IdentifierContext *>(_localctx)->idToken -> getText().data() };
    			
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool GrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 34: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GrammarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 21);
    case 1: return precpred(_ctx, 20);
    case 2: return precpred(_ctx, 19);
    case 3: return precpred(_ctx, 18);
    case 4: return precpred(_ctx, 17);
    case 5: return precpred(_ctx, 16);
    case 6: return precpred(_ctx, 15);
    case 7: return precpred(_ctx, 14);
    case 8: return precpred(_ctx, 13);
    case 9: return precpred(_ctx, 10);
    case 10: return precpred(_ctx, 33);
    case 11: return precpred(_ctx, 32);
    case 12: return precpred(_ctx, 31);
    case 13: return precpred(_ctx, 30);
    case 14: return precpred(_ctx, 28);
    case 15: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

void GrammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  grammarParserInitialize();
#else
  ::antlr4::internal::call_once(grammarParserOnceFlag, grammarParserInitialize);
#endif
}
