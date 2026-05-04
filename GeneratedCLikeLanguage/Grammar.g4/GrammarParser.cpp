
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
      "while", "if", "prog", "block", "stmt", "declarations", "declaration", 
      "assignments", "assignment", "type", "return", "expr", "number", "identifier"
    },
    std::vector<std::string>{
      "", "'while'", "'('", "')'", "'if'", "'else'", "'{'", "'}'", "';'", 
      "'='", "'int'", "'float'", "'bool'", "'return'", "'/'", "'*'", "'+'", 
      "'-'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "WS", "INT", "FLOAT", "BOOL", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,28,187,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,43,8,1,1,1,1,1,1,
  	2,5,2,48,8,2,10,2,12,2,51,9,2,1,2,1,2,1,3,1,3,5,3,57,8,3,10,3,12,3,60,
  	9,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,3,4,83,8,4,1,5,5,5,86,8,5,10,5,12,5,89,9,5,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,105,8,6,1,7,5,7,108,
  	8,7,10,7,12,7,111,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,3,9,127,8,9,1,10,1,10,3,10,131,8,10,1,10,1,10,1,10,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,3,11,154,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,5,11,171,8,11,10,11,12,11,174,9,11,1,12,
  	1,12,1,12,1,12,1,12,1,12,3,12,182,8,12,1,13,1,13,1,13,1,13,0,1,22,14,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,0,3,1,0,14,15,1,0,16,17,1,0,18,23,
  	194,0,28,1,0,0,0,2,35,1,0,0,0,4,49,1,0,0,0,6,54,1,0,0,0,8,82,1,0,0,0,
  	10,87,1,0,0,0,12,104,1,0,0,0,14,109,1,0,0,0,16,114,1,0,0,0,18,126,1,0,
  	0,0,20,128,1,0,0,0,22,153,1,0,0,0,24,181,1,0,0,0,26,183,1,0,0,0,28,29,
  	5,1,0,0,29,30,5,2,0,0,30,31,3,22,11,0,31,32,5,3,0,0,32,33,3,8,4,0,33,
  	34,6,0,-1,0,34,1,1,0,0,0,35,36,5,4,0,0,36,37,5,2,0,0,37,38,3,22,11,0,
  	38,39,5,3,0,0,39,42,3,8,4,0,40,41,5,5,0,0,41,43,3,8,4,0,42,40,1,0,0,0,
  	42,43,1,0,0,0,43,44,1,0,0,0,44,45,6,1,-1,0,45,3,1,0,0,0,46,48,3,8,4,0,
  	47,46,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,52,1,0,0,0,
  	51,49,1,0,0,0,52,53,6,2,-1,0,53,5,1,0,0,0,54,58,5,6,0,0,55,57,3,8,4,0,
  	56,55,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,61,1,0,0,0,
  	60,58,1,0,0,0,61,62,5,7,0,0,62,63,6,3,-1,0,63,7,1,0,0,0,64,65,3,12,6,
  	0,65,66,6,4,-1,0,66,83,1,0,0,0,67,68,3,16,8,0,68,69,6,4,-1,0,69,83,1,
  	0,0,0,70,71,3,20,10,0,71,72,6,4,-1,0,72,83,1,0,0,0,73,74,3,2,1,0,74,75,
  	6,4,-1,0,75,83,1,0,0,0,76,77,3,0,0,0,77,78,6,4,-1,0,78,83,1,0,0,0,79,
  	80,3,6,3,0,80,81,6,4,-1,0,81,83,1,0,0,0,82,64,1,0,0,0,82,67,1,0,0,0,82,
  	70,1,0,0,0,82,73,1,0,0,0,82,76,1,0,0,0,82,79,1,0,0,0,83,9,1,0,0,0,84,
  	86,3,12,6,0,85,84,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,
  	90,1,0,0,0,89,87,1,0,0,0,90,91,6,5,-1,0,91,11,1,0,0,0,92,93,3,18,9,0,
  	93,94,3,26,13,0,94,95,5,8,0,0,95,96,6,6,-1,0,96,105,1,0,0,0,97,98,3,18,
  	9,0,98,99,3,26,13,0,99,100,5,9,0,0,100,101,3,22,11,0,101,102,5,8,0,0,
  	102,103,6,6,-1,0,103,105,1,0,0,0,104,92,1,0,0,0,104,97,1,0,0,0,105,13,
  	1,0,0,0,106,108,3,16,8,0,107,106,1,0,0,0,108,111,1,0,0,0,109,107,1,0,
  	0,0,109,110,1,0,0,0,110,112,1,0,0,0,111,109,1,0,0,0,112,113,6,7,-1,0,
  	113,15,1,0,0,0,114,115,3,26,13,0,115,116,5,9,0,0,116,117,3,22,11,0,117,
  	118,5,8,0,0,118,119,6,8,-1,0,119,17,1,0,0,0,120,121,5,10,0,0,121,127,
  	6,9,-1,0,122,123,5,11,0,0,123,127,6,9,-1,0,124,125,5,12,0,0,125,127,6,
  	9,-1,0,126,120,1,0,0,0,126,122,1,0,0,0,126,124,1,0,0,0,127,19,1,0,0,0,
  	128,130,5,13,0,0,129,131,3,22,11,0,130,129,1,0,0,0,130,131,1,0,0,0,131,
  	132,1,0,0,0,132,133,5,8,0,0,133,134,6,10,-1,0,134,21,1,0,0,0,135,136,
  	6,11,-1,0,136,137,3,26,13,0,137,138,6,11,-1,0,138,154,1,0,0,0,139,140,
  	3,24,12,0,140,141,6,11,-1,0,141,154,1,0,0,0,142,143,5,2,0,0,143,144,3,
  	22,11,0,144,145,5,3,0,0,145,146,6,11,-1,0,146,154,1,0,0,0,147,148,5,2,
  	0,0,148,149,3,18,9,0,149,150,5,3,0,0,150,151,3,22,11,1,151,152,6,11,-1,
  	0,152,154,1,0,0,0,153,135,1,0,0,0,153,139,1,0,0,0,153,142,1,0,0,0,153,
  	147,1,0,0,0,154,172,1,0,0,0,155,156,10,7,0,0,156,157,7,0,0,0,157,158,
  	3,22,11,8,158,159,6,11,-1,0,159,171,1,0,0,0,160,161,10,6,0,0,161,162,
  	7,1,0,0,162,163,3,22,11,7,163,164,6,11,-1,0,164,171,1,0,0,0,165,166,10,
  	5,0,0,166,167,7,2,0,0,167,168,3,22,11,6,168,169,6,11,-1,0,169,171,1,0,
  	0,0,170,155,1,0,0,0,170,160,1,0,0,0,170,165,1,0,0,0,171,174,1,0,0,0,172,
  	170,1,0,0,0,172,173,1,0,0,0,173,23,1,0,0,0,174,172,1,0,0,0,175,176,5,
  	25,0,0,176,182,6,12,-1,0,177,178,5,26,0,0,178,182,6,12,-1,0,179,180,5,
  	27,0,0,180,182,6,12,-1,0,181,175,1,0,0,0,181,177,1,0,0,0,181,179,1,0,
  	0,0,182,25,1,0,0,0,183,184,5,28,0,0,184,185,6,13,-1,0,185,27,1,0,0,0,
  	13,42,49,58,82,87,104,109,126,130,153,170,172,181
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
    setState(28);
    match(GrammarParser::T__0);
    setState(29);
    match(GrammarParser::T__1);
    setState(30);
    antlrcpp::downCast<WhileContext *>(_localctx)->exprContext = expr(0);
    setState(31);
    match(GrammarParser::T__2);
    setState(32);
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
  enterRule(_localctx, 2, GrammarParser::RuleIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(GrammarParser::T__3);
    setState(36);
    match(GrammarParser::T__1);
    setState(37);
    antlrcpp::downCast<IfContext *>(_localctx)->exprContext = expr(0);
    setState(38);
    match(GrammarParser::T__2);
    setState(39);
    antlrcpp::downCast<IfContext *>(_localctx)->stmt_1 = stmt();
    setState(42);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(40);
      match(GrammarParser::T__4);
      setState(41);
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

std::vector<GrammarParser::StmtContext *> GrammarParser::ProgContext::stmt() {
  return getRuleContexts<GrammarParser::StmtContext>();
}

GrammarParser::StmtContext* GrammarParser::ProgContext::stmt(size_t i) {
  return getRuleContext<GrammarParser::StmtContext>(i);
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
  enterRule(_localctx, 4, GrammarParser::RuleProg);
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
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 268450898) != 0)) {
      setState(46);
      antlrcpp::downCast<ProgContext *>(_localctx)->stmtContext = stmt();
      antlrcpp::downCast<ProgContext *>(_localctx)->items.push_back(antlrcpp::downCast<ProgContext *>(_localctx)->stmtContext);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
    			for(auto *stmt : antlrcpp::downCast<ProgContext *>(_localctx)->items){
    				list->add(stmt->m_node);
    			}

    			_localctx->m_node = new ProgNode{list};
    		
   
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
  enterRule(_localctx, 6, GrammarParser::RuleBlock);
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
    setState(54);
    match(GrammarParser::T__5);
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 268450898) != 0)) {
      setState(55);
      antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext = stmt();
      antlrcpp::downCast<BlockContext *>(_localctx)->items.push_back(antlrcpp::downCast<BlockContext *>(_localctx)->stmtContext);
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
    match(GrammarParser::T__6);

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

GrammarParser::AssignmentContext* GrammarParser::StmtContext::assignment() {
  return getRuleContext<GrammarParser::AssignmentContext>(0);
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

GrammarParser::BlockContext* GrammarParser::StmtContext::block() {
  return getRuleContext<GrammarParser::BlockContext>(0);
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
  enterRule(_localctx, 8, GrammarParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__9:
      case GrammarParser::T__10:
      case GrammarParser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(64);
        antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext = declaration();

        				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->declarationContext->m_node;
        			
        break;
      }

      case GrammarParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(67);
        antlrcpp::downCast<StmtContext *>(_localctx)->assignmentContext = assignment();

        				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->assignmentContext->m_node;
        			
        break;
      }

      case GrammarParser::T__12: {
        enterOuterAlt(_localctx, 3);
        setState(70);
        antlrcpp::downCast<StmtContext *>(_localctx)->returnContext = return_();

        				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->returnContext->m_node;
        			
        break;
      }

      case GrammarParser::T__3: {
        enterOuterAlt(_localctx, 4);
        setState(73);
        antlrcpp::downCast<StmtContext *>(_localctx)->ifContext = if_();

        				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->ifContext->m_node;
        			
        break;
      }

      case GrammarParser::T__0: {
        enterOuterAlt(_localctx, 5);
        setState(76);
        antlrcpp::downCast<StmtContext *>(_localctx)->whileContext = while_();

        				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->whileContext->m_node;
        			
        break;
      }

      case GrammarParser::T__5: {
        enterOuterAlt(_localctx, 6);
        setState(79);
        antlrcpp::downCast<StmtContext *>(_localctx)->blockContext = block();

        				_localctx->m_node = antlrcpp::downCast<StmtContext *>(_localctx)->blockContext->m_node;
        			
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

//----------------- DeclarationsContext ------------------------------------------------------------------

GrammarParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::DeclarationContext *> GrammarParser::DeclarationsContext::declaration() {
  return getRuleContexts<GrammarParser::DeclarationContext>();
}

GrammarParser::DeclarationContext* GrammarParser::DeclarationsContext::declaration(size_t i) {
  return getRuleContext<GrammarParser::DeclarationContext>(i);
}


size_t GrammarParser::DeclarationsContext::getRuleIndex() const {
  return GrammarParser::RuleDeclarations;
}

void GrammarParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void GrammarParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

GrammarParser::DeclarationsContext* GrammarParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, GrammarParser::RuleDeclarations);
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
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7168) != 0)) {
      setState(84);
      antlrcpp::downCast<DeclarationsContext *>(_localctx)->declarationContext = declaration();
      antlrcpp::downCast<DeclarationsContext *>(_localctx)->items.push_back(antlrcpp::downCast<DeclarationsContext *>(_localctx)->declarationContext);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<ListNode<DeclarationNode>> list = new ListNode<DeclarationNode>{};
    			for(auto *decl : antlrcpp::downCast<DeclarationsContext *>(_localctx)->items)
    				list->add(decl->m_node.cast<DeclarationNode>());

    			_localctx->m_node = list;
    		
   
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

GrammarParser::TypeContext* GrammarParser::DeclarationContext::type() {
  return getRuleContext<GrammarParser::TypeContext>(0);
}

GrammarParser::IdentifierContext* GrammarParser::DeclarationContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::ExprContext* GrammarParser::DeclarationContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
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
  enterRule(_localctx, 12, GrammarParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->typeContext = type();
      setState(93);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->identifierContext = identifier();
      setState(94);
      match(GrammarParser::T__7);
       
      			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<DeclarationContext *>(_localctx)->typeContext->m_node.cast<DataTypeNode>();
      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();

      			_localctx -> m_node = new DeclarationNode{dtn,in};
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(97);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->typeContext = type();
      setState(98);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->identifierContext = identifier();
      setState(99);
      match(GrammarParser::T__8);
      setState(100);
      antlrcpp::downCast<DeclarationContext *>(_localctx)->exprContext = expr(0);
      setState(101);
      match(GrammarParser::T__7);

      			ReferencePtr<DataTypeNode> dtn = antlrcpp::downCast<DeclarationContext *>(_localctx)->typeContext->m_node.cast<DataTypeNode>();
      			ReferencePtr<IdentifierNode> in = antlrcpp::downCast<DeclarationContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();
      			
      			_localctx->m_node = new DeclarationNode{dtn,in,antlrcpp::downCast<DeclarationContext *>(_localctx)->exprContext->m_node};
      		
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

//----------------- AssignmentsContext ------------------------------------------------------------------

GrammarParser::AssignmentsContext::AssignmentsContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

std::vector<GrammarParser::AssignmentContext *> GrammarParser::AssignmentsContext::assignment() {
  return getRuleContexts<GrammarParser::AssignmentContext>();
}

GrammarParser::AssignmentContext* GrammarParser::AssignmentsContext::assignment(size_t i) {
  return getRuleContext<GrammarParser::AssignmentContext>(i);
}


size_t GrammarParser::AssignmentsContext::getRuleIndex() const {
  return GrammarParser::RuleAssignments;
}

void GrammarParser::AssignmentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignments(this);
}

void GrammarParser::AssignmentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignments(this);
}

