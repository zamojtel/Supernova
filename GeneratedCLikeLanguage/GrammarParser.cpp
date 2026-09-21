
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
      "expr", "select", "number", "string_literal", "char_literal", "identifier"
    },
    std::vector<std::string>{
      "", "'while'", "'('", "')'", "'do'", "';'", "'for'", "'if'", "'else'", 
      "'inline'", "','", "'{'", "'}'", "'print'", "'print_type'", "'memcpy'", 
      "'='", "'struct'", "'union'", "'*'", "'['", "']'", "'const'", "'volatile'", 
      "'&'", "'int'", "'int8'", "'int16'", "'int32'", "'int64'", "'uint8'", 
      "'uint16'", "'uint32'", "'uint64'", "'float'", "'double'", "'bool'", 
      "'void'", "'char'", "'return'", "'sizeof'", "'assert'", "'.'", "'->'", 
      "'++'", "'--'", "'-'", "'~'", "'!'", "'/'", "'%'", "'+'", "'>>'", 
      "'<<'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'^'", "'|'", 
      "'&&'", "'||'", "'reinterpret_cast'", "'malloc'", "'free'", "'select'", 
      "", "", "", "", "", "", "", "", "", "'continue'", "'break'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "LINE_COMMENT", "WS", "INT", "FLOAT", "DOUBLE", "BOOL", "BINARY", 
      "OCTAL", "HEX", "CONTINUE", "BREAK", "ID", "STRING_LITERAL", "CHAR_LITERAL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,81,577,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,0,1,0,1,0,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,100,8,3,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,3,4,109,8,4,1,4,1,4,1,5,5,5,114,8,5,10,5,12,5,117,9,5,1,5,1,5,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,136,8,6,
  	1,7,3,7,139,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,5,8,152,8,
  	8,10,8,12,8,155,9,8,3,8,157,8,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	3,10,168,8,10,1,10,1,10,1,10,1,11,1,11,1,11,5,11,176,8,11,10,11,12,11,
  	179,9,11,1,11,1,11,1,12,1,12,5,12,185,8,12,10,12,12,12,188,9,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,254,8,13,1,14,1,14,5,14,258,8,
  	14,10,14,12,14,261,9,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,16,
  	1,16,1,16,1,16,5,16,275,8,16,10,16,12,16,278,9,16,1,16,1,16,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,291,8,17,1,18,1,18,1,18,1,18,
  	1,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,309,
  	8,20,1,21,1,21,5,21,313,8,21,10,21,12,21,316,9,21,1,21,1,21,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,333,8,22,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	3,23,363,8,23,1,24,1,24,3,24,367,8,24,1,24,1,24,1,24,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,469,8,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,5,27,543,8,27,10,27,12,27,546,9,27,1,28,1,28,1,28,1,28,1,28,1,28,1,
  	28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,566,8,
  	29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,32,0,1,54,33,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,
  	54,56,58,60,62,64,0,5,2,0,19,19,49,50,2,0,46,46,51,51,1,0,52,53,1,0,54,
  	59,2,0,70,70,74,76,628,0,66,1,0,0,0,2,73,1,0,0,0,4,82,1,0,0,0,6,99,1,
  	0,0,0,8,101,1,0,0,0,10,115,1,0,0,0,12,135,1,0,0,0,14,138,1,0,0,0,16,156,
  	1,0,0,0,18,160,1,0,0,0,20,164,1,0,0,0,22,172,1,0,0,0,24,182,1,0,0,0,26,
  	253,1,0,0,0,28,255,1,0,0,0,30,265,1,0,0,0,32,270,1,0,0,0,34,290,1,0,0,
  	0,36,292,1,0,0,0,38,297,1,0,0,0,40,308,1,0,0,0,42,310,1,0,0,0,44,332,
  	1,0,0,0,46,362,1,0,0,0,48,364,1,0,0,0,50,371,1,0,0,0,52,377,1,0,0,0,54,
  	468,1,0,0,0,56,547,1,0,0,0,58,565,1,0,0,0,60,567,1,0,0,0,62,570,1,0,0,
  	0,64,573,1,0,0,0,66,67,5,1,0,0,67,68,5,2,0,0,68,69,3,54,27,0,69,70,5,
  	3,0,0,70,71,3,26,13,0,71,72,6,0,-1,0,72,1,1,0,0,0,73,74,5,4,0,0,74,75,
  	3,26,13,0,75,76,5,1,0,0,76,77,5,2,0,0,77,78,3,54,27,0,78,79,5,3,0,0,79,
  	80,5,5,0,0,80,81,6,1,-1,0,81,3,1,0,0,0,82,83,5,6,0,0,83,84,5,2,0,0,84,
  	85,3,6,3,0,85,86,5,5,0,0,86,87,3,54,27,0,87,88,5,5,0,0,88,89,3,54,27,
  	0,89,90,5,3,0,0,90,91,3,26,13,0,91,92,6,2,-1,0,92,5,1,0,0,0,93,94,3,32,
  	16,0,94,95,6,3,-1,0,95,100,1,0,0,0,96,97,3,54,27,0,97,98,6,3,-1,0,98,
  	100,1,0,0,0,99,93,1,0,0,0,99,96,1,0,0,0,100,7,1,0,0,0,101,102,5,7,0,0,
  	102,103,5,2,0,0,103,104,3,54,27,0,104,105,5,3,0,0,105,108,3,26,13,0,106,
  	107,5,8,0,0,107,109,3,26,13,0,108,106,1,0,0,0,108,109,1,0,0,0,109,110,
  	1,0,0,0,110,111,6,4,-1,0,111,9,1,0,0,0,112,114,3,12,6,0,113,112,1,0,0,
  	0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,118,1,0,0,0,117,
  	115,1,0,0,0,118,119,6,5,-1,0,119,11,1,0,0,0,120,121,3,14,7,0,121,122,
  	6,6,-1,0,122,136,1,0,0,0,123,124,3,32,16,0,124,125,5,5,0,0,125,126,6,
  	6,-1,0,126,136,1,0,0,0,127,128,3,38,19,0,128,129,5,5,0,0,129,130,6,6,
  	-1,0,130,136,1,0,0,0,131,132,3,36,18,0,132,133,5,5,0,0,133,134,6,6,-1,
  	0,134,136,1,0,0,0,135,120,1,0,0,0,135,123,1,0,0,0,135,127,1,0,0,0,135,
  	131,1,0,0,0,136,13,1,0,0,0,137,139,5,9,0,0,138,137,1,0,0,0,138,139,1,
  	0,0,0,139,140,1,0,0,0,140,141,3,42,21,0,141,142,3,64,32,0,142,143,5,2,
  	0,0,143,144,3,16,8,0,144,145,5,3,0,0,145,146,3,24,12,0,146,147,6,7,-1,
  	0,147,15,1,0,0,0,148,153,3,18,9,0,149,150,5,10,0,0,150,152,3,18,9,0,151,
  	149,1,0,0,0,152,155,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,157,1,
  	0,0,0,155,153,1,0,0,0,156,148,1,0,0,0,156,157,1,0,0,0,157,158,1,0,0,0,
  	158,159,6,8,-1,0,159,17,1,0,0,0,160,161,3,42,21,0,161,162,3,64,32,0,162,
  	163,6,9,-1,0,163,19,1,0,0,0,164,165,3,64,32,0,165,167,5,2,0,0,166,168,
  	3,22,11,0,167,166,1,0,0,0,167,168,1,0,0,0,168,169,1,0,0,0,169,170,5,3,
  	0,0,170,171,6,10,-1,0,171,21,1,0,0,0,172,177,3,54,27,0,173,174,5,10,0,
  	0,174,176,3,54,27,0,175,173,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,
  	178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,0,180,181,6,11,-1,0,181,23,
  	1,0,0,0,182,186,5,11,0,0,183,185,3,26,13,0,184,183,1,0,0,0,185,188,1,
  	0,0,0,186,184,1,0,0,0,186,187,1,0,0,0,187,189,1,0,0,0,188,186,1,0,0,0,
  	189,190,5,12,0,0,190,191,6,12,-1,0,191,25,1,0,0,0,192,193,3,32,16,0,193,
  	194,5,5,0,0,194,195,6,13,-1,0,195,254,1,0,0,0,196,197,3,20,10,0,197,198,
  	5,5,0,0,198,199,6,13,-1,0,199,254,1,0,0,0,200,201,3,48,24,0,201,202,6,
  	13,-1,0,202,254,1,0,0,0,203,204,3,8,4,0,204,205,6,13,-1,0,205,254,1,0,
  	0,0,206,207,3,0,0,0,207,208,6,13,-1,0,208,254,1,0,0,0,209,210,3,4,2,0,
  	210,211,6,13,-1,0,211,254,1,0,0,0,212,213,3,2,1,0,213,214,6,13,-1,0,214,
  	254,1,0,0,0,215,216,3,24,12,0,216,217,6,13,-1,0,217,254,1,0,0,0,218,219,
  	5,78,0,0,219,220,5,5,0,0,220,254,6,13,-1,0,221,222,5,77,0,0,222,223,5,
  	5,0,0,223,254,6,13,-1,0,224,225,5,13,0,0,225,226,5,2,0,0,226,227,3,54,
  	27,0,227,228,5,3,0,0,228,229,5,5,0,0,229,230,6,13,-1,0,230,254,1,0,0,
  	0,231,232,5,14,0,0,232,233,5,2,0,0,233,234,3,54,27,0,234,235,5,3,0,0,
  	235,236,5,5,0,0,236,237,6,13,-1,0,237,254,1,0,0,0,238,239,5,15,0,0,239,
  	240,5,2,0,0,240,241,3,54,27,0,241,242,5,10,0,0,242,243,3,54,27,0,243,
  	244,5,10,0,0,244,245,3,54,27,0,245,246,5,3,0,0,246,247,5,5,0,0,247,248,
  	6,13,-1,0,248,254,1,0,0,0,249,250,3,54,27,0,250,251,5,5,0,0,251,252,6,
  	13,-1,0,252,254,1,0,0,0,253,192,1,0,0,0,253,196,1,0,0,0,253,200,1,0,0,
  	0,253,203,1,0,0,0,253,206,1,0,0,0,253,209,1,0,0,0,253,212,1,0,0,0,253,
  	215,1,0,0,0,253,218,1,0,0,0,253,221,1,0,0,0,253,224,1,0,0,0,253,231,1,
  	0,0,0,253,238,1,0,0,0,253,249,1,0,0,0,254,27,1,0,0,0,255,259,5,11,0,0,
  	256,258,3,30,15,0,257,256,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,
  	260,1,0,0,0,260,262,1,0,0,0,261,259,1,0,0,0,262,263,5,12,0,0,263,264,
  	6,14,-1,0,264,29,1,0,0,0,265,266,3,42,21,0,266,267,3,64,32,0,267,268,
  	5,5,0,0,268,269,6,15,-1,0,269,31,1,0,0,0,270,271,3,42,21,0,271,276,3,
  	34,17,0,272,273,5,10,0,0,273,275,3,34,17,0,274,272,1,0,0,0,275,278,1,
  	0,0,0,276,274,1,0,0,0,276,277,1,0,0,0,277,279,1,0,0,0,278,276,1,0,0,0,
  	279,280,6,16,-1,0,280,33,1,0,0,0,281,282,3,64,32,0,282,283,6,17,-1,0,
  	283,291,1,0,0,0,284,285,3,64,32,0,285,286,5,16,0,0,286,287,3,54,27,0,
  	287,288,1,0,0,0,288,289,6,17,-1,0,289,291,1,0,0,0,290,281,1,0,0,0,290,
  	284,1,0,0,0,291,35,1,0,0,0,292,293,5,17,0,0,293,294,3,64,32,0,294,295,
  	3,28,14,0,295,296,6,18,-1,0,296,37,1,0,0,0,297,298,5,18,0,0,298,299,3,
  	64,32,0,299,300,3,28,14,0,300,301,6,19,-1,0,301,39,1,0,0,0,302,303,3,
  	46,23,0,303,304,6,20,-1,0,304,309,1,0,0,0,305,306,3,64,32,0,306,307,6,
  	20,-1,0,307,309,1,0,0,0,308,302,1,0,0,0,308,305,1,0,0,0,309,41,1,0,0,
  	0,310,314,3,40,20,0,311,313,3,44,22,0,312,311,1,0,0,0,313,316,1,0,0,0,
  	314,312,1,0,0,0,314,315,1,0,0,0,315,317,1,0,0,0,316,314,1,0,0,0,317,318,
  	6,21,-1,0,318,43,1,0,0,0,319,320,5,19,0,0,320,333,6,22,-1,0,321,322,5,
  	20,0,0,322,323,3,54,27,0,323,324,5,21,0,0,324,325,6,22,-1,0,325,333,1,
  	0,0,0,326,327,5,22,0,0,327,333,6,22,-1,0,328,329,5,23,0,0,329,333,6,22,
  	-1,0,330,331,5,24,0,0,331,333,6,22,-1,0,332,319,1,0,0,0,332,321,1,0,0,
  	0,332,326,1,0,0,0,332,328,1,0,0,0,332,330,1,0,0,0,333,45,1,0,0,0,334,
  	335,5,25,0,0,335,363,6,23,-1,0,336,337,5,26,0,0,337,363,6,23,-1,0,338,
  	339,5,27,0,0,339,363,6,23,-1,0,340,341,5,28,0,0,341,363,6,23,-1,0,342,
  	343,5,29,0,0,343,363,6,23,-1,0,344,345,5,30,0,0,345,363,6,23,-1,0,346,
  	347,5,31,0,0,347,363,6,23,-1,0,348,349,5,32,0,0,349,363,6,23,-1,0,350,
  	351,5,33,0,0,351,363,6,23,-1,0,352,353,5,34,0,0,353,363,6,23,-1,0,354,
  	355,5,35,0,0,355,363,6,23,-1,0,356,357,5,36,0,0,357,363,6,23,-1,0,358,
  	359,5,37,0,0,359,363,6,23,-1,0,360,361,5,38,0,0,361,363,6,23,-1,0,362,
  	334,1,0,0,0,362,336,1,0,0,0,362,338,1,0,0,0,362,340,1,0,0,0,362,342,1,
  	0,0,0,362,344,1,0,0,0,362,346,1,0,0,0,362,348,1,0,0,0,362,350,1,0,0,0,
  	362,352,1,0,0,0,362,354,1,0,0,0,362,356,1,0,0,0,362,358,1,0,0,0,362,360,
  	1,0,0,0,363,47,1,0,0,0,364,366,5,39,0,0,365,367,3,54,27,0,366,365,1,0,
  	0,0,366,367,1,0,0,0,367,368,1,0,0,0,368,369,5,5,0,0,369,370,6,24,-1,0,
  	370,49,1,0,0,0,371,372,5,40,0,0,372,373,5,2,0,0,373,374,3,42,21,0,374,
  	375,5,3,0,0,375,376,6,25,-1,0,376,51,1,0,0,0,377,378,5,41,0,0,378,379,
  	5,2,0,0,379,380,3,54,27,0,380,381,5,3,0,0,381,382,6,26,-1,0,382,53,1,
  	0,0,0,383,384,6,27,-1,0,384,385,5,2,0,0,385,386,3,42,21,0,386,387,5,3,
  	0,0,387,388,3,54,27,35,388,389,6,27,-1,0,389,469,1,0,0,0,390,391,5,44,
  	0,0,391,392,3,54,27,30,392,393,6,27,-1,0,393,469,1,0,0,0,394,395,5,45,
  	0,0,395,396,3,54,27,28,396,397,6,27,-1,0,397,469,1,0,0,0,398,399,5,46,
  	0,0,399,400,3,54,27,27,400,401,6,27,-1,0,401,469,1,0,0,0,402,403,5,47,
  	0,0,403,404,3,54,27,26,404,405,6,27,-1,0,405,469,1,0,0,0,406,407,5,48,
  	0,0,407,408,3,54,27,25,408,409,6,27,-1,0,409,469,1,0,0,0,410,411,5,19,
  	0,0,411,412,3,54,27,24,412,413,6,27,-1,0,413,469,1,0,0,0,414,415,5,24,
  	0,0,415,416,3,54,27,23,416,417,6,27,-1,0,417,469,1,0,0,0,418,419,3,20,
  	10,0,419,420,6,27,-1,0,420,469,1,0,0,0,421,422,3,64,32,0,422,423,6,27,
  	-1,0,423,469,1,0,0,0,424,425,3,58,29,0,425,426,6,27,-1,0,426,469,1,0,
  	0,0,427,428,5,2,0,0,428,429,3,54,27,0,429,430,5,3,0,0,430,431,6,27,-1,
  	0,431,469,1,0,0,0,432,433,5,64,0,0,433,434,5,56,0,0,434,435,3,42,21,0,
  	435,436,5,54,0,0,436,437,5,2,0,0,437,438,3,54,27,0,438,439,5,3,0,0,439,
  	440,6,27,-1,0,440,469,1,0,0,0,441,442,3,50,25,0,442,443,6,27,-1,0,443,
  	469,1,0,0,0,444,445,3,52,26,0,445,446,6,27,-1,0,446,469,1,0,0,0,447,448,
  	3,56,28,0,448,449,6,27,-1,0,449,469,1,0,0,0,450,451,5,65,0,0,451,452,
  	5,2,0,0,452,453,3,54,27,0,453,454,5,3,0,0,454,455,6,27,-1,0,455,469,1,
  	0,0,0,456,457,5,66,0,0,457,458,5,2,0,0,458,459,3,54,27,0,459,460,5,3,
  	0,0,460,461,6,27,-1,0,461,469,1,0,0,0,462,463,3,60,30,0,463,464,6,27,
  	-1,0,464,469,1,0,0,0,465,466,3,62,31,0,466,467,6,27,-1,0,467,469,1,0,
  	0,0,468,383,1,0,0,0,468,390,1,0,0,0,468,394,1,0,0,0,468,398,1,0,0,0,468,
  	402,1,0,0,0,468,406,1,0,0,0,468,410,1,0,0,0,468,414,1,0,0,0,468,418,1,
  	0,0,0,468,421,1,0,0,0,468,424,1,0,0,0,468,427,1,0,0,0,468,432,1,0,0,0,
  	468,441,1,0,0,0,468,444,1,0,0,0,468,447,1,0,0,0,468,450,1,0,0,0,468,456,
  	1,0,0,0,468,462,1,0,0,0,468,465,1,0,0,0,469,544,1,0,0,0,470,471,10,22,
  	0,0,471,472,7,0,0,0,472,473,3,54,27,23,473,474,6,27,-1,0,474,543,1,0,
  	0,0,475,476,10,21,0,0,476,477,7,1,0,0,477,478,3,54,27,22,478,479,6,27,
  	-1,0,479,543,1,0,0,0,480,481,10,20,0,0,481,482,7,2,0,0,482,483,3,54,27,
  	21,483,484,6,27,-1,0,484,543,1,0,0,0,485,486,10,19,0,0,486,487,7,3,0,
  	0,487,488,3,54,27,20,488,489,6,27,-1,0,489,543,1,0,0,0,490,491,10,18,
  	0,0,491,492,5,24,0,0,492,493,3,54,27,19,493,494,6,27,-1,0,494,543,1,0,
  	0,0,495,496,10,17,0,0,496,497,5,60,0,0,497,498,3,54,27,18,498,499,6,27,
  	-1,0,499,543,1,0,0,0,500,501,10,16,0,0,501,502,5,61,0,0,502,503,3,54,
  	27,17,503,504,6,27,-1,0,504,543,1,0,0,0,505,506,10,15,0,0,506,507,5,62,
  	0,0,507,508,3,54,27,16,508,509,6,27,-1,0,509,543,1,0,0,0,510,511,10,14,
  	0,0,511,512,5,63,0,0,512,513,3,54,27,15,513,514,6,27,-1,0,514,543,1,0,
  	0,0,515,516,10,11,0,0,516,517,5,16,0,0,517,518,3,54,27,12,518,519,6,27,
  	-1,0,519,543,1,0,0,0,520,521,10,34,0,0,521,522,5,20,0,0,522,523,3,54,
  	27,0,523,524,5,21,0,0,524,525,6,27,-1,0,525,543,1,0,0,0,526,527,10,33,
  	0,0,527,528,5,42,0,0,528,529,3,64,32,0,529,530,6,27,-1,0,530,543,1,0,
  	0,0,531,532,10,32,0,0,532,533,5,43,0,0,533,534,3,64,32,0,534,535,6,27,
  	-1,0,535,543,1,0,0,0,536,537,10,31,0,0,537,538,5,44,0,0,538,543,6,27,
  	-1,0,539,540,10,29,0,0,540,541,5,45,0,0,541,543,6,27,-1,0,542,470,1,0,
  	0,0,542,475,1,0,0,0,542,480,1,0,0,0,542,485,1,0,0,0,542,490,1,0,0,0,542,
  	495,1,0,0,0,542,500,1,0,0,0,542,505,1,0,0,0,542,510,1,0,0,0,542,515,1,
  	0,0,0,542,520,1,0,0,0,542,526,1,0,0,0,542,531,1,0,0,0,542,536,1,0,0,0,
  	542,539,1,0,0,0,543,546,1,0,0,0,544,542,1,0,0,0,544,545,1,0,0,0,545,55,
  	1,0,0,0,546,544,1,0,0,0,547,548,5,67,0,0,548,549,5,2,0,0,549,550,3,54,
  	27,0,550,551,5,10,0,0,551,552,3,54,27,0,552,553,5,10,0,0,553,554,3,54,
  	27,0,554,555,5,3,0,0,555,556,6,28,-1,0,556,57,1,0,0,0,557,558,7,4,0,0,
  	558,566,6,29,-1,0,559,560,5,71,0,0,560,566,6,29,-1,0,561,562,5,72,0,0,
  	562,566,6,29,-1,0,563,564,5,73,0,0,564,566,6,29,-1,0,565,557,1,0,0,0,
  	565,559,1,0,0,0,565,561,1,0,0,0,565,563,1,0,0,0,566,59,1,0,0,0,567,568,
  	5,80,0,0,568,569,6,30,-1,0,569,61,1,0,0,0,570,571,5,81,0,0,571,572,6,
  	31,-1,0,572,63,1,0,0,0,573,574,5,79,0,0,574,575,6,32,-1,0,575,65,1,0,
  	0,0,23,99,108,115,135,138,153,156,167,177,186,253,259,276,290,308,314,
  	332,362,366,468,542,544,565
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
    setState(66);
    match(GrammarParser::T__0);
    setState(67);
    match(GrammarParser::T__1);
    setState(68);
    antlrcpp::downCast<WhileContext *>(_localctx)->exprContext = expr(0);
    setState(69);
    match(GrammarParser::T__2);
    setState(70);
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
    setState(73);
    match(GrammarParser::T__3);
    setState(74);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->stmtContext = stmt();
    setState(75);
    match(GrammarParser::T__0);
    setState(76);
    match(GrammarParser::T__1);
    setState(77);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->exprContext = expr(0);
    setState(78);
    match(GrammarParser::T__2);
    setState(79);
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
    setState(82);
    match(GrammarParser::T__5);
    setState(83);
    match(GrammarParser::T__1);
    setState(84);
    antlrcpp::downCast<ForContext *>(_localctx)->initStatmentsContext = initStatments();
    setState(85);
    match(GrammarParser::T__4);

    setState(86);
    antlrcpp::downCast<ForContext *>(_localctx)->condition = antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(87);
    match(GrammarParser::T__4);
    setState(88);
    antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(89);
    match(GrammarParser::T__2);
    setState(90);
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
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext = declaration();

      				_localctx->m_node = antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
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
    setState(101);
    match(GrammarParser::T__6);
    setState(102);
    match(GrammarParser::T__1);
    setState(103);
    antlrcpp::downCast<IfContext *>(_localctx)->exprContext = expr(0);
    setState(104);
    match(GrammarParser::T__2);
    setState(105);
    antlrcpp::downCast<IfContext *>(_localctx)->stmt_1 = stmt();
    setState(108);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(106);
      match(GrammarParser::T__7);
      setState(107);
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
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 549722653184) != 0) || _la == GrammarParser::ID) {
      setState(112);
      antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext = progElement();
      antlrcpp::downCast<ProgContext *>(_localctx)->items.push_back(antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext);
      setState(117);
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
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext = function();

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext->m_node;	
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(123);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext = declaration();
      setState(124);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(127);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext = unionDecl();
      setState(128);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(131);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->structDeclContext = structDecl();
      setState(132);
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
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T__8) {
      setState(137);
      antlrcpp::downCast<FunctionContext *>(_localctx)->inline_keyword = match(GrammarParser::T__8);
    }
    setState(140);
    antlrcpp::downCast<FunctionContext *>(_localctx)->dataTypeContext = dataType();
    setState(141);
    antlrcpp::downCast<FunctionContext *>(_localctx)->identifierContext = identifier();
    setState(142);
    match(GrammarParser::T__1);
    setState(143);
    antlrcpp::downCast<FunctionContext *>(_localctx)->functionParametersContext = functionParameters();
    setState(144);
    match(GrammarParser::T__2);
    setState(145);
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
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & 18014398509498367) != 0)) {
      setState(148);
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::T__9) {
        setState(149);
        match(GrammarParser::T__9);
        setState(150);
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
        setState(155);
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
    setState(160);
    antlrcpp::downCast<FunctionParameterContext *>(_localctx)->dataTypeContext = dataType();
    setState(161);
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
    setState(164);
    antlrcpp::downCast<FunctionCallContext *>(_localctx)->identifierContext = identifier();
    setState(165);
    match(GrammarParser::T__1);
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 548656319561732) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 237519) != 0)) {
      setState(166);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->argumentListContext = argumentList();
    }
    setState(169);
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
    setState(172);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(173);
      match(GrammarParser::T__9);
      setState(174);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
      setState(179);
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
    setState(182);
    match(GrammarParser::T__10);
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 549755797694678) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 262095) != 0)) {
      setState(183);
      antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext = stmt();
      antlrcpp::downCast<BlockContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(189);
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

std::vector<GrammarParser::ExprContext *> GrammarParser::StmtContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::StmtContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
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
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext = declaration();
      setState(193);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(196);
      antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext = functionCall();
      setState(197);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(200);
      antlrcpp::downCast<StmtContext *>(_localctx)->returnContext = return_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->returnContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(203);
      antlrcpp::downCast<StmtContext *>(_localctx)->ifContext = if_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->ifContext->m_node;
      			
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(206);
      antlrcpp::downCast<StmtContext *>(_localctx)->whileContext = while_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->whileContext->m_node;
      			
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(209);
      antlrcpp::downCast<StmtContext *>(_localctx)->forContext = for_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->forContext->m_node;
      			
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(212);
      antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext = doWhile();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext->m_node;
      			
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(215);
      antlrcpp::downCast<StmtContext *>(_localctx)->blockContext = block();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->blockContext->m_node;
      			
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(218);
      match(GrammarParser::BREAK);
      setState(219);
      match(GrammarParser::T__4);

      				_localctx->m_node = new BreakNode{};
      			
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(221);
      match(GrammarParser::CONTINUE);
      setState(222);
      match(GrammarParser::T__4);

      				_localctx->m_node = new ContinueNode{};
      			
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(224);
      match(GrammarParser::T__12);
      setState(225);
      match(GrammarParser::T__1);
      setState(226);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(227);
      match(GrammarParser::T__2);
      setState(228);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(231);
      match(GrammarParser::T__13);
      setState(232);
      match(GrammarParser::T__1);
      setState(233);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(234);
      match(GrammarParser::T__2);
      setState(235);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintTypeNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(238);
      match(GrammarParser::T__14);
      setState(239);
      match(GrammarParser::T__1);
      setState(240);
      antlrcpp::downCast<StmtContext *>(_localctx)->e1 = expr(0);
      setState(241);
      match(GrammarParser::T__9);
      setState(242);
      antlrcpp::downCast<StmtContext *>(_localctx)->e2 = expr(0);
      setState(243);
      match(GrammarParser::T__9);
      setState(244);
      antlrcpp::downCast<StmtContext *>(_localctx)->e3 = expr(0);
      setState(245);
      match(GrammarParser::T__2);
      setState(246);
      match(GrammarParser::T__4);

      				_localctx->m_node = new MemcpyNode{
      					antlrcpp::downCast<StmtContext *>(_localctx)->e1->m_node,
      					antlrcpp::downCast<StmtContext *>(_localctx)->e2->m_node,
      					antlrcpp::downCast<StmtContext *>(_localctx)->e3->m_node,
      				};
      			
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(249);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(250);
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
    setState(255);
    match(GrammarParser::T__10);
    setState(259);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & 18014398509498367) != 0)) {
      setState(256);
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext = memberDecl();
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext);
      setState(261);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(262);
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
    setState(265);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->dataTypeContext = dataType();
    setState(266);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->identifierContext = identifier();
    setState(267);
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
    setState(270);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->dataTypeContext = dataType();
    setState(271);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
    antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
    setState(276);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(272);
      match(GrammarParser::T__9);
      setState(273);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
      antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
      setState(278);
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
    setState(290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(281);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			_localctx -> m_node = new DeclarationListItemNode{in};
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(284);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();
      setState(285);
      match(GrammarParser::T__15);
      setState(286);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->exprContext = expr(0);

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			ReferencePtr<AbstractSyntaxTreeNode> expr = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->exprContext->m_node;
      			_localctx->m_node = new DeclarationListItemNode{in,expr};
      		
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
    setState(292);
    match(GrammarParser::T__16);
    setState(293);
    antlrcpp::downCast<StructDeclContext *>(_localctx)->identifierContext = identifier();
    setState(294);
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
    setState(297);
    match(GrammarParser::T__17);
    setState(298);
    antlrcpp::downCast<UnionDeclContext *>(_localctx)->identifierContext = identifier();
    setState(299);
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
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case GrammarParser::T__36:
      case GrammarParser::T__37: {
        enterOuterAlt(_localctx, 1);
        setState(302);
        antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext = basicType();
         _localctx->m_node = antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext->m_node; 
        break;
      }

      case GrammarParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(305);
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
    setState(310);
    antlrcpp::downCast<DataTypeContext *>(_localctx)->ft = fundamentalType();
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30932992) != 0)) {
      setState(311);
      antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext = typeModifier();
      antlrcpp::downCast<DataTypeContext *>(_localctx)->modifier_list.push_back(antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext);
      setState(316);
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
    setState(332);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__18: {
        enterOuterAlt(_localctx, 1);
        setState(319);
        match(GrammarParser::T__18);
        _localctx->m_node = new PointerNode{}; 
        break;
      }

      case GrammarParser::T__19: {
        enterOuterAlt(_localctx, 2);
        setState(321);
        match(GrammarParser::T__19);

        setState(322);
        antlrcpp::downCast<TypeModifierContext *>(_localctx)->e = expr(0);
        setState(323);
        match(GrammarParser::T__20);
         _localctx->m_node = new ArrayNode{ antlrcpp::downCast<TypeModifierContext *>(_localctx)->e->m_node }; 
        break;
      }

      case GrammarParser::T__21: {
        enterOuterAlt(_localctx, 3);
        setState(326);
        match(GrammarParser::T__21);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::CONST}; 
        break;
      }

      case GrammarParser::T__22: {
        enterOuterAlt(_localctx, 4);
        setState(328);
        match(GrammarParser::T__22);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::VOLATILE}; 
        break;
      }

      case GrammarParser::T__23: {
        enterOuterAlt(_localctx, 5);
        setState(330);
        match(GrammarParser::T__23);
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
    setState(362);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__24: {
        enterOuterAlt(_localctx, 1);
        setState(334);
        match(GrammarParser::T__24);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__25: {
        enterOuterAlt(_localctx, 2);
        setState(336);
        match(GrammarParser::T__25);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT8}; 
        break;
      }

      case GrammarParser::T__26: {
        enterOuterAlt(_localctx, 3);
        setState(338);
        match(GrammarParser::T__26);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT16}; 
        break;
      }

      case GrammarParser::T__27: {
        enterOuterAlt(_localctx, 4);
        setState(340);
        match(GrammarParser::T__27);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__28: {
        enterOuterAlt(_localctx, 5);
        setState(342);
        match(GrammarParser::T__28);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT64}; 
        break;
      }

      case GrammarParser::T__29: {
        enterOuterAlt(_localctx, 6);
        setState(344);
        match(GrammarParser::T__29);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT8}; 
        break;
      }

      case GrammarParser::T__30: {
        enterOuterAlt(_localctx, 7);
        setState(346);
        match(GrammarParser::T__30);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT16}; 
        break;
      }

      case GrammarParser::T__31: {
        enterOuterAlt(_localctx, 8);
        setState(348);
        match(GrammarParser::T__31);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT32}; 
        break;
      }

      case GrammarParser::T__32: {
        enterOuterAlt(_localctx, 9);
        setState(350);
        match(GrammarParser::T__32);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT64}; 
        break;
      }

      case GrammarParser::T__33: {
        enterOuterAlt(_localctx, 10);
        setState(352);
        match(GrammarParser::T__33);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::FLOAT}; 
        break;
      }

      case GrammarParser::T__34: {
        enterOuterAlt(_localctx, 11);
        setState(354);
        match(GrammarParser::T__34);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::DOUBLE}; 
        break;
      }

      case GrammarParser::T__35: {
        enterOuterAlt(_localctx, 12);
        setState(356);
        match(GrammarParser::T__35);
         _localctx->m_node = new BasicTypeNode{IRBasicType::BOOL}; 
        break;
      }

      case GrammarParser::T__36: {
        enterOuterAlt(_localctx, 13);
        setState(358);
        match(GrammarParser::T__36);
         _localctx->m_node = new BasicTypeNode{IRBasicType::VOID}; 
        break;
      }

      case GrammarParser::T__37: {
        enterOuterAlt(_localctx, 14);
        setState(360);
        match(GrammarParser::T__37);
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
    setState(364);
    match(GrammarParser::T__38);
    setState(366);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 548656319561732) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 237519) != 0)) {
      setState(365);
      antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext = expr(0);
    }
    setState(368);
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
    setState(371);
    match(GrammarParser::T__39);
    setState(372);
    match(GrammarParser::T__1);
    setState(373);
    antlrcpp::downCast<SizeOfContext *>(_localctx)->dataTypeContext = dataType();
    setState(374);
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
    setState(377);
    match(GrammarParser::T__40);
    setState(378);
    match(GrammarParser::T__1);
    setState(379);
    antlrcpp::downCast<AssertConditionContext *>(_localctx)->exprContext = expr(0);
    setState(380);
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
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, GrammarParser::RuleExpr, precedence);

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
    setState(468);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(384);
      match(GrammarParser::T__1);
      setState(385);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(386);
      match(GrammarParser::T__2);
      setState(387);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(35);

      			_localctx->m_node = new CastNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 2: {
      setState(390);
      match(GrammarParser::T__43);
      setState(391);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(30);

      			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 3: {
      setState(394);
      match(GrammarParser::T__44);
      setState(395);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(28);

      			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 4: {
      setState(398);
      match(GrammarParser::T__45);
      setState(399);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(27);

      			_localctx->m_node = new UnaryMinusNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 5: {
      setState(402);
      match(GrammarParser::T__46);
      setState(403);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(26);

      			_localctx->m_node = new BitwiseNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 6: {
      setState(406);
      match(GrammarParser::T__47);
      setState(407);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(25);

      			_localctx->m_node = new BooleanNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 7: {
      setState(410);
      match(GrammarParser::T__18);
      setState(411);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(24);

      			_localctx->m_node = new DereferenceNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 8: {
      setState(414);
      match(GrammarParser::T__23);
      setState(415);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(23);

      			_localctx->m_node = new AddressOfNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 9: {
      setState(418);
      antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext = functionCall();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext->m_node; 
      break;
    }

    case 10: {
      setState(421);
      antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext->m_node; 
      break;
    }

    case 11: {
      setState(424);
      antlrcpp::downCast<ExprContext *>(_localctx)->numberContext = number();
       _localctx -> m_node = antlrcpp::downCast<ExprContext *>(_localctx)->numberContext->m_node; 
      break;
    }

    case 12: {
      setState(427);
      match(GrammarParser::T__1);
      setState(428);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(429);
      match(GrammarParser::T__2);
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node; 
      break;
    }

    case 13: {
      setState(432);
      match(GrammarParser::T__63);
      setState(433);
      match(GrammarParser::T__55);
      setState(434);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(435);
      match(GrammarParser::T__53);
      setState(436);
      match(GrammarParser::T__1);
      setState(437);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(438);
      match(GrammarParser::T__2);

      			_localctx->m_node = new ReinterpretNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 14: {
      setState(441);
      antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext = sizeOf();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext->m_node; 
      break;
    }

    case 15: {
      setState(444);
      antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext = assertCondition();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext->m_node; 
      break;
    }

    case 16: {
      setState(447);
      antlrcpp::downCast<ExprContext *>(_localctx)->selectContext = select();

      			_localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->selectContext->m_node;
      		
      break;
    }

    case 17: {
      setState(450);
      match(GrammarParser::T__64);
      setState(451);
      match(GrammarParser::T__1);
      setState(452);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(453);
      match(GrammarParser::T__2);

      			_localctx->m_node = new MallocNode(antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node);
      		
      break;
    }

    case 18: {
      setState(456);
      match(GrammarParser::T__65);
      setState(457);
      match(GrammarParser::T__1);
      setState(458);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(459);
      match(GrammarParser::T__2);

      			_localctx->m_node = new FreeNode(antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node);
      		
      break;
    }

    case 19: {
      setState(462);
      antlrcpp::downCast<ExprContext *>(_localctx)->string_literalContext = string_literal();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->string_literalContext->m_node; 
      break;
    }

    case 20: {
      setState(465);
      antlrcpp::downCast<ExprContext *>(_localctx)->char_literalContext = char_literal();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->char_literalContext->m_node; 
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(544);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(542);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(470);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(471);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1688849860788224) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(472);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(23);
           
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
          setState(475);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(476);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__45

          || _la == GrammarParser::T__50)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(477);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(22);

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
          setState(480);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(481);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__51

          || _la == GrammarParser::T__52)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(482);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(21);

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
          setState(485);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(486);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1134907106097364992) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(487);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(20);

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
          setState(490);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(491);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__23);
          setState(492);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(19);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_AND};
                    		
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(495);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(496);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__59);
          setState(497);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(18);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_XOR};
                    		
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(500);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(501);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__60);
          setState(502);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(17);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_OR};
                    		
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(505);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(506);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__61);
          setState(507);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(16);

                    			_localctx->m_node = new AndNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(510);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(511);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__62);
          setState(512);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(15);

                    			_localctx->m_node = new OrNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left_expr = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(515);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(516);
          match(GrammarParser::T__15);
          setState(517);
          antlrcpp::downCast<ExprContext *>(_localctx)->right_expr = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(12);

                    			_localctx->m_node = new AssignmentNode{antlrcpp::downCast<ExprContext *>(_localctx)->left_expr->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right_expr->m_node};
                    		
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->array_id = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(520);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(521);
          match(GrammarParser::T__19);
          setState(522);
          antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
          setState(523);
          match(GrammarParser::T__20);

                    			_localctx->m_node = new ArrayAccessNode{antlrcpp::downCast<ExprContext *>(_localctx)->array_id->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
                    		
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->new_left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(526);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(527);
          match(GrammarParser::T__41);
          setState(528);
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
          setState(531);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(532);
          match(GrammarParser::T__42);
          setState(533);
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
          setState(536);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(537);
          match(GrammarParser::T__43);

                    			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(539);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(540);
          match(GrammarParser::T__44);

                    			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        default:
          break;
        } 
      }
      setState(546);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
  enterRule(_localctx, 56, GrammarParser::RuleSelect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    match(GrammarParser::T__66);
    setState(548);
    match(GrammarParser::T__1);
    setState(549);
    antlrcpp::downCast<SelectContext *>(_localctx)->condition = expr(0);
    setState(550);
    match(GrammarParser::T__9);
    setState(551);
    antlrcpp::downCast<SelectContext *>(_localctx)->e_t = expr(0);
    setState(552);
    match(GrammarParser::T__9);
    setState(553);
    antlrcpp::downCast<SelectContext *>(_localctx)->e_f = expr(0);
    setState(554);
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
  enterRule(_localctx, 58, GrammarParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(565);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INT:
      case GrammarParser::BINARY:
      case GrammarParser::OCTAL:
      case GrammarParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(557);
        antlrcpp::downCast<NumberContext *>(_localctx)->integerLiteral = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 70) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 70)) & 113) != 0))) {
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
        setState(559);
        antlrcpp::downCast<NumberContext *>(_localctx)->floatToken = match(GrammarParser::FLOAT);

        				_localctx -> m_node = new ConstantNode{(float) std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->floatToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::DOUBLE: {
        enterOuterAlt(_localctx, 3);
        setState(561);
        antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken = match(GrammarParser::DOUBLE);

        				_localctx -> m_node = new ConstantNode{ std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::BOOL: {
        enterOuterAlt(_localctx, 4);
        setState(563);
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
  enterRule(_localctx, 60, GrammarParser::RuleString_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(567);
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
  enterRule(_localctx, 62, GrammarParser::RuleChar_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
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
  enterRule(_localctx, 64, GrammarParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
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
    case 27: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GrammarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 22);
    case 1: return precpred(_ctx, 21);
    case 2: return precpred(_ctx, 20);
    case 3: return precpred(_ctx, 19);
    case 4: return precpred(_ctx, 18);
    case 5: return precpred(_ctx, 17);
    case 6: return precpred(_ctx, 16);
    case 7: return precpred(_ctx, 15);
    case 8: return precpred(_ctx, 14);
    case 9: return precpred(_ctx, 11);
    case 10: return precpred(_ctx, 34);
    case 11: return precpred(_ctx, 33);
    case 12: return precpred(_ctx, 32);
    case 13: return precpred(_ctx, 31);
    case 14: return precpred(_ctx, 29);

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
