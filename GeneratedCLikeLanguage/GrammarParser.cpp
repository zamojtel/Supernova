
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
      "expr", "select", "number", "identifier"
    },
    std::vector<std::string>{
      "", "'while'", "'('", "')'", "'do'", "';'", "'for'", "'if'", "'else'", 
      "'inline'", "','", "'{'", "'}'", "'print'", "'print_type'", "'='", 
      "'struct'", "'union'", "'*'", "'['", "']'", "'const'", "'volatile'", 
      "'&'", "'int'", "'int8'", "'int16'", "'int32'", "'int64'", "'uint8'", 
      "'uint16'", "'uint32'", "'uint64'", "'float'", "'double'", "'bool'", 
      "'void'", "'return'", "'sizeof'", "'assert'", "'.'", "'->'", "'++'", 
      "'--'", "'-'", "'~'", "'!'", "'/'", "'%'", "'+'", "'>>'", "'<<'", 
      "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'^'", "'|'", "'&&'", 
      "'||'", "'reinterpret_cast'", "'malloc'", "'free'", "'select'", "", 
      "", "", "", "", "", "", "", "", "'continue'", "'break'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "LINE_COMMENT", 
      "WS", "INT", "FLOAT", "DOUBLE", "BOOL", "BINARY", "OCTAL", "HEX", 
      "CONTINUE", "BREAK", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,77,548,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,
  	1,3,1,3,1,3,1,3,3,3,96,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,105,8,4,1,
  	4,1,4,1,5,5,5,110,8,5,10,5,12,5,113,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,132,8,6,1,7,3,7,135,8,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,5,8,148,8,8,10,8,12,8,151,9,8,
  	3,8,153,8,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,3,10,164,8,10,1,10,
  	1,10,1,10,1,11,1,11,1,11,5,11,172,8,11,10,11,12,11,175,9,11,1,11,1,11,
  	1,12,1,12,5,12,181,8,12,10,12,12,12,184,9,12,1,12,1,12,1,12,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,3,13,239,8,13,1,14,1,14,5,14,243,8,14,10,
  	14,12,14,246,9,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,
  	16,1,16,5,16,260,8,16,10,16,12,16,263,9,16,1,16,1,16,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,3,17,276,8,17,1,18,1,18,1,18,1,18,1,18,1,
  	19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,294,8,20,1,
  	21,1,21,5,21,298,8,21,10,21,12,21,301,9,21,1,21,1,21,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,318,8,22,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,346,8,23,1,
  	24,1,24,3,24,350,8,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,
  	26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,3,27,446,8,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,5,27,520,8,27,10,27,12,27,523,9,27,1,28,1,
  	28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,29,3,29,543,8,29,1,30,1,30,1,30,1,30,0,1,54,31,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,
  	58,60,0,5,2,0,18,18,47,48,2,0,44,44,49,49,1,0,50,51,1,0,52,57,2,0,68,
  	68,72,74,597,0,62,1,0,0,0,2,69,1,0,0,0,4,78,1,0,0,0,6,95,1,0,0,0,8,97,
  	1,0,0,0,10,111,1,0,0,0,12,131,1,0,0,0,14,134,1,0,0,0,16,152,1,0,0,0,18,
  	156,1,0,0,0,20,160,1,0,0,0,22,168,1,0,0,0,24,178,1,0,0,0,26,238,1,0,0,
  	0,28,240,1,0,0,0,30,250,1,0,0,0,32,255,1,0,0,0,34,275,1,0,0,0,36,277,
  	1,0,0,0,38,282,1,0,0,0,40,293,1,0,0,0,42,295,1,0,0,0,44,317,1,0,0,0,46,
  	345,1,0,0,0,48,347,1,0,0,0,50,354,1,0,0,0,52,360,1,0,0,0,54,445,1,0,0,
  	0,56,524,1,0,0,0,58,542,1,0,0,0,60,544,1,0,0,0,62,63,5,1,0,0,63,64,5,
  	2,0,0,64,65,3,54,27,0,65,66,5,3,0,0,66,67,3,26,13,0,67,68,6,0,-1,0,68,
  	1,1,0,0,0,69,70,5,4,0,0,70,71,3,26,13,0,71,72,5,1,0,0,72,73,5,2,0,0,73,
  	74,3,54,27,0,74,75,5,3,0,0,75,76,5,5,0,0,76,77,6,1,-1,0,77,3,1,0,0,0,
  	78,79,5,6,0,0,79,80,5,2,0,0,80,81,3,6,3,0,81,82,5,5,0,0,82,83,3,54,27,
  	0,83,84,5,5,0,0,84,85,3,54,27,0,85,86,5,3,0,0,86,87,3,26,13,0,87,88,6,
  	2,-1,0,88,5,1,0,0,0,89,90,3,32,16,0,90,91,6,3,-1,0,91,96,1,0,0,0,92,93,
  	3,54,27,0,93,94,6,3,-1,0,94,96,1,0,0,0,95,89,1,0,0,0,95,92,1,0,0,0,96,
  	7,1,0,0,0,97,98,5,7,0,0,98,99,5,2,0,0,99,100,3,54,27,0,100,101,5,3,0,
  	0,101,104,3,26,13,0,102,103,5,8,0,0,103,105,3,26,13,0,104,102,1,0,0,0,
  	104,105,1,0,0,0,105,106,1,0,0,0,106,107,6,4,-1,0,107,9,1,0,0,0,108,110,
  	3,12,6,0,109,108,1,0,0,0,110,113,1,0,0,0,111,109,1,0,0,0,111,112,1,0,
  	0,0,112,114,1,0,0,0,113,111,1,0,0,0,114,115,6,5,-1,0,115,11,1,0,0,0,116,
  	117,3,14,7,0,117,118,6,6,-1,0,118,132,1,0,0,0,119,120,3,32,16,0,120,121,
  	5,5,0,0,121,122,6,6,-1,0,122,132,1,0,0,0,123,124,3,38,19,0,124,125,5,
  	5,0,0,125,126,6,6,-1,0,126,132,1,0,0,0,127,128,3,36,18,0,128,129,5,5,
  	0,0,129,130,6,6,-1,0,130,132,1,0,0,0,131,116,1,0,0,0,131,119,1,0,0,0,
  	131,123,1,0,0,0,131,127,1,0,0,0,132,13,1,0,0,0,133,135,5,9,0,0,134,133,
  	1,0,0,0,134,135,1,0,0,0,135,136,1,0,0,0,136,137,3,42,21,0,137,138,3,60,
  	30,0,138,139,5,2,0,0,139,140,3,16,8,0,140,141,5,3,0,0,141,142,3,24,12,
  	0,142,143,6,7,-1,0,143,15,1,0,0,0,144,149,3,18,9,0,145,146,5,10,0,0,146,
  	148,3,18,9,0,147,145,1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,150,
  	1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,0,152,144,1,0,0,0,152,153,1,0,0,
  	0,153,154,1,0,0,0,154,155,6,8,-1,0,155,17,1,0,0,0,156,157,3,42,21,0,157,
  	158,3,60,30,0,158,159,6,9,-1,0,159,19,1,0,0,0,160,161,3,60,30,0,161,163,
  	5,2,0,0,162,164,3,22,11,0,163,162,1,0,0,0,163,164,1,0,0,0,164,165,1,0,
  	0,0,165,166,5,3,0,0,166,167,6,10,-1,0,167,21,1,0,0,0,168,173,3,54,27,
  	0,169,170,5,10,0,0,170,172,3,54,27,0,171,169,1,0,0,0,172,175,1,0,0,0,
  	173,171,1,0,0,0,173,174,1,0,0,0,174,176,1,0,0,0,175,173,1,0,0,0,176,177,
  	6,11,-1,0,177,23,1,0,0,0,178,182,5,11,0,0,179,181,3,26,13,0,180,179,1,
  	0,0,0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,185,1,0,0,0,
  	184,182,1,0,0,0,185,186,5,12,0,0,186,187,6,12,-1,0,187,25,1,0,0,0,188,
  	189,3,32,16,0,189,190,5,5,0,0,190,191,6,13,-1,0,191,239,1,0,0,0,192,193,
  	3,20,10,0,193,194,5,5,0,0,194,195,6,13,-1,0,195,239,1,0,0,0,196,197,3,
  	48,24,0,197,198,6,13,-1,0,198,239,1,0,0,0,199,200,3,8,4,0,200,201,6,13,
  	-1,0,201,239,1,0,0,0,202,203,3,0,0,0,203,204,6,13,-1,0,204,239,1,0,0,
  	0,205,206,3,4,2,0,206,207,6,13,-1,0,207,239,1,0,0,0,208,209,3,2,1,0,209,
  	210,6,13,-1,0,210,239,1,0,0,0,211,212,3,24,12,0,212,213,6,13,-1,0,213,
  	239,1,0,0,0,214,215,5,76,0,0,215,216,5,5,0,0,216,239,6,13,-1,0,217,218,
  	5,75,0,0,218,219,5,5,0,0,219,239,6,13,-1,0,220,221,5,13,0,0,221,222,5,
  	2,0,0,222,223,3,54,27,0,223,224,5,3,0,0,224,225,5,5,0,0,225,226,6,13,
  	-1,0,226,239,1,0,0,0,227,228,5,14,0,0,228,229,5,2,0,0,229,230,3,54,27,
  	0,230,231,5,3,0,0,231,232,5,5,0,0,232,233,6,13,-1,0,233,239,1,0,0,0,234,
  	235,3,54,27,0,235,236,5,5,0,0,236,237,6,13,-1,0,237,239,1,0,0,0,238,188,
  	1,0,0,0,238,192,1,0,0,0,238,196,1,0,0,0,238,199,1,0,0,0,238,202,1,0,0,
  	0,238,205,1,0,0,0,238,208,1,0,0,0,238,211,1,0,0,0,238,214,1,0,0,0,238,
  	217,1,0,0,0,238,220,1,0,0,0,238,227,1,0,0,0,238,234,1,0,0,0,239,27,1,
  	0,0,0,240,244,5,11,0,0,241,243,3,30,15,0,242,241,1,0,0,0,243,246,1,0,
  	0,0,244,242,1,0,0,0,244,245,1,0,0,0,245,247,1,0,0,0,246,244,1,0,0,0,247,
  	248,5,12,0,0,248,249,6,14,-1,0,249,29,1,0,0,0,250,251,3,42,21,0,251,252,
  	3,60,30,0,252,253,5,5,0,0,253,254,6,15,-1,0,254,31,1,0,0,0,255,256,3,
  	42,21,0,256,261,3,34,17,0,257,258,5,10,0,0,258,260,3,34,17,0,259,257,
  	1,0,0,0,260,263,1,0,0,0,261,259,1,0,0,0,261,262,1,0,0,0,262,264,1,0,0,
  	0,263,261,1,0,0,0,264,265,6,16,-1,0,265,33,1,0,0,0,266,267,3,60,30,0,
  	267,268,6,17,-1,0,268,276,1,0,0,0,269,270,3,60,30,0,270,271,5,15,0,0,
  	271,272,3,54,27,0,272,273,1,0,0,0,273,274,6,17,-1,0,274,276,1,0,0,0,275,
  	266,1,0,0,0,275,269,1,0,0,0,276,35,1,0,0,0,277,278,5,16,0,0,278,279,3,
  	60,30,0,279,280,3,28,14,0,280,281,6,18,-1,0,281,37,1,0,0,0,282,283,5,
  	17,0,0,283,284,3,60,30,0,284,285,3,28,14,0,285,286,6,19,-1,0,286,39,1,
  	0,0,0,287,288,3,46,23,0,288,289,6,20,-1,0,289,294,1,0,0,0,290,291,3,60,
  	30,0,291,292,6,20,-1,0,292,294,1,0,0,0,293,287,1,0,0,0,293,290,1,0,0,
  	0,294,41,1,0,0,0,295,299,3,40,20,0,296,298,3,44,22,0,297,296,1,0,0,0,
  	298,301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,300,302,1,0,0,0,301,299,
  	1,0,0,0,302,303,6,21,-1,0,303,43,1,0,0,0,304,305,5,18,0,0,305,318,6,22,
  	-1,0,306,307,5,19,0,0,307,308,3,54,27,0,308,309,5,20,0,0,309,310,6,22,
  	-1,0,310,318,1,0,0,0,311,312,5,21,0,0,312,318,6,22,-1,0,313,314,5,22,
  	0,0,314,318,6,22,-1,0,315,316,5,23,0,0,316,318,6,22,-1,0,317,304,1,0,
  	0,0,317,306,1,0,0,0,317,311,1,0,0,0,317,313,1,0,0,0,317,315,1,0,0,0,318,
  	45,1,0,0,0,319,320,5,24,0,0,320,346,6,23,-1,0,321,322,5,25,0,0,322,346,
  	6,23,-1,0,323,324,5,26,0,0,324,346,6,23,-1,0,325,326,5,27,0,0,326,346,
  	6,23,-1,0,327,328,5,28,0,0,328,346,6,23,-1,0,329,330,5,29,0,0,330,346,
  	6,23,-1,0,331,332,5,30,0,0,332,346,6,23,-1,0,333,334,5,31,0,0,334,346,
  	6,23,-1,0,335,336,5,32,0,0,336,346,6,23,-1,0,337,338,5,33,0,0,338,346,
  	6,23,-1,0,339,340,5,34,0,0,340,346,6,23,-1,0,341,342,5,35,0,0,342,346,
  	6,23,-1,0,343,344,5,36,0,0,344,346,6,23,-1,0,345,319,1,0,0,0,345,321,
  	1,0,0,0,345,323,1,0,0,0,345,325,1,0,0,0,345,327,1,0,0,0,345,329,1,0,0,
  	0,345,331,1,0,0,0,345,333,1,0,0,0,345,335,1,0,0,0,345,337,1,0,0,0,345,
  	339,1,0,0,0,345,341,1,0,0,0,345,343,1,0,0,0,346,47,1,0,0,0,347,349,5,
  	37,0,0,348,350,3,54,27,0,349,348,1,0,0,0,349,350,1,0,0,0,350,351,1,0,
  	0,0,351,352,5,5,0,0,352,353,6,24,-1,0,353,49,1,0,0,0,354,355,5,38,0,0,
  	355,356,5,2,0,0,356,357,3,42,21,0,357,358,5,3,0,0,358,359,6,25,-1,0,359,
  	51,1,0,0,0,360,361,5,39,0,0,361,362,5,2,0,0,362,363,3,54,27,0,363,364,
  	5,3,0,0,364,365,6,26,-1,0,365,53,1,0,0,0,366,367,6,27,-1,0,367,368,5,
  	2,0,0,368,369,3,42,21,0,369,370,5,3,0,0,370,371,3,54,27,33,371,372,6,
  	27,-1,0,372,446,1,0,0,0,373,374,5,42,0,0,374,375,3,54,27,28,375,376,6,
  	27,-1,0,376,446,1,0,0,0,377,378,5,43,0,0,378,379,3,54,27,26,379,380,6,
  	27,-1,0,380,446,1,0,0,0,381,382,5,44,0,0,382,383,3,54,27,25,383,384,6,
  	27,-1,0,384,446,1,0,0,0,385,386,5,45,0,0,386,387,3,54,27,24,387,388,6,
  	27,-1,0,388,446,1,0,0,0,389,390,5,46,0,0,390,391,3,54,27,23,391,392,6,
  	27,-1,0,392,446,1,0,0,0,393,394,5,18,0,0,394,395,3,54,27,22,395,396,6,
  	27,-1,0,396,446,1,0,0,0,397,398,5,23,0,0,398,399,3,54,27,21,399,400,6,
  	27,-1,0,400,446,1,0,0,0,401,402,3,20,10,0,402,403,6,27,-1,0,403,446,1,
  	0,0,0,404,405,3,60,30,0,405,406,6,27,-1,0,406,446,1,0,0,0,407,408,3,58,
  	29,0,408,409,6,27,-1,0,409,446,1,0,0,0,410,411,5,2,0,0,411,412,3,54,27,
  	0,412,413,5,3,0,0,413,414,6,27,-1,0,414,446,1,0,0,0,415,416,5,62,0,0,
  	416,417,5,54,0,0,417,418,3,42,21,0,418,419,5,52,0,0,419,420,5,2,0,0,420,
  	421,3,54,27,0,421,422,5,3,0,0,422,423,6,27,-1,0,423,446,1,0,0,0,424,425,
  	3,50,25,0,425,426,6,27,-1,0,426,446,1,0,0,0,427,428,3,52,26,0,428,429,
  	6,27,-1,0,429,446,1,0,0,0,430,431,3,56,28,0,431,432,6,27,-1,0,432,446,
  	1,0,0,0,433,434,5,63,0,0,434,435,5,2,0,0,435,436,3,54,27,0,436,437,5,
  	3,0,0,437,438,6,27,-1,0,438,446,1,0,0,0,439,440,5,64,0,0,440,441,5,2,
  	0,0,441,442,3,54,27,0,442,443,5,3,0,0,443,444,6,27,-1,0,444,446,1,0,0,
  	0,445,366,1,0,0,0,445,373,1,0,0,0,445,377,1,0,0,0,445,381,1,0,0,0,445,
  	385,1,0,0,0,445,389,1,0,0,0,445,393,1,0,0,0,445,397,1,0,0,0,445,401,1,
  	0,0,0,445,404,1,0,0,0,445,407,1,0,0,0,445,410,1,0,0,0,445,415,1,0,0,0,
  	445,424,1,0,0,0,445,427,1,0,0,0,445,430,1,0,0,0,445,433,1,0,0,0,445,439,
  	1,0,0,0,446,521,1,0,0,0,447,448,10,20,0,0,448,449,7,0,0,0,449,450,3,54,
  	27,21,450,451,6,27,-1,0,451,520,1,0,0,0,452,453,10,19,0,0,453,454,7,1,
  	0,0,454,455,3,54,27,20,455,456,6,27,-1,0,456,520,1,0,0,0,457,458,10,18,
  	0,0,458,459,7,2,0,0,459,460,3,54,27,19,460,461,6,27,-1,0,461,520,1,0,
  	0,0,462,463,10,17,0,0,463,464,7,3,0,0,464,465,3,54,27,18,465,466,6,27,
  	-1,0,466,520,1,0,0,0,467,468,10,16,0,0,468,469,5,23,0,0,469,470,3,54,
  	27,17,470,471,6,27,-1,0,471,520,1,0,0,0,472,473,10,15,0,0,473,474,5,58,
  	0,0,474,475,3,54,27,16,475,476,6,27,-1,0,476,520,1,0,0,0,477,478,10,14,
  	0,0,478,479,5,59,0,0,479,480,3,54,27,15,480,481,6,27,-1,0,481,520,1,0,
  	0,0,482,483,10,13,0,0,483,484,5,60,0,0,484,485,3,54,27,14,485,486,6,27,
  	-1,0,486,520,1,0,0,0,487,488,10,12,0,0,488,489,5,61,0,0,489,490,3,54,
  	27,13,490,491,6,27,-1,0,491,520,1,0,0,0,492,493,10,9,0,0,493,494,5,15,
  	0,0,494,495,3,54,27,10,495,496,6,27,-1,0,496,520,1,0,0,0,497,498,10,32,
  	0,0,498,499,5,19,0,0,499,500,3,54,27,0,500,501,5,20,0,0,501,502,6,27,
  	-1,0,502,520,1,0,0,0,503,504,10,31,0,0,504,505,5,40,0,0,505,506,3,60,
  	30,0,506,507,6,27,-1,0,507,520,1,0,0,0,508,509,10,30,0,0,509,510,5,41,
  	0,0,510,511,3,60,30,0,511,512,6,27,-1,0,512,520,1,0,0,0,513,514,10,29,
  	0,0,514,515,5,42,0,0,515,520,6,27,-1,0,516,517,10,27,0,0,517,518,5,43,
  	0,0,518,520,6,27,-1,0,519,447,1,0,0,0,519,452,1,0,0,0,519,457,1,0,0,0,
  	519,462,1,0,0,0,519,467,1,0,0,0,519,472,1,0,0,0,519,477,1,0,0,0,519,482,
  	1,0,0,0,519,487,1,0,0,0,519,492,1,0,0,0,519,497,1,0,0,0,519,503,1,0,0,
  	0,519,508,1,0,0,0,519,513,1,0,0,0,519,516,1,0,0,0,520,523,1,0,0,0,521,
  	519,1,0,0,0,521,522,1,0,0,0,522,55,1,0,0,0,523,521,1,0,0,0,524,525,5,
  	65,0,0,525,526,5,2,0,0,526,527,3,54,27,0,527,528,5,10,0,0,528,529,3,54,
  	27,0,529,530,5,10,0,0,530,531,3,54,27,0,531,532,5,3,0,0,532,533,6,28,
  	-1,0,533,57,1,0,0,0,534,535,7,4,0,0,535,543,6,29,-1,0,536,537,5,69,0,
  	0,537,543,6,29,-1,0,538,539,5,70,0,0,539,543,6,29,-1,0,540,541,5,71,0,
  	0,541,543,6,29,-1,0,542,534,1,0,0,0,542,536,1,0,0,0,542,538,1,0,0,0,542,
  	540,1,0,0,0,543,59,1,0,0,0,544,545,5,77,0,0,545,546,6,30,-1,0,546,61,
  	1,0,0,0,23,95,104,111,131,134,149,152,163,173,182,238,244,261,275,293,
  	299,317,345,349,445,519,521,542
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
    setState(62);
    match(GrammarParser::T__0);
    setState(63);
    match(GrammarParser::T__1);
    setState(64);
    antlrcpp::downCast<WhileContext *>(_localctx)->exprContext = expr(0);
    setState(65);
    match(GrammarParser::T__2);
    setState(66);
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
    setState(69);
    match(GrammarParser::T__3);
    setState(70);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->stmtContext = stmt();
    setState(71);
    match(GrammarParser::T__0);
    setState(72);
    match(GrammarParser::T__1);
    setState(73);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->exprContext = expr(0);
    setState(74);
    match(GrammarParser::T__2);
    setState(75);
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
    setState(78);
    match(GrammarParser::T__5);
    setState(79);
    match(GrammarParser::T__1);
    setState(80);
    antlrcpp::downCast<ForContext *>(_localctx)->initStatmentsContext = initStatments();
    setState(81);
    match(GrammarParser::T__4);

    setState(82);
    antlrcpp::downCast<ForContext *>(_localctx)->condition = antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(83);
    match(GrammarParser::T__4);
    setState(84);
    antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(85);
    match(GrammarParser::T__2);
    setState(86);
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
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(89);
      antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext = declaration();

      				_localctx->m_node = antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
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
    setState(97);
    match(GrammarParser::T__6);
    setState(98);
    match(GrammarParser::T__1);
    setState(99);
    antlrcpp::downCast<IfContext *>(_localctx)->exprContext = expr(0);
    setState(100);
    match(GrammarParser::T__2);
    setState(101);
    antlrcpp::downCast<IfContext *>(_localctx)->stmt_1 = stmt();
    setState(104);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(102);
      match(GrammarParser::T__7);
      setState(103);
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
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 137422373376) != 0) || _la == GrammarParser::ID) {
      setState(108);
      antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext = progElement();
      antlrcpp::downCast<ProgContext *>(_localctx)->items.push_back(antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext);
      setState(113);
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
    setState(131);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(116);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext = function();

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext->m_node;	
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(119);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext = declaration();
      setState(120);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext = unionDecl();
      setState(124);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(127);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->structDeclContext = structDecl();
      setState(128);
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
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T__8) {
      setState(133);
      antlrcpp::downCast<FunctionContext *>(_localctx)->inline_keyword = match(GrammarParser::T__8);
    }
    setState(136);
    antlrcpp::downCast<FunctionContext *>(_localctx)->dataTypeContext = dataType();
    setState(137);
    antlrcpp::downCast<FunctionContext *>(_localctx)->identifierContext = identifier();
    setState(138);
    match(GrammarParser::T__1);
    setState(139);
    antlrcpp::downCast<FunctionContext *>(_localctx)->functionParametersContext = functionParameters();
    setState(140);
    match(GrammarParser::T__2);
    setState(141);
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
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & 9007199254749183) != 0)) {
      setState(144);
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::T__9) {
        setState(145);
        match(GrammarParser::T__9);
        setState(146);
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
        setState(151);
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
    setState(156);
    antlrcpp::downCast<FunctionParameterContext *>(_localctx)->dataTypeContext = dataType();
    setState(157);
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
    setState(160);
    antlrcpp::downCast<FunctionCallContext *>(_localctx)->identifierContext = identifier();
    setState(161);
    match(GrammarParser::T__1);
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4611548854343172092) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 10227) != 0)) {
      setState(162);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->argumentListContext = argumentList();
    }
    setState(165);
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
    setState(168);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(169);
      match(GrammarParser::T__9);
      setState(170);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
      setState(175);
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
    setState(178);
    match(GrammarParser::T__10);
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4611548579482015530) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16371) != 0)) {
      setState(179);
      antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext = stmt();
      antlrcpp::downCast<BlockContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext);
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(185);
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
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(188);
      antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext = declaration();
      setState(189);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(192);
      antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext = functionCall();
      setState(193);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(196);
      antlrcpp::downCast<StmtContext *>(_localctx)->returnContext = return_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->returnContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(199);
      antlrcpp::downCast<StmtContext *>(_localctx)->ifContext = if_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->ifContext->m_node;
      			
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(202);
      antlrcpp::downCast<StmtContext *>(_localctx)->whileContext = while_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->whileContext->m_node;
      			
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(205);
      antlrcpp::downCast<StmtContext *>(_localctx)->forContext = for_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->forContext->m_node;
      			
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(208);
      antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext = doWhile();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext->m_node;
      			
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(211);
      antlrcpp::downCast<StmtContext *>(_localctx)->blockContext = block();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->blockContext->m_node;
      			
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(214);
      match(GrammarParser::BREAK);
      setState(215);
      match(GrammarParser::T__4);

      				_localctx->m_node = new BreakNode{};
      			
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(217);
      match(GrammarParser::CONTINUE);
      setState(218);
      match(GrammarParser::T__4);

      				_localctx->m_node = new ContinueNode{};
      			
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(220);
      match(GrammarParser::T__12);
      setState(221);
      match(GrammarParser::T__1);
      setState(222);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(223);
      match(GrammarParser::T__2);
      setState(224);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(227);
      match(GrammarParser::T__13);
      setState(228);
      match(GrammarParser::T__1);
      setState(229);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(230);
      match(GrammarParser::T__2);
      setState(231);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintTypeNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(234);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(235);
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
    setState(240);
    match(GrammarParser::T__10);
    setState(244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & 9007199254749183) != 0)) {
      setState(241);
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext = memberDecl();
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext);
      setState(246);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(247);
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
    setState(250);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->dataTypeContext = dataType();
    setState(251);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->identifierContext = identifier();
    setState(252);
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
    setState(255);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->dataTypeContext = dataType();
    setState(256);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
    antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
    setState(261);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__9) {
      setState(257);
      match(GrammarParser::T__9);
      setState(258);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
      antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
      setState(263);
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
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(266);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			_localctx -> m_node = new DeclarationListItemNode{in};
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(269);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();
      setState(270);
      match(GrammarParser::T__14);
      setState(271);
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
    setState(277);
    match(GrammarParser::T__15);
    setState(278);
    antlrcpp::downCast<StructDeclContext *>(_localctx)->identifierContext = identifier();
    setState(279);
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
    setState(282);
    match(GrammarParser::T__16);
    setState(283);
    antlrcpp::downCast<UnionDeclContext *>(_localctx)->identifierContext = identifier();
    setState(284);
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
    setState(293);
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
      case GrammarParser::T__35: {
        enterOuterAlt(_localctx, 1);
        setState(287);
        antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext = basicType();
         _localctx->m_node = antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext->m_node; 
        break;
      }

      case GrammarParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(290);
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
    setState(295);
    antlrcpp::downCast<DataTypeContext *>(_localctx)->ft = fundamentalType();
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15466496) != 0)) {
      setState(296);
      antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext = typeModifier();
      antlrcpp::downCast<DataTypeContext *>(_localctx)->modifier_list.push_back(antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext);
      setState(301);
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
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__17: {
        enterOuterAlt(_localctx, 1);
        setState(304);
        match(GrammarParser::T__17);
        _localctx->m_node = new PointerNode{}; 
        break;
      }

      case GrammarParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(306);
        match(GrammarParser::T__18);

        setState(307);
        antlrcpp::downCast<TypeModifierContext *>(_localctx)->e = expr(0);
        setState(308);
        match(GrammarParser::T__19);
         _localctx->m_node = new ArrayNode{ antlrcpp::downCast<TypeModifierContext *>(_localctx)->e->m_node }; 
        break;
      }

      case GrammarParser::T__20: {
        enterOuterAlt(_localctx, 3);
        setState(311);
        match(GrammarParser::T__20);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::CONST}; 
        break;
      }

      case GrammarParser::T__21: {
        enterOuterAlt(_localctx, 4);
        setState(313);
        match(GrammarParser::T__21);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::VOLATILE}; 
        break;
      }

      case GrammarParser::T__22: {
        enterOuterAlt(_localctx, 5);
        setState(315);
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
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__23: {
        enterOuterAlt(_localctx, 1);
        setState(319);
        match(GrammarParser::T__23);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__24: {
        enterOuterAlt(_localctx, 2);
        setState(321);
        match(GrammarParser::T__24);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT8}; 
        break;
      }

      case GrammarParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(323);
        match(GrammarParser::T__25);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT16}; 
        break;
      }

      case GrammarParser::T__26: {
        enterOuterAlt(_localctx, 4);
        setState(325);
        match(GrammarParser::T__26);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__27: {
        enterOuterAlt(_localctx, 5);
        setState(327);
        match(GrammarParser::T__27);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT64}; 
        break;
      }

      case GrammarParser::T__28: {
        enterOuterAlt(_localctx, 6);
        setState(329);
        match(GrammarParser::T__28);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT8}; 
        break;
      }

      case GrammarParser::T__29: {
        enterOuterAlt(_localctx, 7);
        setState(331);
        match(GrammarParser::T__29);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT16}; 
        break;
      }

      case GrammarParser::T__30: {
        enterOuterAlt(_localctx, 8);
        setState(333);
        match(GrammarParser::T__30);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT32}; 
        break;
      }

      case GrammarParser::T__31: {
        enterOuterAlt(_localctx, 9);
        setState(335);
        match(GrammarParser::T__31);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT64}; 
        break;
      }

      case GrammarParser::T__32: {
        enterOuterAlt(_localctx, 10);
        setState(337);
        match(GrammarParser::T__32);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::FLOAT}; 
        break;
      }

      case GrammarParser::T__33: {
        enterOuterAlt(_localctx, 11);
        setState(339);
        match(GrammarParser::T__33);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::DOUBLE}; 
        break;
      }

      case GrammarParser::T__34: {
        enterOuterAlt(_localctx, 12);
        setState(341);
        match(GrammarParser::T__34);
         _localctx->m_node = new BasicTypeNode{IRBasicType::BOOL}; 
        break;
      }

      case GrammarParser::T__35: {
        enterOuterAlt(_localctx, 13);
        setState(343);
        match(GrammarParser::T__35);
         _localctx->m_node = new BasicTypeNode{IRBasicType::VOID}; 
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
    setState(347);
    match(GrammarParser::T__36);
    setState(349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4611548854343172092) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 10227) != 0)) {
      setState(348);
      antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext = expr(0);
    }
    setState(351);
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
    setState(354);
    match(GrammarParser::T__37);
    setState(355);
    match(GrammarParser::T__1);
    setState(356);
    antlrcpp::downCast<SizeOfContext *>(_localctx)->dataTypeContext = dataType();
    setState(357);
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
    setState(360);
    match(GrammarParser::T__38);
    setState(361);
    match(GrammarParser::T__1);
    setState(362);
    antlrcpp::downCast<AssertConditionContext *>(_localctx)->exprContext = expr(0);
    setState(363);
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
    setState(445);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(367);
      match(GrammarParser::T__1);
      setState(368);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(369);
      match(GrammarParser::T__2);
      setState(370);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(33);

      			_localctx->m_node = new CastNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 2: {
      setState(373);
      match(GrammarParser::T__41);
      setState(374);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(28);

      			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 3: {
      setState(377);
      match(GrammarParser::T__42);
      setState(378);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(26);

      			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 4: {
      setState(381);
      match(GrammarParser::T__43);
      setState(382);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(25);

      			_localctx->m_node = new UnaryMinusNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 5: {
      setState(385);
      match(GrammarParser::T__44);
      setState(386);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(24);

      			_localctx->m_node = new BitwiseNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 6: {
      setState(389);
      match(GrammarParser::T__45);
      setState(390);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(23);

      			_localctx->m_node = new BooleanNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 7: {
      setState(393);
      match(GrammarParser::T__17);
      setState(394);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(22);

      			_localctx->m_node = new DereferenceNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 8: {
      setState(397);
      match(GrammarParser::T__22);
      setState(398);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(21);

      			_localctx->m_node = new AddressOfNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 9: {
      setState(401);
      antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext = functionCall();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext->m_node; 
      break;
    }

    case 10: {
      setState(404);
      antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext->m_node; 
      break;
    }

    case 11: {
      setState(407);
      antlrcpp::downCast<ExprContext *>(_localctx)->numberContext = number();
       _localctx -> m_node = antlrcpp::downCast<ExprContext *>(_localctx)->numberContext->m_node; 
      break;
    }

    case 12: {
      setState(410);
      match(GrammarParser::T__1);
      setState(411);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(412);
      match(GrammarParser::T__2);
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node; 
      break;
    }

    case 13: {
      setState(415);
      match(GrammarParser::T__61);
      setState(416);
      match(GrammarParser::T__53);
      setState(417);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(418);
      match(GrammarParser::T__51);
      setState(419);
      match(GrammarParser::T__1);
      setState(420);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(421);
      match(GrammarParser::T__2);

      			_localctx->m_node = new ReinterpretNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 14: {
      setState(424);
      antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext = sizeOf();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext->m_node; 
      break;
    }

    case 15: {
      setState(427);
      antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext = assertCondition();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext->m_node; 
      break;
    }

    case 16: {
      setState(430);
      antlrcpp::downCast<ExprContext *>(_localctx)->selectContext = select();

      			_localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->selectContext->m_node;
      		
      break;
    }

    case 17: {
      setState(433);
      match(GrammarParser::T__62);
      setState(434);
      match(GrammarParser::T__1);
      setState(435);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(436);
      match(GrammarParser::T__2);

      			_localctx->m_node = new MallocNode(antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node);
      		
      break;
    }

    case 18: {
      setState(439);
      match(GrammarParser::T__63);
      setState(440);
      match(GrammarParser::T__1);
      setState(441);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(442);
      match(GrammarParser::T__2);

      			_localctx->m_node = new FreeNode(antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node);
      		
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(521);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(519);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(447);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(448);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 422212465328128) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(449);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(21);
           
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
          setState(452);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(453);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__43

          || _la == GrammarParser::T__48)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(454);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(20);

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
          setState(457);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(458);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__49

          || _la == GrammarParser::T__50)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(459);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(19);

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
          setState(462);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(463);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 283726776524341248) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(464);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(18);

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
          setState(467);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(468);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__22);
          setState(469);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(17);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_AND};
                    		
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(472);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(473);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__57);
          setState(474);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(16);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_XOR};
                    		
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(477);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(478);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__58);
          setState(479);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(15);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_OR};
                    		
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(482);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(483);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__59);
          setState(484);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(14);

                    			_localctx->m_node = new AndNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(487);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(488);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__60);
          setState(489);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(13);

                    			_localctx->m_node = new OrNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left_expr = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(492);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(493);
          match(GrammarParser::T__14);
          setState(494);
          antlrcpp::downCast<ExprContext *>(_localctx)->right_expr = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(10);

                    			_localctx->m_node = new AssignmentNode{antlrcpp::downCast<ExprContext *>(_localctx)->left_expr->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right_expr->m_node};
                    		
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->array_id = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(497);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(498);
          match(GrammarParser::T__18);
          setState(499);
          antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
          setState(500);
          match(GrammarParser::T__19);

                    			_localctx->m_node = new ArrayAccessNode{antlrcpp::downCast<ExprContext *>(_localctx)->array_id->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
                    		
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->new_left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(503);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(504);
          match(GrammarParser::T__39);
          setState(505);
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
          setState(508);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(509);
          match(GrammarParser::T__40);
          setState(510);
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
          setState(513);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(514);
          match(GrammarParser::T__41);

                    			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(516);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(517);
          match(GrammarParser::T__42);

                    			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        default:
          break;
        } 
      }
      setState(523);
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
    setState(524);
    match(GrammarParser::T__64);
    setState(525);
    match(GrammarParser::T__1);
    setState(526);
    antlrcpp::downCast<SelectContext *>(_localctx)->condition = expr(0);
    setState(527);
    match(GrammarParser::T__9);
    setState(528);
    antlrcpp::downCast<SelectContext *>(_localctx)->e_t = expr(0);
    setState(529);
    match(GrammarParser::T__9);
    setState(530);
    antlrcpp::downCast<SelectContext *>(_localctx)->e_f = expr(0);
    setState(531);
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
    setState(542);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INT:
      case GrammarParser::BINARY:
      case GrammarParser::OCTAL:
      case GrammarParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(534);
        antlrcpp::downCast<NumberContext *>(_localctx)->integerLiteral = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 68)) & 113) != 0))) {
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
        setState(536);
        antlrcpp::downCast<NumberContext *>(_localctx)->floatToken = match(GrammarParser::FLOAT);

        				_localctx -> m_node = new ConstantNode{(float) std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->floatToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::DOUBLE: {
        enterOuterAlt(_localctx, 3);
        setState(538);
        antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken = match(GrammarParser::DOUBLE);

        				_localctx -> m_node = new ConstantNode{ std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::BOOL: {
        enterOuterAlt(_localctx, 4);
        setState(540);
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
  enterRule(_localctx, 60, GrammarParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(544);
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
    case 0: return precpred(_ctx, 20);
    case 1: return precpred(_ctx, 19);
    case 2: return precpred(_ctx, 18);
    case 3: return precpred(_ctx, 17);
    case 4: return precpred(_ctx, 16);
    case 5: return precpred(_ctx, 15);
    case 6: return precpred(_ctx, 14);
    case 7: return precpred(_ctx, 13);
    case 8: return precpred(_ctx, 12);
    case 9: return precpred(_ctx, 9);
    case 10: return precpred(_ctx, 32);
    case 11: return precpred(_ctx, 31);
    case 12: return precpred(_ctx, 30);
    case 13: return precpred(_ctx, 29);
    case 14: return precpred(_ctx, 27);

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
