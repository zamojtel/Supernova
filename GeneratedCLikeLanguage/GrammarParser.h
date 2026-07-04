
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  GrammarParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, LINE_COMMENT = 61, WS = 62, 
    INT = 63, FLOAT = 64, DOUBLE = 65, BOOL = 66, BINARY = 67, OCTAL = 68, 
    HEX = 69, CONTINUE = 70, BREAK = 71, ID = 72
  };

  enum {
    RuleWhile = 0, RuleDoWhile = 1, RuleFor = 2, RuleInitStatments = 3, 
    RuleIf = 4, RuleProg = 5, RuleProgElement = 6, RuleFunction = 7, RuleFunctionParameters = 8, 
    RuleFunctionParameter = 9, RuleFunctionCall = 10, RuleArgumentList = 11, 
    RuleBlock = 12, RuleStmt = 13, RuleBlockDecl = 14, RuleMemberDecl = 15, 
    RuleDeclaration = 16, RuleDeclarationListItem = 17, RuleStructDecl = 18, 
    RuleUnionDecl = 19, RuleFundamentalType = 20, RuleDataType = 21, RuleTypeModifier = 22, 
    RuleBasicType = 23, RuleReturn = 24, RuleSizeOf = 25, RuleAssertCondition = 26, 
    RuleExpr = 27, RuleSelect = 28, RuleNumber = 29, RuleIdentifier = 30
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
  class DoWhileContext;
  class ForContext;
  class InitStatmentsContext;
  class IfContext;
  class ProgContext;
  class ProgElementContext;
  class FunctionContext;
  class FunctionParametersContext;
  class FunctionParameterContext;
  class FunctionCallContext;
  class ArgumentListContext;
  class BlockContext;
  class StmtContext;
  class BlockDeclContext;
  class MemberDeclContext;
  class DeclarationContext;
  class DeclarationListItemContext;
  class StructDeclContext;
  class UnionDeclContext;
  class FundamentalTypeContext;
  class DataTypeContext;
  class TypeModifierContext;
  class BasicTypeContext;
  class ReturnContext;
  class SizeOfContext;
  class AssertConditionContext;
  class ExprContext;
  class SelectContext;
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

  class  DoWhileContext : public MyContextSuperClass {
  public:
    GrammarParser::StmtContext *stmtContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    DoWhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StmtContext *stmt();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DoWhileContext* doWhile();

  class  ForContext : public MyContextSuperClass {
  public:
    GrammarParser::InitStatmentsContext *initStatmentsContext = nullptr;
    GrammarParser::ExprContext *condition = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    GrammarParser::StmtContext *stmtContext = nullptr;
    ForContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InitStatmentsContext *initStatments();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    StmtContext *stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForContext* for_();

  class  InitStatmentsContext : public MyContextSuperClass {
  public:
    GrammarParser::DeclarationContext *declarationContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    InitStatmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InitStatmentsContext* initStatments();

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
    GrammarParser::ProgElementContext *progElementContext = nullptr;
    std::vector<ProgElementContext *> items;
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProgElementContext *> progElement();
    ProgElementContext* progElement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgContext* prog();

  class  ProgElementContext : public MyContextSuperClass {
  public:
    GrammarParser::FunctionContext *functionContext = nullptr;
    GrammarParser::DeclarationContext *declarationContext = nullptr;
    GrammarParser::UnionDeclContext *unionDeclContext = nullptr;
    GrammarParser::StructDeclContext *structDeclContext = nullptr;
    ProgElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    DeclarationContext *declaration();
    UnionDeclContext *unionDecl();
    StructDeclContext *structDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgElementContext* progElement();

  class  FunctionContext : public MyContextSuperClass {
  public:
    GrammarParser::DataTypeContext *dataTypeContext = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::FunctionParametersContext *functionParametersContext = nullptr;
    GrammarParser::BlockContext *blockContext = nullptr;
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataTypeContext *dataType();
    IdentifierContext *identifier();
    FunctionParametersContext *functionParameters();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  FunctionParametersContext : public MyContextSuperClass {
  public:
    GrammarParser::FunctionParameterContext *functionParameterContext = nullptr;
    std::vector<FunctionParameterContext *> parameters;
    FunctionParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctionParameterContext *> functionParameter();
    FunctionParameterContext* functionParameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionParametersContext* functionParameters();

  class  FunctionParameterContext : public MyContextSuperClass {
  public:
    GrammarParser::DataTypeContext *dataTypeContext = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    FunctionParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataTypeContext *dataType();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionParameterContext* functionParameter();

  class  FunctionCallContext : public MyContextSuperClass {
  public:
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::ArgumentListContext *argumentListContext = nullptr;
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    ArgumentListContext *argumentList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallContext* functionCall();

  class  ArgumentListContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> arguments;
    ArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentListContext* argumentList();

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
    GrammarParser::FunctionCallContext *functionCallContext = nullptr;
    GrammarParser::ReturnContext *returnContext = nullptr;
    GrammarParser::IfContext *ifContext = nullptr;
    GrammarParser::WhileContext *whileContext = nullptr;
    GrammarParser::ForContext *forContext = nullptr;
    GrammarParser::DoWhileContext *doWhileContext = nullptr;
    GrammarParser::BlockContext *blockContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    FunctionCallContext *functionCall();
    ReturnContext *return_();
    IfContext *if_();
    WhileContext *while_();
    ForContext *for_();
    DoWhileContext *doWhile();
    BlockContext *block();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StmtContext* stmt();

  class  BlockDeclContext : public MyContextSuperClass {
  public:
    GrammarParser::MemberDeclContext *memberDeclContext = nullptr;
    std::vector<MemberDeclContext *> items;
    BlockDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MemberDeclContext *> memberDecl();
    MemberDeclContext* memberDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockDeclContext* blockDecl();

  class  MemberDeclContext : public MyContextSuperClass {
  public:
    GrammarParser::DataTypeContext *dataTypeContext = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    MemberDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataTypeContext *dataType();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MemberDeclContext* memberDecl();

  class  DeclarationContext : public MyContextSuperClass {
  public:
    GrammarParser::DataTypeContext *dataTypeContext = nullptr;
    GrammarParser::DeclarationListItemContext *declarationListItemContext = nullptr;
    std::vector<DeclarationListItemContext *> items;
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataTypeContext *dataType();
    std::vector<DeclarationListItemContext *> declarationListItem();
    DeclarationListItemContext* declarationListItem(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationContext* declaration();

  class  DeclarationListItemContext : public MyContextSuperClass {
  public:
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    DeclarationListItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationListItemContext* declarationListItem();

  class  StructDeclContext : public MyContextSuperClass {
  public:
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::BlockDeclContext *blockDeclContext = nullptr;
    StructDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    BlockDeclContext *blockDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructDeclContext* structDecl();

  class  UnionDeclContext : public MyContextSuperClass {
  public:
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::BlockDeclContext *blockDeclContext = nullptr;
    UnionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    BlockDeclContext *blockDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnionDeclContext* unionDecl();

  class  FundamentalTypeContext : public MyContextSuperClass {
  public:
    GrammarParser::BasicTypeContext *basicTypeContext = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    FundamentalTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BasicTypeContext *basicType();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FundamentalTypeContext* fundamentalType();

  class  DataTypeContext : public MyContextSuperClass {
  public:
    GrammarParser::FundamentalTypeContext *ft = nullptr;
    GrammarParser::TypeModifierContext *typeModifierContext = nullptr;
    std::vector<TypeModifierContext *> modifier_list;
    DataTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FundamentalTypeContext *fundamentalType();
    std::vector<TypeModifierContext *> typeModifier();
    TypeModifierContext* typeModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DataTypeContext* dataType();

  class  TypeModifierContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *e = nullptr;
    TypeModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeModifierContext* typeModifier();

  class  BasicTypeContext : public MyContextSuperClass {
  public:
    BasicTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BasicTypeContext* basicType();

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

  class  SizeOfContext : public MyContextSuperClass {
  public:
    GrammarParser::DataTypeContext *dataTypeContext = nullptr;
    SizeOfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataTypeContext *dataType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SizeOfContext* sizeOf();

  class  AssertConditionContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *exprContext = nullptr;
    AssertConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssertConditionContext* assertCondition();

  class  ExprContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *array_id = nullptr;
    GrammarParser::ExprContext *new_left = nullptr;
    GrammarParser::ExprContext *e = nullptr;
    GrammarParser::ExprContext *left = nullptr;
    GrammarParser::ExprContext *left_expr = nullptr;
    GrammarParser::DataTypeContext *dataTypeContext = nullptr;
    GrammarParser::ExprContext *exprContext = nullptr;
    GrammarParser::FunctionCallContext *functionCallContext = nullptr;
    GrammarParser::IdentifierContext *identifierContext = nullptr;
    GrammarParser::NumberContext *numberContext = nullptr;
    GrammarParser::SizeOfContext *sizeOfContext = nullptr;
    GrammarParser::AssertConditionContext *assertConditionContext = nullptr;
    GrammarParser::SelectContext *selectContext = nullptr;
    antlr4::Token *op = nullptr;
    GrammarParser::ExprContext *right = nullptr;
    GrammarParser::ExprContext *right_expr = nullptr;
    GrammarParser::IdentifierContext *field = nullptr;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataTypeContext *dataType();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    FunctionCallContext *functionCall();
    IdentifierContext *identifier();
    NumberContext *number();
    SizeOfContext *sizeOf();
    AssertConditionContext *assertCondition();
    SelectContext *select();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  SelectContext : public MyContextSuperClass {
  public:
    GrammarParser::ExprContext *condition = nullptr;
    GrammarParser::ExprContext *e_t = nullptr;
    GrammarParser::ExprContext *e_f = nullptr;
    SelectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SelectContext* select();

  class  NumberContext : public MyContextSuperClass {
  public:
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *doubleToken = nullptr;
    antlr4::Token *boolToken = nullptr;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();
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

