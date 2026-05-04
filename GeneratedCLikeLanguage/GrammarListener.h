
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GrammarParser.
 */
class  GrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterWhile(GrammarParser::WhileContext *ctx) = 0;
  virtual void exitWhile(GrammarParser::WhileContext *ctx) = 0;

  virtual void enterDoWhile(GrammarParser::DoWhileContext *ctx) = 0;
  virtual void exitDoWhile(GrammarParser::DoWhileContext *ctx) = 0;

  virtual void enterFor(GrammarParser::ForContext *ctx) = 0;
  virtual void exitFor(GrammarParser::ForContext *ctx) = 0;

  virtual void enterInitStatments(GrammarParser::InitStatmentsContext *ctx) = 0;
  virtual void exitInitStatments(GrammarParser::InitStatmentsContext *ctx) = 0;

  virtual void enterIf(GrammarParser::IfContext *ctx) = 0;
  virtual void exitIf(GrammarParser::IfContext *ctx) = 0;

  virtual void enterProg(GrammarParser::ProgContext *ctx) = 0;
  virtual void exitProg(GrammarParser::ProgContext *ctx) = 0;

  virtual void enterProgElement(GrammarParser::ProgElementContext *ctx) = 0;
  virtual void exitProgElement(GrammarParser::ProgElementContext *ctx) = 0;

  virtual void enterFunction(GrammarParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(GrammarParser::FunctionContext *ctx) = 0;

  virtual void enterFunctionParameters(GrammarParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(GrammarParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionParameter(GrammarParser::FunctionParameterContext *ctx) = 0;
  virtual void exitFunctionParameter(GrammarParser::FunctionParameterContext *ctx) = 0;

  virtual void enterFunctionCall(GrammarParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(GrammarParser::FunctionCallContext *ctx) = 0;

  virtual void enterArgumentList(GrammarParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(GrammarParser::ArgumentListContext *ctx) = 0;

  virtual void enterBlock(GrammarParser::BlockContext *ctx) = 0;
  virtual void exitBlock(GrammarParser::BlockContext *ctx) = 0;

  virtual void enterStmt(GrammarParser::StmtContext *ctx) = 0;
  virtual void exitStmt(GrammarParser::StmtContext *ctx) = 0;

  virtual void enterBlockDecl(GrammarParser::BlockDeclContext *ctx) = 0;
  virtual void exitBlockDecl(GrammarParser::BlockDeclContext *ctx) = 0;

  virtual void enterMemberDecl(GrammarParser::MemberDeclContext *ctx) = 0;
  virtual void exitMemberDecl(GrammarParser::MemberDeclContext *ctx) = 0;

  virtual void enterDeclaration(GrammarParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(GrammarParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationListItem(GrammarParser::DeclarationListItemContext *ctx) = 0;
  virtual void exitDeclarationListItem(GrammarParser::DeclarationListItemContext *ctx) = 0;

  virtual void enterStructDecl(GrammarParser::StructDeclContext *ctx) = 0;
  virtual void exitStructDecl(GrammarParser::StructDeclContext *ctx) = 0;

  virtual void enterUnionDecl(GrammarParser::UnionDeclContext *ctx) = 0;
  virtual void exitUnionDecl(GrammarParser::UnionDeclContext *ctx) = 0;

  virtual void enterFundamentalType(GrammarParser::FundamentalTypeContext *ctx) = 0;
  virtual void exitFundamentalType(GrammarParser::FundamentalTypeContext *ctx) = 0;

  virtual void enterDataType(GrammarParser::DataTypeContext *ctx) = 0;
  virtual void exitDataType(GrammarParser::DataTypeContext *ctx) = 0;

  virtual void enterTypeModifier(GrammarParser::TypeModifierContext *ctx) = 0;
  virtual void exitTypeModifier(GrammarParser::TypeModifierContext *ctx) = 0;

  virtual void enterBasicType(GrammarParser::BasicTypeContext *ctx) = 0;
  virtual void exitBasicType(GrammarParser::BasicTypeContext *ctx) = 0;

  virtual void enterReturn(GrammarParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(GrammarParser::ReturnContext *ctx) = 0;

  virtual void enterSizeOf(GrammarParser::SizeOfContext *ctx) = 0;
  virtual void exitSizeOf(GrammarParser::SizeOfContext *ctx) = 0;

  virtual void enterAssertCondition(GrammarParser::AssertConditionContext *ctx) = 0;
  virtual void exitAssertCondition(GrammarParser::AssertConditionContext *ctx) = 0;

  virtual void enterExpr(GrammarParser::ExprContext *ctx) = 0;
  virtual void exitExpr(GrammarParser::ExprContext *ctx) = 0;

  virtual void enterNumber(GrammarParser::NumberContext *ctx) = 0;
  virtual void exitNumber(GrammarParser::NumberContext *ctx) = 0;

  virtual void enterIdentifier(GrammarParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(GrammarParser::IdentifierContext *ctx) = 0;


};

