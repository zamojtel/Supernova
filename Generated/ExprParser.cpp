
// Generated from Expr.g4 by ANTLR 4.13.2


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExprParserStaticData final {
  ExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExprParserStaticData(const ExprParserStaticData&) = delete;
  ExprParserStaticData(ExprParserStaticData&&) = delete;
  ExprParserStaticData& operator=(const ExprParserStaticData&) = delete;
  ExprParserStaticData& operator=(ExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag exprParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ExprParserStaticData> exprParserStaticData = nullptr;

void exprParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (exprParserStaticData != nullptr) {
    return;
  }
#else
  assert(exprParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ExprParserStaticData>(
    std::vector<std::string>{
      "prog", "expr", "integer"
    },
    std::vector<std::string>{
      "", "'*'", "'/'", "'+'", "'-'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "NEWLINE", "INT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,8,37,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,3,1,19,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,29,8,1,10,
  	1,12,1,32,9,1,1,2,1,2,1,2,1,2,0,1,2,3,0,2,4,0,2,1,0,1,2,1,0,3,4,36,0,
  	6,1,0,0,0,2,18,1,0,0,0,4,33,1,0,0,0,6,7,3,2,1,0,7,8,5,0,0,1,8,9,6,0,-1,
  	0,9,1,1,0,0,0,10,11,6,1,-1,0,11,12,3,4,2,0,12,13,6,1,-1,0,13,19,1,0,0,
  	0,14,15,5,5,0,0,15,16,3,2,1,0,16,17,5,6,0,0,17,19,1,0,0,0,18,10,1,0,0,
  	0,18,14,1,0,0,0,19,30,1,0,0,0,20,21,10,4,0,0,21,22,7,0,0,0,22,29,3,2,
  	1,5,23,24,10,3,0,0,24,25,7,1,0,0,25,26,3,2,1,4,26,27,6,1,-1,0,27,29,1,
  	0,0,0,28,20,1,0,0,0,28,23,1,0,0,0,29,32,1,0,0,0,30,28,1,0,0,0,30,31,1,
  	0,0,0,31,3,1,0,0,0,32,30,1,0,0,0,33,34,5,8,0,0,34,35,6,2,-1,0,35,5,1,
  	0,0,0,3,18,28,30
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  exprParserStaticData = std::move(staticData);
}

}

ExprParser::ExprParser(TokenStream *input) : ExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExprParser::ExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *exprParserStaticData->atn, exprParserStaticData->decisionToDFA, exprParserStaticData->sharedContextCache, options);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

const atn::ATN& ExprParser::getATN() const {
  return *exprParserStaticData->atn;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return exprParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExprParser::getVocabulary() const {
  return exprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExprParser::getSerializedATN() const {
  return exprParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

ExprParser::ExprContext* ExprParser::ProgContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

tree::TerminalNode* ExprParser::ProgContext::EOF() {
  return getToken(ExprParser::EOF, 0);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}

void ExprParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ExprParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(6);
    antlrcpp::downCast<ProgContext *>(_localctx)->exprContext = expr(0);
    setState(7);
    match(ExprParser::EOF);
    _localctx -> value = antlrcpp::downCast<ProgContext *>(_localctx)->exprContext -> value;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

ExprParser::IntegerContext* ExprParser::ExprContext::integer() {
  return getRuleContext<ExprParser::IntegerContext>(0);
}

std::vector<ExprParser::ExprContext *> ExprParser::ExprContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleExpr, precedence);

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
    setState(18);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INT: {
        setState(11);
        antlrcpp::downCast<ExprContext *>(_localctx)->integerContext = integer();

                _localctx -> value = antlrcpp::downCast<ExprContext *>(_localctx)->integerContext -> value;
            
        break;
      }

      case ExprParser::T__4: {
        setState(14);
        match(ExprParser::T__4);
        setState(15);
        expr(0);
        setState(16);
        match(ExprParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(30);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(28);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(20);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(21);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__0

          || _la == ExprParser::T__1)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(22);
          expr(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(23);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(24);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__2

          || _la == ExprParser::T__3)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(25);
          antlrcpp::downCast<ExprContext *>(_localctx)->right = expr(4);

                                _localctx -> value = antlrcpp::downCast<ExprContext *>(_localctx)->left -> value + antlrcpp::downCast<ExprContext *>(_localctx)->right -> value;
                            
          break;
        }

        default:
          break;
        } 
      }
      setState(32);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

ExprParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : MyContextSuperClass(parent, invokingState) {
}

tree::TerminalNode* ExprParser::IntegerContext::INT() {
  return getToken(ExprParser::INT, 0);
}


size_t ExprParser::IntegerContext::getRuleIndex() const {
  return ExprParser::RuleInteger;
}

void ExprParser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}

void ExprParser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}

ExprParser::IntegerContext* ExprParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleInteger);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    antlrcpp::downCast<IntegerContext *>(_localctx)->intToken = match(ExprParser::INT);
     _localctx -> value = std::atoi(antlrcpp::downCast<IntegerContext *>(_localctx)->intToken -> getText().data());
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void ExprParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  exprParserInitialize();
#else
  ::antlr4::internal::call_once(exprParserOnceFlag, exprParserInitialize);
#endif
}
