
#ifndef IR_INCLUDES_H
#define IR_INCLUDES_H

#include "IRError.h"
#include "IROperandType.h"
#include "IROperation.h"

#include "IRBasicType.h"

#include "ConstantValue.h"

#include "IRDataTypeNodeType.h"
#include "IRDataTypeNode.h"

#include "IRBasicTypeNode.h"
#include "IRErrorTypeNode.h"

#include "TypeRef.h"
#include "IRMember.h"
#include "IRCompositeTypeNode.h"
#include "IRStruct.h"
#include "IRUnion.h"

#include "IRConstant.h"
#include "IRDataTypeManager.h"
#include "IRVariable.h"
#include "IRGlobalVariable.h"
#include "IRLocalVariable.h"


//void IRCompositeType::add_field(const TypeRef ref_type, std::string f_name) {

#include "IROperand.h"
#include "IRTriple.h"

// IR Data Types:


#include "IRArrayNode.h"

#include "IRPointerNode.h"
#include "IRQualifiersNode.h"
#include "IRReferenceNode.h"

#include "IRBasicBlock.h"

// Checker Class
#include "IRCheckerListener.h"
#include "IRChecker.h"
#include "IRErrorCollector.h"

#include "IRFunction.h"
#include "IRProgram.h"

#include "IRCoder.h"
// Interpreter: 
#include "IRInterpreterListener.h"
#include "IRInterpreterForTests.h"
#include "IRStackFrame.h"

#include "Interpreter.h"

#endif IR_INCLUDES_H