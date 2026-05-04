
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  GrammarParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, WS = 24, INT = 25, FLOAT = 26, BOOL = 27, 
    ID = 28
  };

  enum {
    RuleWhile = 0, RuleIf = 1, RuleProg = 2, RuleBlock = 3, RuleStmt = 4, 
    RuleDeclarations = 5, RuleDeclaration = 6, RuleAssignments = 7, RuleAssignment = 8, 
    RuleType = 9, RuleReturn = 10, RuleExpr = 11, RuleNumber = 12, RuleIdentifier = 13
  };

  explicit GrammarParser(antlr4::TokenStream *input);

  GrammarParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~GrammarParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class WhileContext;
  class IfContext;
  class ProgContext;
  class BlockContext;
  class StmtContext;
  class DeclarationsContext;
  class DeclarationContext;
  class AssignmentsContext;
  class AssignmentContext;
  class TypeContext;
  class ReturnContext;
  class ExprContext;
  class NumberContext;
  class IdentifierContext; 

  class  WhileContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *exprContext = nullptr;
    GrammarParser::StmtContext *stmtContext = nullptr;
    WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    StmtContext *stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WhileContext* while_();

  class  IfContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *exprContext = nullptr;
    GrammarParser::StmtContext *stmt_1 = nullptr;
    GrammarParser::StmtContext *stmt_2 = nullptr;
    IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfContext* if_();

  class  ProgContext : public MyContextSuperClass {
  public:
    GrammarParser::StmtContext *stmtContext = nullptr;
    std::vector<StmtContext *> items;
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgContext* prog();

  class  BlockContext : public MyContextSuperClass {
  public:
    GrammarParser::StmtContext *stmtContext = nullptr;
    std::vector<StmtContext *> items;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  StmtContext : public MyContextSuperClass {
  public:
    GrammarParser::DeclarationContext *declarationContext = nullptr;
    GrammarParser::AssignmentContext *assignmentContext = nullptr;
    GrammarParser::ReturnContext *returnContext = nullptr;
    GrammarParser::IfContext *ifContext = nullptr;
    GrammarParser::WhileContext *whileContext = nullptr;
    GrammarParser::BlockContext *blockContext = nullptr;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    AssignmentContext *assignment();
    ReturnContext *return_();
    IfContext *if_();
    WhileContext *while_();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StmtContext* stmt();

  class  DeclarationsContext : public MyContextSuperClass {
  public:
    GrammarParser::DeclarationContext *declarationContext = nullptr;
    std::vector<DeclarationContext *> items;
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationsContext* declarations();

  class  DeclarationContext : public MyContextSuperClass {
  public:
    GrammarParser::TypeContext *typeContext = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationContext* declaration();

  class  AssignmentsContext : public MyContextSuperClass {
  public:
    GrammarParser::AssignmentContext *assignmentContext = nullptr;
    std::vector<AssignmentContext *> items;
    AssignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentsContext* assignments();

  class  AssignmentContext : public MyContextSuperClass {
  public:
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentContext* assignment();

  class  TypeContext : public MyContextSuperClass {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  ReturnContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *exprContext = nullptr;
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnContext* return_();

  class  ExprContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *left = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::NumberContext *numberContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    GrammarParser::TypeContext *typeContext = nullptr;
    antlr4::Token *op = nullptr;
    GrammarParser::ExprContext *right = nullptr;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    NumberContext *number();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  NumberContext : public MyContextSuperClass {
  public:
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *boolToken = nullptr;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *BOOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumberContext* number();

  class  IdentifierContext : public MyContextSuperClass {
  public:
    antlr4::Token *idToken = nullptr;
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdentifierContext* identifier();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

