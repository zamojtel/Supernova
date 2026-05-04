
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

  virtual void enterDoWhile(GrammarParser::DoWhileContext * /*ctx*/) override { }
  virtual void exitDoWhile(GrammarParser::DoWhileContext * /*ctx*/) override { }

  virtual void enterFor(GrammarParser::ForContext * /*ctx*/) override { }
  virtual void exitFor(GrammarParser::ForContext * /*ctx*/) override { }

  virtual void enterInitStatments(GrammarParser::InitStatmentsContext * /*ctx*/) override { }
  virtual void exitInitStatments(GrammarParser::InitStatmentsContext * /*ctx*/) override { }

  virtual void enterIf(GrammarParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(GrammarParser::IfContext * /*ctx*/) override { }

  virtual void enterProg(GrammarParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(GrammarParser::ProgContext * /*ctx*/) override { }

  virtual void enterProgElement(GrammarParser::ProgElementContext * /*ctx*/) override { }
  virtual void exitProgElement(GrammarParser::ProgElementContext * /*ctx*/) override { }

  virtual void enterFunction(GrammarParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(GrammarParser::FunctionContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(GrammarParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(GrammarParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionParameter(GrammarParser::FunctionParameterContext * /*ctx*/) override { }
  virtual void exitFunctionParameter(GrammarParser::FunctionParameterContext * /*ctx*/) override { }

  virtual void enterFunctionCall(GrammarParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(GrammarParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterArgumentList(GrammarParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(GrammarParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterBlock(GrammarParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(GrammarParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(GrammarParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(GrammarParser::StmtContext * /*ctx*/) override { }

  virtual void enterBlockDecl(GrammarParser::BlockDeclContext * /*ctx*/) override { }
  virtual void exitBlockDecl(GrammarParser::BlockDeclContext * /*ctx*/) override { }

  virtual void enterMemberDecl(GrammarParser::MemberDeclContext * /*ctx*/) override { }
  virtual void exitMemberDecl(GrammarParser::MemberDeclContext * /*ctx*/) override { }

  virtual void enterDeclaration(GrammarParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(GrammarParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclarationListItem(GrammarParser::DeclarationListItemContext * /*ctx*/) override { }
  virtual void exitDeclarationListItem(GrammarParser::DeclarationListItemContext * /*ctx*/) override { }

  virtual void enterStructDecl(GrammarParser::StructDeclContext * /*ctx*/) override { }
  virtual void exitStructDecl(GrammarParser::StructDeclContext * /*ctx*/) override { }

  virtual void enterUnionDecl(GrammarParser::UnionDeclContext * /*ctx*/) override { }
  virtual void exitUnionDecl(GrammarParser::UnionDeclContext * /*ctx*/) override { }

  virtual void enterFundamentalType(GrammarParser::FundamentalTypeContext * /*ctx*/) override { }
  virtual void exitFundamentalType(GrammarParser::FundamentalTypeContext * /*ctx*/) override { }

  virtual void enterDataType(GrammarParser::DataTypeContext * /*ctx*/) override { }
  virtual void exitDataType(GrammarParser::DataTypeContext * /*ctx*/) override { }

  virtual void enterTypeModifier(GrammarParser::TypeModifierContext * /*ctx*/) override { }
  virtual void exitTypeModifier(GrammarParser::TypeModifierContext * /*ctx*/) override { }

  virtual void enterBasicType(GrammarParser::BasicTypeContext * /*ctx*/) override { }
  virtual void exitBasicType(GrammarParser::BasicTypeContext * /*ctx*/) override { }

  virtual void enterReturn(GrammarParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(GrammarParser::ReturnContext * /*ctx*/) override { }

  virtual void enterSizeOf(GrammarParser::SizeOfContext * /*ctx*/) override { }
  virtual void exitSizeOf(GrammarParser::SizeOfContext * /*ctx*/) override { }

  virtual void enterAssertCondition(GrammarParser::AssertConditionContext * /*ctx*/) override { }
  virtual void exitAssertCondition(GrammarParser::AssertConditionContext * /*ctx*/) override { }

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

