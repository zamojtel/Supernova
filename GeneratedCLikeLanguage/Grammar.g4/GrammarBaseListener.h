
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarListener.h"


/**
 * This class provides an empty implementation of GrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GrammarBaseListener : public GrammarListener {
public:

  virtual void enterWhile(GrammarParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(GrammarParser::WhileContext * /*ctx*/) override { }

  virtual void enterIf(GrammarParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(GrammarParser::IfContext * /*ctx*/) override { }

  virtual void enterProg(GrammarParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(GrammarParser::ProgContext * /*ctx*/) override { }

  virtual void enterBlock(GrammarParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(GrammarParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(GrammarParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(GrammarParser::StmtContext * /*ctx*/) override { }

  virtual void enterDeclarations(GrammarParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(GrammarParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterDeclaration(GrammarParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(GrammarParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterAssignments(GrammarParser::AssignmentsContext * /*ctx*/) override { }
  virtual void exitAssignments(GrammarParser::AssignmentsContext * /*ctx*/) override { }

  virtual void enterAssignment(GrammarParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(GrammarParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterType(GrammarParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(GrammarParser::TypeContext * /*ctx*/) override { }

  virtual void enterReturn(GrammarParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(GrammarParser::ReturnContext * /*ctx*/) override { }

  virtual void enterExpr(GrammarParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(GrammarParser::ExprContext * /*ctx*/) override { }

  virtual void enterNumber(GrammarParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(GrammarParser::NumberContext * /*ctx*/) override { }

  virtual void enterIdentifier(GrammarParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(GrammarParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

