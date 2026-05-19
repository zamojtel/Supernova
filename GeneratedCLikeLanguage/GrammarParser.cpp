
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
      "expr", "number", "identifier"
    },
    std::vector<std::string>{
      "", "'while'", "'('", "')'", "'do'", "';'", "'for'", "'if'", "'else'", 
      "','", "'{'", "'}'", "'print'", "'='", "'struct'", "'union'", "'*'", 
      "'['", "']'", "'const'", "'volatile'", "'&'", "'int'", "'int8'", "'int16'", 
      "'int32'", "'int64'", "'uint8'", "'uint16'", "'uint32'", "'uint64'", 
      "'float'", "'double'", "'bool'", "'void'", "'return'", "'sizeof'", 
      "'assert'", "'.'", "'->'", "'++'", "'--'", "'!'", "'/'", "'+'", "'-'", 
      "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&&'", "'||'", "'|'", 
      "'reinterpret_cast'", "", "", "", "", "", "", "'continue'", "'break'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "LINE_COMMENT", "WS", "INT", "FLOAT", "DOUBLE", 
      "BOOL", "CONTINUE", "BREAK", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,64,493,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,94,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,103,8,4,1,4,1,4,1,5,
  	5,5,108,8,5,10,5,12,5,111,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,130,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,8,1,8,1,8,5,8,143,8,8,10,8,12,8,146,9,8,3,8,148,8,8,1,8,1,8,1,9,1,
  	9,1,9,1,9,1,10,1,10,1,10,3,10,159,8,10,1,10,1,10,1,10,1,11,1,11,1,11,
  	5,11,167,8,11,10,11,12,11,170,9,11,1,11,1,11,1,12,1,12,5,12,176,8,12,
  	10,12,12,12,179,9,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,227,8,13,1,14,1,14,5,14,
  	231,8,14,10,14,12,14,234,9,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,
  	1,16,1,16,1,16,1,16,5,16,248,8,16,10,16,12,16,251,9,16,1,16,1,16,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,264,8,17,1,18,1,18,1,18,
  	1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	282,8,20,1,21,1,21,5,21,286,8,21,10,21,12,21,289,9,21,1,21,1,21,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,306,
  	8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,
  	334,8,23,1,24,1,24,3,24,338,8,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,
  	25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,411,8,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,5,27,475,8,27,10,27,12,27,478,9,27,1,28,1,28,1,28,1,28,1,
  	28,1,28,1,28,1,28,3,28,488,8,28,1,29,1,29,1,29,1,29,0,1,54,30,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,0,3,2,0,16,16,43,43,1,0,44,45,1,0,46,51,534,0,60,1,0,0,0,2,67,1,
  	0,0,0,4,76,1,0,0,0,6,93,1,0,0,0,8,95,1,0,0,0,10,109,1,0,0,0,12,129,1,
  	0,0,0,14,131,1,0,0,0,16,147,1,0,0,0,18,151,1,0,0,0,20,155,1,0,0,0,22,
  	163,1,0,0,0,24,173,1,0,0,0,26,226,1,0,0,0,28,228,1,0,0,0,30,238,1,0,0,
  	0,32,243,1,0,0,0,34,263,1,0,0,0,36,265,1,0,0,0,38,270,1,0,0,0,40,281,
  	1,0,0,0,42,283,1,0,0,0,44,305,1,0,0,0,46,333,1,0,0,0,48,335,1,0,0,0,50,
  	342,1,0,0,0,52,348,1,0,0,0,54,410,1,0,0,0,56,487,1,0,0,0,58,489,1,0,0,
  	0,60,61,5,1,0,0,61,62,5,2,0,0,62,63,3,54,27,0,63,64,5,3,0,0,64,65,3,26,
  	13,0,65,66,6,0,-1,0,66,1,1,0,0,0,67,68,5,4,0,0,68,69,3,26,13,0,69,70,
  	5,1,0,0,70,71,5,2,0,0,71,72,3,54,27,0,72,73,5,3,0,0,73,74,5,5,0,0,74,
  	75,6,1,-1,0,75,3,1,0,0,0,76,77,5,6,0,0,77,78,5,2,0,0,78,79,3,6,3,0,79,
  	80,5,5,0,0,80,81,3,54,27,0,81,82,5,5,0,0,82,83,3,54,27,0,83,84,5,3,0,
  	0,84,85,3,26,13,0,85,86,6,2,-1,0,86,5,1,0,0,0,87,88,3,32,16,0,88,89,6,
  	3,-1,0,89,94,1,0,0,0,90,91,3,54,27,0,91,92,6,3,-1,0,92,94,1,0,0,0,93,
  	87,1,0,0,0,93,90,1,0,0,0,94,7,1,0,0,0,95,96,5,7,0,0,96,97,5,2,0,0,97,
  	98,3,54,27,0,98,99,5,3,0,0,99,102,3,26,13,0,100,101,5,8,0,0,101,103,3,
  	26,13,0,102,100,1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,105,6,4,-1,
  	0,105,9,1,0,0,0,106,108,3,12,6,0,107,106,1,0,0,0,108,111,1,0,0,0,109,
  	107,1,0,0,0,109,110,1,0,0,0,110,112,1,0,0,0,111,109,1,0,0,0,112,113,6,
  	5,-1,0,113,11,1,0,0,0,114,115,3,14,7,0,115,116,6,6,-1,0,116,130,1,0,0,
  	0,117,118,3,32,16,0,118,119,5,5,0,0,119,120,6,6,-1,0,120,130,1,0,0,0,
  	121,122,3,38,19,0,122,123,5,5,0,0,123,124,6,6,-1,0,124,130,1,0,0,0,125,
  	126,3,36,18,0,126,127,5,5,0,0,127,128,6,6,-1,0,128,130,1,0,0,0,129,114,
  	1,0,0,0,129,117,1,0,0,0,129,121,1,0,0,0,129,125,1,0,0,0,130,13,1,0,0,
  	0,131,132,3,42,21,0,132,133,3,58,29,0,133,134,5,2,0,0,134,135,3,16,8,
  	0,135,136,5,3,0,0,136,137,3,24,12,0,137,138,6,7,-1,0,138,15,1,0,0,0,139,
  	144,3,18,9,0,140,141,5,9,0,0,141,143,3,18,9,0,142,140,1,0,0,0,143,146,
  	1,0,0,0,144,142,1,0,0,0,144,145,1,0,0,0,145,148,1,0,0,0,146,144,1,0,0,
  	0,147,139,1,0,0,0,147,148,1,0,0,0,148,149,1,0,0,0,149,150,6,8,-1,0,150,
  	17,1,0,0,0,151,152,3,42,21,0,152,153,3,58,29,0,153,154,6,9,-1,0,154,19,
  	1,0,0,0,155,156,3,58,29,0,156,158,5,2,0,0,157,159,3,22,11,0,158,157,1,
  	0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,160,161,5,3,0,0,161,162,6,10,-1,
  	0,162,21,1,0,0,0,163,168,3,54,27,0,164,165,5,9,0,0,165,167,3,54,27,0,
  	166,164,1,0,0,0,167,170,1,0,0,0,168,166,1,0,0,0,168,169,1,0,0,0,169,171,
  	1,0,0,0,170,168,1,0,0,0,171,172,6,11,-1,0,172,23,1,0,0,0,173,177,5,10,
  	0,0,174,176,3,26,13,0,175,174,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,
  	177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,0,180,181,5,11,0,0,181,
  	182,6,12,-1,0,182,25,1,0,0,0,183,184,3,32,16,0,184,185,5,5,0,0,185,186,
  	6,13,-1,0,186,227,1,0,0,0,187,188,3,20,10,0,188,189,5,5,0,0,189,190,6,
  	13,-1,0,190,227,1,0,0,0,191,192,3,48,24,0,192,193,6,13,-1,0,193,227,1,
  	0,0,0,194,195,3,8,4,0,195,196,6,13,-1,0,196,227,1,0,0,0,197,198,3,0,0,
  	0,198,199,6,13,-1,0,199,227,1,0,0,0,200,201,3,4,2,0,201,202,6,13,-1,0,
  	202,227,1,0,0,0,203,204,3,2,1,0,204,205,6,13,-1,0,205,227,1,0,0,0,206,
  	207,3,24,12,0,207,208,6,13,-1,0,208,227,1,0,0,0,209,210,5,63,0,0,210,
  	211,5,5,0,0,211,227,6,13,-1,0,212,213,5,62,0,0,213,214,5,5,0,0,214,227,
  	6,13,-1,0,215,216,5,12,0,0,216,217,5,2,0,0,217,218,3,54,27,0,218,219,
  	5,3,0,0,219,220,5,5,0,0,220,221,6,13,-1,0,221,227,1,0,0,0,222,223,3,54,
  	27,0,223,224,5,5,0,0,224,225,6,13,-1,0,225,227,1,0,0,0,226,183,1,0,0,
  	0,226,187,1,0,0,0,226,191,1,0,0,0,226,194,1,0,0,0,226,197,1,0,0,0,226,
  	200,1,0,0,0,226,203,1,0,0,0,226,206,1,0,0,0,226,209,1,0,0,0,226,212,1,
  	0,0,0,226,215,1,0,0,0,226,222,1,0,0,0,227,27,1,0,0,0,228,232,5,10,0,0,
  	229,231,3,30,15,0,230,229,1,0,0,0,231,234,1,0,0,0,232,230,1,0,0,0,232,
  	233,1,0,0,0,233,235,1,0,0,0,234,232,1,0,0,0,235,236,5,11,0,0,236,237,
  	6,14,-1,0,237,29,1,0,0,0,238,239,3,42,21,0,239,240,3,58,29,0,240,241,
  	5,5,0,0,241,242,6,15,-1,0,242,31,1,0,0,0,243,244,3,42,21,0,244,249,3,
  	34,17,0,245,246,5,9,0,0,246,248,3,34,17,0,247,245,1,0,0,0,248,251,1,0,
  	0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,252,1,0,0,0,251,249,1,0,0,0,252,
  	253,6,16,-1,0,253,33,1,0,0,0,254,255,3,58,29,0,255,256,6,17,-1,0,256,
  	264,1,0,0,0,257,258,3,58,29,0,258,259,5,13,0,0,259,260,3,54,27,0,260,
  	261,1,0,0,0,261,262,6,17,-1,0,262,264,1,0,0,0,263,254,1,0,0,0,263,257,
  	1,0,0,0,264,35,1,0,0,0,265,266,5,14,0,0,266,267,3,58,29,0,267,268,3,28,
  	14,0,268,269,6,18,-1,0,269,37,1,0,0,0,270,271,5,15,0,0,271,272,3,58,29,
  	0,272,273,3,28,14,0,273,274,6,19,-1,0,274,39,1,0,0,0,275,276,3,46,23,
  	0,276,277,6,20,-1,0,277,282,1,0,0,0,278,279,3,58,29,0,279,280,6,20,-1,
  	0,280,282,1,0,0,0,281,275,1,0,0,0,281,278,1,0,0,0,282,41,1,0,0,0,283,
  	287,3,40,20,0,284,286,3,44,22,0,285,284,1,0,0,0,286,289,1,0,0,0,287,285,
  	1,0,0,0,287,288,1,0,0,0,288,290,1,0,0,0,289,287,1,0,0,0,290,291,6,21,
  	-1,0,291,43,1,0,0,0,292,293,5,16,0,0,293,306,6,22,-1,0,294,295,5,17,0,
  	0,295,296,3,54,27,0,296,297,5,18,0,0,297,298,6,22,-1,0,298,306,1,0,0,
  	0,299,300,5,19,0,0,300,306,6,22,-1,0,301,302,5,20,0,0,302,306,6,22,-1,
  	0,303,304,5,21,0,0,304,306,6,22,-1,0,305,292,1,0,0,0,305,294,1,0,0,0,
  	305,299,1,0,0,0,305,301,1,0,0,0,305,303,1,0,0,0,306,45,1,0,0,0,307,308,
  	5,22,0,0,308,334,6,23,-1,0,309,310,5,23,0,0,310,334,6,23,-1,0,311,312,
  	5,24,0,0,312,334,6,23,-1,0,313,314,5,25,0,0,314,334,6,23,-1,0,315,316,
  	5,26,0,0,316,334,6,23,-1,0,317,318,5,27,0,0,318,334,6,23,-1,0,319,320,
  	5,28,0,0,320,334,6,23,-1,0,321,322,5,29,0,0,322,334,6,23,-1,0,323,324,
  	5,30,0,0,324,334,6,23,-1,0,325,326,5,31,0,0,326,334,6,23,-1,0,327,328,
  	5,32,0,0,328,334,6,23,-1,0,329,330,5,33,0,0,330,334,6,23,-1,0,331,332,
  	5,34,0,0,332,334,6,23,-1,0,333,307,1,0,0,0,333,309,1,0,0,0,333,311,1,
  	0,0,0,333,313,1,0,0,0,333,315,1,0,0,0,333,317,1,0,0,0,333,319,1,0,0,0,
  	333,321,1,0,0,0,333,323,1,0,0,0,333,325,1,0,0,0,333,327,1,0,0,0,333,329,
  	1,0,0,0,333,331,1,0,0,0,334,47,1,0,0,0,335,337,5,35,0,0,336,338,3,54,
  	27,0,337,336,1,0,0,0,337,338,1,0,0,0,338,339,1,0,0,0,339,340,5,5,0,0,
  	340,341,6,24,-1,0,341,49,1,0,0,0,342,343,5,36,0,0,343,344,5,2,0,0,344,
  	345,3,42,21,0,345,346,5,3,0,0,346,347,6,25,-1,0,347,51,1,0,0,0,348,349,
  	5,37,0,0,349,350,5,2,0,0,350,351,3,54,27,0,351,352,5,3,0,0,352,353,6,
  	26,-1,0,353,53,1,0,0,0,354,355,6,27,-1,0,355,356,5,2,0,0,356,357,3,42,
  	21,0,357,358,5,3,0,0,358,359,3,54,27,26,359,360,6,27,-1,0,360,411,1,0,
  	0,0,361,362,5,40,0,0,362,363,3,54,27,21,363,364,6,27,-1,0,364,411,1,0,
  	0,0,365,366,5,41,0,0,366,367,3,54,27,19,367,368,6,27,-1,0,368,411,1,0,
  	0,0,369,370,5,42,0,0,370,371,3,54,27,0,371,372,6,27,-1,0,372,411,1,0,
  	0,0,373,374,5,16,0,0,374,375,3,54,27,17,375,376,6,27,-1,0,376,411,1,0,
  	0,0,377,378,5,21,0,0,378,379,3,54,27,16,379,380,6,27,-1,0,380,411,1,0,
  	0,0,381,382,3,20,10,0,382,383,6,27,-1,0,383,411,1,0,0,0,384,385,3,58,
  	29,0,385,386,6,27,-1,0,386,411,1,0,0,0,387,388,3,56,28,0,388,389,6,27,
  	-1,0,389,411,1,0,0,0,390,391,5,2,0,0,391,392,3,54,27,0,392,393,5,3,0,
  	0,393,394,6,27,-1,0,394,411,1,0,0,0,395,396,5,55,0,0,396,397,5,48,0,0,
  	397,398,3,42,21,0,398,399,5,46,0,0,399,400,5,2,0,0,400,401,3,54,27,0,
  	401,402,5,3,0,0,402,403,6,27,-1,0,403,411,1,0,0,0,404,405,3,50,25,0,405,
  	406,6,27,-1,0,406,411,1,0,0,0,407,408,3,52,26,0,408,409,6,27,-1,0,409,
  	411,1,0,0,0,410,354,1,0,0,0,410,361,1,0,0,0,410,365,1,0,0,0,410,369,1,
  	0,0,0,410,373,1,0,0,0,410,377,1,0,0,0,410,381,1,0,0,0,410,384,1,0,0,0,
  	410,387,1,0,0,0,410,390,1,0,0,0,410,395,1,0,0,0,410,404,1,0,0,0,410,407,
  	1,0,0,0,411,476,1,0,0,0,412,413,10,15,0,0,413,414,7,0,0,0,414,415,3,54,
  	27,16,415,416,6,27,-1,0,416,475,1,0,0,0,417,418,10,14,0,0,418,419,7,1,
  	0,0,419,420,3,54,27,15,420,421,6,27,-1,0,421,475,1,0,0,0,422,423,10,13,
  	0,0,423,424,7,2,0,0,424,425,3,54,27,14,425,426,6,27,-1,0,426,475,1,0,
  	0,0,427,428,10,12,0,0,428,429,5,52,0,0,429,430,3,54,27,13,430,431,6,27,
  	-1,0,431,475,1,0,0,0,432,433,10,11,0,0,433,434,5,53,0,0,434,435,3,54,
  	27,12,435,436,6,27,-1,0,436,475,1,0,0,0,437,438,10,10,0,0,438,439,5,21,
  	0,0,439,440,3,54,27,11,440,441,6,27,-1,0,441,475,1,0,0,0,442,443,10,9,
  	0,0,443,444,5,54,0,0,444,445,3,54,27,10,445,446,6,27,-1,0,446,475,1,0,
  	0,0,447,448,10,6,0,0,448,449,5,13,0,0,449,450,3,54,27,7,450,451,6,27,
  	-1,0,451,475,1,0,0,0,452,453,10,25,0,0,453,454,5,17,0,0,454,455,3,54,
  	27,0,455,456,5,18,0,0,456,457,6,27,-1,0,457,475,1,0,0,0,458,459,10,24,
  	0,0,459,460,5,38,0,0,460,461,3,58,29,0,461,462,6,27,-1,0,462,475,1,0,
  	0,0,463,464,10,23,0,0,464,465,5,39,0,0,465,466,3,58,29,0,466,467,6,27,
  	-1,0,467,475,1,0,0,0,468,469,10,22,0,0,469,470,5,40,0,0,470,475,6,27,
  	-1,0,471,472,10,20,0,0,472,473,5,41,0,0,473,475,6,27,-1,0,474,412,1,0,
  	0,0,474,417,1,0,0,0,474,422,1,0,0,0,474,427,1,0,0,0,474,432,1,0,0,0,474,
  	437,1,0,0,0,474,442,1,0,0,0,474,447,1,0,0,0,474,452,1,0,0,0,474,458,1,
  	0,0,0,474,463,1,0,0,0,474,468,1,0,0,0,474,471,1,0,0,0,475,478,1,0,0,0,
  	476,474,1,0,0,0,476,477,1,0,0,0,477,55,1,0,0,0,478,476,1,0,0,0,479,480,
  	5,58,0,0,480,488,6,28,-1,0,481,482,5,59,0,0,482,488,6,28,-1,0,483,484,
  	5,60,0,0,484,488,6,28,-1,0,485,486,5,61,0,0,486,488,6,28,-1,0,487,479,
  	1,0,0,0,487,481,1,0,0,0,487,483,1,0,0,0,487,485,1,0,0,0,488,57,1,0,0,
  	0,489,490,5,64,0,0,490,491,6,29,-1,0,491,59,1,0,0,0,22,93,102,109,129,
  	144,147,158,168,177,226,232,249,263,281,287,305,333,337,410,474,476,487
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
    setState(60);
    match(GrammarParser::T__0);
    setState(61);
    match(GrammarParser::T__1);
    setState(62);
    antlrcpp::downCast<WhileContext *>(_localctx)->exprContext = expr(0);
    setState(63);
    match(GrammarParser::T__2);
    setState(64);
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
    setState(67);
    match(GrammarParser::T__3);
    setState(68);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->stmtContext = stmt();
    setState(69);
    match(GrammarParser::T__0);
    setState(70);
    match(GrammarParser::T__1);
    setState(71);
    antlrcpp::downCast<DoWhileContext *>(_localctx)->exprContext = expr(0);
    setState(72);
    match(GrammarParser::T__2);
    setState(73);
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
    setState(76);
    match(GrammarParser::T__5);
    setState(77);
    match(GrammarParser::T__1);
    setState(78);
    antlrcpp::downCast<ForContext *>(_localctx)->initStatmentsContext = initStatments();
    setState(79);
    match(GrammarParser::T__4);

    setState(80);
    antlrcpp::downCast<ForContext *>(_localctx)->condition = antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(81);
    match(GrammarParser::T__4);
    setState(82);
    antlrcpp::downCast<ForContext *>(_localctx)->exprContext = expr(0);
    setState(83);
    match(GrammarParser::T__2);
    setState(84);
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
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(87);
      antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext = declaration();

      				_localctx->m_node = antlrcpp::downCast<InitStatmentsContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
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
    setState(95);
    match(GrammarParser::T__6);
    setState(96);
    match(GrammarParser::T__1);
    setState(97);
    antlrcpp::downCast<IfContext *>(_localctx)->exprContext = expr(0);
    setState(98);
    match(GrammarParser::T__2);
    setState(99);
    antlrcpp::downCast<IfContext *>(_localctx)->stmt_1 = stmt();
    setState(102);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(100);
      match(GrammarParser::T__7);
      setState(101);
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
    setState(109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & 1125899908939523) != 0)) {
      setState(106);
      antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext = progElement();
      antlrcpp::downCast<ProgContext *>(_localctx)->items.push_back(antlrcpp::downCast<ProgContext *>(_localctx)->progElementContext);
      setState(111);
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
    setState(129);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(114);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext = function();

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->functionContext->m_node;	
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(117);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext = declaration();
      setState(118);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(121);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext = unionDecl();
      setState(122);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<ProgElementContext *>(_localctx)->unionDeclContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(125);
      antlrcpp::downCast<ProgElementContext *>(_localctx)->structDeclContext = structDecl();
      setState(126);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    antlrcpp::downCast<FunctionContext *>(_localctx)->dataTypeContext = dataType();
    setState(132);
    antlrcpp::downCast<FunctionContext *>(_localctx)->identifierContext = identifier();
    setState(133);
    match(GrammarParser::T__1);
    setState(134);
    antlrcpp::downCast<FunctionContext *>(_localctx)->functionParametersContext = functionParameters();
    setState(135);
    match(GrammarParser::T__2);
    setState(136);
    antlrcpp::downCast<FunctionContext *>(_localctx)->blockContext = block();

    			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<FunctionContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>();
    			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<FunctionContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
    			ReferencePtr<ListNode<FunctionParameterNode>> params = antlrcpp::downCast<FunctionContext *>(_localctx)->functionParametersContext->m_node.cast<ListNode<FunctionParameterNode>>();
    			ReferencePtr<BlockNode> blk = antlrcpp::downCast<FunctionContext *>(_localctx)->blockContext->m_node.cast<BlockNode>();
    			_localctx->m_node = new FunctionNode{dtn,in,params,blk};
    		
   
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
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 22) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 22)) & 4398046519295) != 0)) {
      setState(139);
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
      antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::T__8) {
        setState(140);
        match(GrammarParser::T__8);
        setState(141);
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext = functionParameter();
        antlrcpp::downCast<FunctionParametersContext *>(_localctx)->parameters.push_back(antlrcpp::downCast<FunctionParametersContext *>(_localctx)->functionParameterContext);
        setState(146);
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
    setState(151);
    antlrcpp::downCast<FunctionParameterContext *>(_localctx)->dataTypeContext = dataType();
    setState(152);
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
    setState(155);
    antlrcpp::downCast<FunctionCallContext *>(_localctx)->identifierContext = identifier();
    setState(156);
    match(GrammarParser::T__1);
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & 5701559103936544769) != 0)) {
      setState(157);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->argumentListContext = argumentList();
    }
    setState(160);
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
    setState(163);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
    antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__8) {
      setState(164);
      match(GrammarParser::T__8);
      setState(165);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext = expr(0);
      antlrcpp::downCast<ArgumentListContext *>(_localctx)->arguments.push_back(antlrcpp::downCast<ArgumentListContext *>(_localctx)->exprContext);
      setState(170);
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
    setState(173);
    match(GrammarParser::T__9);
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -126096803837736341) != 0)) {
      setState(174);
      antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext = stmt();
      antlrcpp::downCast<BlockContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext);
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(180);
    match(GrammarParser::T__10);

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
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(183);
      antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext = declaration();
      setState(184);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext->m_node;
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext = functionCall();
      setState(188);
      match(GrammarParser::T__4);

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->functionCallContext->m_node;
      			
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(191);
      antlrcpp::downCast<StmtContext *>(_localctx)->returnContext = return_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->returnContext->m_node;
      			
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(194);
      antlrcpp::downCast<StmtContext *>(_localctx)->ifContext = if_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->ifContext->m_node;
      			
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(197);
      antlrcpp::downCast<StmtContext *>(_localctx)->whileContext = while_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->whileContext->m_node;
      			
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(200);
      antlrcpp::downCast<StmtContext *>(_localctx)->forContext = for_();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->forContext->m_node;
      			
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(203);
      antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext = doWhile();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->doWhileContext->m_node;
      			
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(206);
      antlrcpp::downCast<StmtContext *>(_localctx)->blockContext = block();

      				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->blockContext->m_node;
      			
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(209);
      match(GrammarParser::BREAK);
      setState(210);
      match(GrammarParser::T__4);

      				_localctx->m_node = new BreakNode{};
      			
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(212);
      match(GrammarParser::CONTINUE);
      setState(213);
      match(GrammarParser::T__4);

      				_localctx->m_node = new ContinueNode{};
      			
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(215);
      match(GrammarParser::T__11);
      setState(216);
      match(GrammarParser::T__1);
      setState(217);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(218);
      match(GrammarParser::T__2);
      setState(219);
      match(GrammarParser::T__4);

      				_localctx->m_node = new PrintNode{antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->m_node};
      			
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(222);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(223);
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
    setState(228);
    match(GrammarParser::T__9);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 22) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 22)) & 4398046519295) != 0)) {
      setState(229);
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext = memberDecl();
      antlrcpp::downCast<BlockDeclContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockDeclContext *>(_localctx)->memberDeclContext);
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(235);
    match(GrammarParser::T__10);

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
    setState(238);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->dataTypeContext = dataType();
    setState(239);
    antlrcpp::downCast<MemberDeclContext *>(_localctx)->identifierContext = identifier();
    setState(240);
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
    setState(243);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->dataTypeContext = dataType();
    setState(244);
    antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
    antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__8) {
      setState(245);
      match(GrammarParser::T__8);
      setState(246);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext = declarationListItem();
      antlrcpp::downCast<DeclarationContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationContext *>(_localctx)->declarationListItemContext);
      setState(251);
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
    setState(263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(254);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();

      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			_localctx -> m_node = new DeclarationListItemNode{in};
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(257);
      antlrcpp::downCast<DeclarationListItemContext *>(_localctx)->identifierContext = identifier();
      setState(258);
      match(GrammarParser::T__12);
      setState(259);
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
    setState(265);
    match(GrammarParser::T__13);
    setState(266);
    antlrcpp::downCast<StructDeclContext *>(_localctx)->identifierContext = identifier();
    setState(267);
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
    setState(270);
    match(GrammarParser::T__14);
    setState(271);
    antlrcpp::downCast<UnionDeclContext *>(_localctx)->identifierContext = identifier();
    setState(272);
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
    setState(281);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__21:
      case GrammarParser::T__22:
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
      case GrammarParser::T__33: {
        enterOuterAlt(_localctx, 1);
        setState(275);
        antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext = basicType();
         _localctx->m_node = antlrcpp::downCast<FundamentalTypeContext *>(_localctx)->basicTypeContext->m_node; 
        break;
      }

      case GrammarParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(278);
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
    setState(283);
    antlrcpp::downCast<DataTypeContext *>(_localctx)->ft = fundamentalType();
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3866624) != 0)) {
      setState(284);
      antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext = typeModifier();
      antlrcpp::downCast<DataTypeContext *>(_localctx)->modifier_list.push_back(antlrcpp::downCast<DataTypeContext *>(_localctx)->typeModifierContext);
      setState(289);
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
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__15: {
        enterOuterAlt(_localctx, 1);
        setState(292);
        match(GrammarParser::T__15);
        _localctx->m_node = new PointerNode{}; 
        break;
      }

      case GrammarParser::T__16: {
        enterOuterAlt(_localctx, 2);
        setState(294);
        match(GrammarParser::T__16);

        setState(295);
        antlrcpp::downCast<TypeModifierContext *>(_localctx)->e = expr(0);
        setState(296);
        match(GrammarParser::T__17);
         _localctx->m_node = new ArrayNode{ antlrcpp::downCast<TypeModifierContext *>(_localctx)->e->m_node }; 
        break;
      }

      case GrammarParser::T__18: {
        enterOuterAlt(_localctx, 3);
        setState(299);
        match(GrammarParser::T__18);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::CONST}; 
        break;
      }

      case GrammarParser::T__19: {
        enterOuterAlt(_localctx, 4);
        setState(301);
        match(GrammarParser::T__19);
         _localctx->m_node = new QualifierNode{IRQualifiersNode::VOLATILE}; 
        break;
      }

      case GrammarParser::T__20: {
        enterOuterAlt(_localctx, 5);
        setState(303);
        match(GrammarParser::T__20);
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
    setState(333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__21: {
        enterOuterAlt(_localctx, 1);
        setState(307);
        match(GrammarParser::T__21);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__22: {
        enterOuterAlt(_localctx, 2);
        setState(309);
        match(GrammarParser::T__22);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT8}; 
        break;
      }

      case GrammarParser::T__23: {
        enterOuterAlt(_localctx, 3);
        setState(311);
        match(GrammarParser::T__23);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT16}; 
        break;
      }

      case GrammarParser::T__24: {
        enterOuterAlt(_localctx, 4);
        setState(313);
        match(GrammarParser::T__24);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; 
        break;
      }

      case GrammarParser::T__25: {
        enterOuterAlt(_localctx, 5);
        setState(315);
        match(GrammarParser::T__25);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::INT64}; 
        break;
      }

      case GrammarParser::T__26: {
        enterOuterAlt(_localctx, 6);
        setState(317);
        match(GrammarParser::T__26);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT8}; 
        break;
      }

      case GrammarParser::T__27: {
        enterOuterAlt(_localctx, 7);
        setState(319);
        match(GrammarParser::T__27);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT16}; 
        break;
      }

      case GrammarParser::T__28: {
        enterOuterAlt(_localctx, 8);
        setState(321);
        match(GrammarParser::T__28);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT32}; 
        break;
      }

      case GrammarParser::T__29: {
        enterOuterAlt(_localctx, 9);
        setState(323);
        match(GrammarParser::T__29);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::UINT64}; 
        break;
      }

      case GrammarParser::T__30: {
        enterOuterAlt(_localctx, 10);
        setState(325);
        match(GrammarParser::T__30);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::FLOAT}; 
        break;
      }

      case GrammarParser::T__31: {
        enterOuterAlt(_localctx, 11);
        setState(327);
        match(GrammarParser::T__31);
         _localctx -> m_node = new BasicTypeNode{IRBasicType::DOUBLE}; 
        break;
      }

      case GrammarParser::T__32: {
        enterOuterAlt(_localctx, 12);
        setState(329);
        match(GrammarParser::T__32);
         _localctx->m_node = new BasicTypeNode{IRBasicType::BOOL}; 
        break;
      }

      case GrammarParser::T__33: {
        enterOuterAlt(_localctx, 13);
        setState(331);
        match(GrammarParser::T__33);
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
    setState(335);
    match(GrammarParser::T__34);
    setState(337);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & 5701559103936544769) != 0)) {
      setState(336);
      antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext = expr(0);
    }
    setState(339);
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
    setState(342);
    match(GrammarParser::T__35);
    setState(343);
    match(GrammarParser::T__1);
    setState(344);
    antlrcpp::downCast<SizeOfContext *>(_localctx)->dataTypeContext = dataType();
    setState(345);
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
    setState(348);
    match(GrammarParser::T__36);
    setState(349);
    match(GrammarParser::T__1);
    setState(350);
    antlrcpp::downCast<AssertConditionContext *>(_localctx)->exprContext = expr(0);
    setState(351);
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
    setState(410);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(355);
      match(GrammarParser::T__1);
      setState(356);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(357);
      match(GrammarParser::T__2);
      setState(358);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(26);

      			_localctx->m_node = new CastNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 2: {
      setState(361);
      match(GrammarParser::T__39);
      setState(362);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(21);

      			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 3: {
      setState(365);
      match(GrammarParser::T__40);
      setState(366);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(19);

      			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,false};
      		
      break;
    }

    case 4: {
      setState(369);
      match(GrammarParser::T__41);

      setState(370);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);

      			_localctx->m_node = new BooleanNotNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 5: {
      setState(373);
      match(GrammarParser::T__15);
      setState(374);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(17);

      			_localctx->m_node = new DereferenceNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 6: {
      setState(377);
      match(GrammarParser::T__20);
      setState(378);
      antlrcpp::downCast<ExprContext *>(_localctx)->e = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(16);

      			_localctx->m_node = new AddressOfNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node};
      		
      break;
    }

    case 7: {
      setState(381);
      antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext = functionCall();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->functionCallContext->m_node; 
      break;
    }

    case 8: {
      setState(384);
      antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext->m_node; 
      break;
    }

    case 9: {
      setState(387);
      antlrcpp::downCast<ExprContext *>(_localctx)->numberContext = number();
       _localctx -> m_node = antlrcpp::downCast<ExprContext *>(_localctx)->numberContext->m_node; 
      break;
    }

    case 10: {
      setState(390);
      match(GrammarParser::T__1);
      setState(391);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(392);
      match(GrammarParser::T__2);
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node; 
      break;
    }

    case 11: {
      setState(395);
      match(GrammarParser::T__54);
      setState(396);
      match(GrammarParser::T__47);
      setState(397);
      antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext = dataType();
      setState(398);
      match(GrammarParser::T__45);
      setState(399);
      match(GrammarParser::T__1);
      setState(400);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(401);
      match(GrammarParser::T__2);

      			_localctx->m_node = new ReinterpretNode{antlrcpp::downCast<ExprContext *>(_localctx)->dataTypeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    case 12: {
      setState(404);
      antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext = sizeOf();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->sizeOfContext->m_node; 
      break;
    }

    case 13: {
      setState(407);
      antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext = assertCondition();
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->assertConditionContext->m_node; 
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(476);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(474);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(412);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(413);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__15

          || _la == GrammarParser::T__42)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(414);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(16);
           
                    			char oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data()[0];
                    			OperationType basicType;
                    			switch(oper){
                    			case '*':
                    				basicType = OperationType::MUL;
                    				break;
                    			case '/':
                    				basicType = OperationType::DIV;
                    				break;
                    			}
                    			_localctx -> m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node, basicType }; 
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(417);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(418);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__43

          || _la == GrammarParser::T__44)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(419);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(15);
           
                    			char oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data()[0];
                    			OperationType basicType;
                    			switch(oper){
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
          setState(422);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(423);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4433230883192832) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(424);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(14);

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

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(427);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(428);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__51);
          setState(429);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(13);

                    			_localctx->m_node = new AndNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(432);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(433);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__52);
          setState(434);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(12);

                    			_localctx->m_node = new OrNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node};
                    		
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(437);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(438);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__20);
          setState(439);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(11);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_AND};
                    		
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(442);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(443);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = match(GrammarParser::T__53);
          setState(444);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(10);

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,OperationType::BITWISE_OR};
                    		
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left_expr = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(447);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(448);
          match(GrammarParser::T__12);
          setState(449);
          antlrcpp::downCast<ExprContext *>(_localctx)->right_expr = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(7);

                    			_localctx->m_node = new AssignmentNode{antlrcpp::downCast<ExprContext *>(_localctx)->left_expr->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right_expr->m_node};
                    		
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->array_id = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(452);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(453);
          match(GrammarParser::T__16);
          setState(454);
          antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
          setState(455);
          match(GrammarParser::T__17);

                    			_localctx->m_node = new ArrayAccessNode{antlrcpp::downCast<ExprContext *>(_localctx)->array_id->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
                    		
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->new_left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(458);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(459);
          match(GrammarParser::T__37);
          setState(460);
          antlrcpp::downCast<ExprContext *>(_localctx)->field = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
           // dotMemberAccess
                    			ReferencePtr<AbstractSyntaxTreeNode> expr_node = antlrcpp::downCast<ExprContext *>(_localctx)->new_left->m_node;
                    			ReferencePtr<IdentifierNode> field_id_node = antlrcpp::downCast<ExprContext *>(_localctx)->field->m_node.cast<IdentifierNode>(); 
                    			
                    			_localctx->m_node = new MemberAccessNode{expr_node,field_id_node,false};
                    		
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->new_left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(463);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(464);
          match(GrammarParser::T__38);
          setState(465);
          antlrcpp::downCast<ExprContext *>(_localctx)->field = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
           // arrowMemberAccess
                    			ReferencePtr<AbstractSyntaxTreeNode> expr_node = antlrcpp::downCast<ExprContext *>(_localctx)->new_left->m_node; 
                    			ReferencePtr<IdentifierNode> field_id_node = antlrcpp::downCast<ExprContext *>(_localctx)->field->m_node.cast<IdentifierNode>();
                    			
                    			_localctx->m_node = new MemberAccessNode{expr_node,field_id_node,true};
                    		
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(468);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(469);
          match(GrammarParser::T__39);

                    			_localctx->m_node = new IncrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(471);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(472);
          match(GrammarParser::T__40);

                    			_localctx->m_node = new DecrementationNode{antlrcpp::downCast<ExprContext *>(_localctx)->e->m_node,true};
                    		
          break;
        }

        default:
          break;
        } 
      }
      setState(478);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
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
  enterRule(_localctx, 56, GrammarParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(487);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(479);
        antlrcpp::downCast<NumberContext *>(_localctx)->intToken = match(GrammarParser::INT);
         
        				_localctx -> m_node = new ConstantNode{ std::atoi(antlrcpp::downCast<NumberContext *>(_localctx)->intToken -> getText().data()) }; 
        			
        break;
      }

      case GrammarParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(481);
        antlrcpp::downCast<NumberContext *>(_localctx)->floatToken = match(GrammarParser::FLOAT);

        				_localctx -> m_node = new ConstantNode{(float) std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->floatToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::DOUBLE: {
        enterOuterAlt(_localctx, 3);
        setState(483);
        antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken = match(GrammarParser::DOUBLE);

        				_localctx -> m_node = new ConstantNode{ std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->doubleToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::BOOL: {
        enterOuterAlt(_localctx, 4);
        setState(485);
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
  enterRule(_localctx, 58, GrammarParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
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
    case 0: return precpred(_ctx, 15);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 6);
    case 8: return precpred(_ctx, 25);
    case 9: return precpred(_ctx, 24);
    case 10: return precpred(_ctx, 23);
    case 11: return precpred(_ctx, 22);
    case 12: return precpred(_ctx, 20);

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