GrammarParser::AssignmentsContext* GrammarParser::assignments() {
  AssignmentsContext *_localctx = _tracker.createInstance<AssignmentsContext>(_ctx, getState());
  enterRule(_localctx, 14, GrammarParser::RuleAssignments);
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
    while (_la == GrammarParser::ID) {
      setState(106);
      antlrcpp::downCast<AssignmentsContext *>(_localctx)->assignmentContext = assignment();
      antlrcpp::downCast<AssignmentsContext *>(_localctx)->items.push_back(antlrcpp::downCast<AssignmentsContext *>(_localctx)->assignmentContext);
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    			ReferencePtr<ListNode<AssignmentNode>> list = new ListNode<AssignmentNode>{};
    			for(auto *assignment : antlrcpp::downCast<AssignmentsContext *>(_localctx)->items)
    				list->add(assignment->m_node.cast<AssignmentNode>());

    			_localctx->m_node = list;
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

GrammarParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::AssignmentContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::ExprContext* GrammarParser::AssignmentContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::AssignmentContext::getRuleIndex() const {
  return GrammarParser::RuleAssignment;
}

void GrammarParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void GrammarParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

GrammarParser::AssignmentContext* GrammarParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 16, GrammarParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    antlrcpp::downCast<AssignmentContext *>(_localctx)->identifierContext = identifier();
    setState(115);
    match(GrammarParser::T__8);
    setState(116);
    antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext = expr(0);
    setState(117);
    match(GrammarParser::T__7);

    			//IdentifierNode *id_node = static_cast<IdentifierNode*>(antlrcpp::downCast<AssignmentContext *>(_localctx)->identifierContext->m_node);
    			ReferencePtr<IdentifierNode> id_node = antlrcpp::downCast<AssignmentContext *>(_localctx)->identifierContext->m_node.cast<IdentifierNode>();

    			_localctx -> m_node = new AssignmentNode{id_node,antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext->m_node};
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

GrammarParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}


size_t GrammarParser::TypeContext::getRuleIndex() const {
  return GrammarParser::RuleType;
}

void GrammarParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void GrammarParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

GrammarParser::TypeContext* GrammarParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 18, GrammarParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        match(GrammarParser::T__9);
         _localctx -> m_node = new DataTypeNode{DataType::INT}; 
        break;
      }

      case GrammarParser::T__10: {
        enterOuterAlt(_localctx, 2);
        setState(122);
        match(GrammarParser::T__10);
         _localctx -> m_node = new DataTypeNode{DataType::FLOAT}; 
        break;
      }

      case GrammarParser::T__11: {
        enterOuterAlt(_localctx, 3);
        setState(124);
        match(GrammarParser::T__11);
         _localctx->m_node = new DataTypeNode{DataType::BOOL}; 
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
  enterRule(_localctx, 20, GrammarParser::RuleReturn);
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
    setState(128);
    match(GrammarParser::T__12);
    setState(130);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 503316484) != 0)) {
      setState(129);
      antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext = expr(0);
    }
    setState(132);
    match(GrammarParser::T__7);
     _localctx -> m_node = new ReturnNode{antlrcpp::downCast<ReturnContext *>(_localctx)->exprContext->m_node}; 
   
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

