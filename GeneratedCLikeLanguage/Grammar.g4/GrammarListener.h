
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

  virtual void enterIf(GrammarParser::IfContext *ctx) = 0;
  virtual void exitIf(GrammarParser::IfContext *ctx) = 0;

  virtual void enterProg(GrammarParser::ProgContext *ctx) = 0;
  virtual void exitProg(GrammarParser::ProgContext *ctx) = 0;

  virtual void enterBlock(GrammarParser::BlockContext *ctx) = 0;
  virtual void exitBlock(GrammarParser::BlockContext *ctx) = 0;

  virtual void enterStmt(GrammarParser::StmtContext *ctx) = 0;
  virtual void exitStmt(GrammarParser::StmtContext *ctx) = 0;

  virtual void enterDeclarations(GrammarParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(GrammarParser::DeclarationsContext *ctx) = 0;

  virtual void enterDeclaration(GrammarParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(GrammarParser::DeclarationContext *ctx) = 0;

  virtual void enterAssignments(GrammarParser::AssignmentsContext *ctx) = 0;
  virtual void exitAssignments(GrammarParser::AssignmentsContext *ctx) = 0;

  virtual void enterAssignment(GrammarParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(GrammarParser::AssignmentContext *ctx) = 0;

  virtual void enterType(GrammarParser::TypeContext *ctx) = 0;
  virtual void exitType(GrammarParser::TypeContext *ctx) = 0;

  virtual void enterReturn(GrammarParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(GrammarParser::ReturnContext *ctx) = 0;

  virtual void enterExpr(GrammarParser::ExprContext *ctx) = 0;
  virtual void exitExpr(GrammarParser::ExprContext *ctx) = 0;

  virtual void enterNumber(GrammarParser::NumberContext *ctx) = 0;
  virtual void exitNumber(GrammarParser::NumberContext *ctx) = 0;

  virtual void enterIdentifier(GrammarParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(GrammarParser::IdentifierContext *ctx) = 0;


};

