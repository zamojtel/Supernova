#ifndef IR_H
#define IR_H

#include "IRError.cpp"
#include "IRConstant.cpp"
#include "IRVariable.cpp"
#include "IRTriple.cpp"
#include "IROperand.cpp"

#include "IRBasicBlock.cpp"

#include "IRPrinter.cpp"

#include "IRChecker.cpp"

#include "IRErrorCollector.cpp"

// IR Data Types representation:

#include "TypeRef.cpp"
#include "IRMember.cpp"
#include "IRDataTypeNode.cpp"
#include "IRArrayNode.cpp"
#include "IRPointerNode.cpp"
#include "IRBasicTypeNode.cpp"
#include "IRErrorTypeNode.cpp"
#include "IRQualifiersNode.cpp"
#include "IRReferenceNode.cpp"
//#include "IR"
#include "IRDataTypeManager.cpp"

#include "IRCompositeTypeNode.cpp"
#include "IRStruct.cpp"
#include "IRUnion.cpp"

#include "IRFunction.cpp"
#include "IRProgram.cpp"
#include "IRDataTypeTraits.cpp"

#include "IRCoder.cpp"

#include "Interpreter.cpp"
#include "IRInterpreterForTests.cpp"
#include "IRStackFrame.cpp"

#endif IR_H