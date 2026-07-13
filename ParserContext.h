#pragma once

// The generated ANTLR parser uses this class as contextSuperClass.
// Includes.h and antlr4::ParserRuleContext must be available before this file.
class MyContextSuperClass : public antlr4::ParserRuleContext {
public:
    ReferencePtr<AbstractSyntaxTreeNode> m_node;

    MyContextSuperClass() = default;
    MyContextSuperClass(ParserRuleContext* parent, size_t invoking_state)
        : ParserRuleContext{parent, invoking_state} {}
};