GrammarParser::IdentifierContext* GrammarParser::ExprContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::NumberContext* GrammarParser::ExprContext::number() {
  return getRuleContext<GrammarParser::NumberContext>(0);
}

std::vector<GrammarParser::ExprContext *> GrammarParser::ExprContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::ExprContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}

GrammarParser::TypeContext* GrammarParser::ExprContext::type() {
  return getRuleContext<GrammarParser::TypeContext>(0);
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, GrammarParser::RuleExpr, precedence);

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
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(136);
      antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext = identifier();
       _localctx -> m_node = antlrcpp::downCast<ExprContext *>(_localctx)->identifierContext->m_node; 
      break;
    }

    case 2: {
      setState(139);
      antlrcpp::downCast<ExprContext *>(_localctx)->numberContext = number();
       _localctx -> m_node = antlrcpp::downCast<ExprContext *>(_localctx)->numberContext->m_node; 
      break;
    }

    case 3: {
      setState(142);
      match(GrammarParser::T__1);
      setState(143);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(144);
      match(GrammarParser::T__2);
       _localctx->m_node = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node; 
      break;
    }

    case 4: {
      setState(147);
      match(GrammarParser::T__1);
      setState(148);
      antlrcpp::downCast<ExprContext *>(_localctx)->typeContext = type();
      setState(149);
      match(GrammarParser::T__2);
      setState(150);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(1);

      			_localctx->m_node = new CastNode{antlrcpp::downCast<ExprContext *>(_localctx)->typeContext->m_node.cast<DataTypeNode>(),antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->m_node};
      		
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(172);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(170);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(155);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(156);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__13

          || _la == GrammarParser::T__14)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(157);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(8);
           
                    			char oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data()[0];
                    			OperationType type;
                    			switch(oper){
                    			case '*':
                    				type = OperationType::MUL;
                    				break;
                    			case '/':
                    				type = OperationType::DIV;
                    				break;
                    			}
                    			_localctx -> m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node, type }; 
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(160);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(161);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == GrammarParser::T__15

          || _la == GrammarParser::T__16)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(162);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(7);
           
                    			char oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data()[0];
                    			OperationType type;
                    			switch(oper){
                    			case '+':
                    				type = OperationType::ADD;
                    				break;
                    			case '-':
                    				type = OperationType::SUB;
                    				break;
                    			}

                    			_localctx -> m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node, type }; 
                    		
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(165);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(166);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 16515072) != 0))) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(167);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(6);

                    			std::string oper = antlrcpp::downCast<ExprContext *>(_localctx)->op->getText().data();
                    			OperationType type;

                    			if(oper == ">")
                    				type = OperationType::GT;
                    			else if (oper == ">=")
                    				type = OperationType::GE;
                    			else if (oper == "<")
                    				type = OperationType::LT;
                    			else if (oper == "<=")
                    				type = OperationType::GE;
                    			else if (oper == "==")
                    				type = OperationType::EQ;
                    			else if (oper == "!=")
                    				type = OperationType::NEQ;

                    			_localctx->m_node = new BinaryOperatorNode{antlrcpp::downCast<ExprContext *>(_localctx)->left->m_node,antlrcpp::downCast<ExprContext *>(_localctx)->right->m_node,type};
                    		
          break;
        }

        default:
          break;
        } 
      }
      setState(174);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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
  enterRule(_localctx, 24, GrammarParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        antlrcpp::downCast<NumberContext *>(_localctx)->intToken = match(GrammarParser::INT);
         
        				_localctx -> m_node = new ConstantNode{ std::atoi(antlrcpp::downCast<NumberContext *>(_localctx)->intToken -> getText().data()) }; 
        			
        break;
      }

      case GrammarParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(177);
        antlrcpp::downCast<NumberContext *>(_localctx)->floatToken = match(GrammarParser::FLOAT);

        				_localctx -> m_node = new ConstantNode{(float) std::atof(antlrcpp::downCast<NumberContext *>(_localctx)->floatToken -> getText().data()) };
        			
        break;
      }

      case GrammarParser::BOOL: {
        enterOuterAlt(_localctx, 3);
        setState(179);
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
  enterRule(_localctx, 26, GrammarParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
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
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GrammarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);

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
