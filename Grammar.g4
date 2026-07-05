grammar Grammar;
options{
contextSuperClass = MyContextSuperClass;
}

@parser::members{
	ParserHelper* m_parser_helper;
}

while: 
	    'while' '(' expr ')' stmt {
			$ctx->m_node = new WhileNode{$expr.ctx->m_node,$stmt.ctx->m_node};
		}
	;

doWhile:
		'do' stmt 'while' '(' expr ')' ';' {
			$ctx->m_node = new DoWhileNode{$expr.ctx->m_node,$stmt.ctx->m_node};
		}
	;

for:
		'for' '(' initStatments ';' (condition = expr) ';' expr ')' stmt {
			ReferencePtr<AbstractSyntaxTreeNode> declarations_or_exprs = $initStatments.ctx->m_node;
			ReferencePtr<AbstractSyntaxTreeNode> cond = $condition.ctx->m_node;
			ReferencePtr<AbstractSyntaxTreeNode> expr = $expr.ctx->m_node;
			ReferencePtr<AbstractSyntaxTreeNode> stmt = $stmt.ctx->m_node;

			$ctx->m_node = new ForNode{declarations_or_exprs,cond,expr,stmt};
		}
	;

initStatments:
			declaration {
				$ctx->m_node = $declaration.ctx->m_node;
			}
		|	expr {
				$ctx->m_node = $expr.ctx->m_node;
			}
	;

if:
		'if' '(' expr ')'  stmt_1 = stmt ('else' stmt_2 = stmt)? {
			$ctx->m_node = new IfNode{$expr.ctx->m_node,$stmt_1.ctx->m_node,$stmt_2.ctx!=nullptr ? $stmt_2.ctx->m_node : nullptr };
		}
	;

prog:
		(items += progElement)* {
			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> items_list = new ListNode<AbstractSyntaxTreeNode>{};

			for(auto *item : $items){
				items_list->add(item->m_node);
			}

			$ctx->m_node = new ProgNode{items_list};
		}
	;

progElement:
			function {
				$ctx->m_node = $function.ctx->m_node;	
			}
		|	declaration ';' {
				$ctx->m_node = $declaration.ctx->m_node;
			}
		|	unionDecl	';' {
				$ctx->m_node = $unionDecl.ctx->m_node;
			}
		|	structDecl	';' {
				$ctx->m_node = $structDecl.ctx->m_node;
			}
	;

function:
		dataType identifier '(' functionParameters ')' block {
			ReferencePtr<DataTypeNode> dtn = $dataType.ctx->m_node.cast<DataTypeNode>();
			ReferencePtr<IdentifierNode> in = $identifier.ctx->m_node.cast<IdentifierNode>();
			ReferencePtr<ListNode<FunctionParameterNode>> params = $functionParameters.ctx->m_node.cast<ListNode<FunctionParameterNode>>();
			ReferencePtr<BlockNode> blk = $block.ctx->m_node.cast<BlockNode>();
			$ctx->m_node = new FunctionNode{dtn,in,params,blk};
		}
	;

functionParameters:
		(parameters+=functionParameter (','parameters+=functionParameter)*)?  {
				ReferencePtr<ListNode<FunctionParameterNode>> list = new ListNode<FunctionParameterNode>{};
				for(auto *parameter : $parameters){
					list->add(parameter->m_node.cast<FunctionParameterNode>());
				}
				$ctx->m_node = list;
		}
	;

functionParameter:
		dataType identifier {
			ReferencePtr<DataTypeNode> dtn = $dataType.ctx->m_node.cast<DataTypeNode>();
			ReferencePtr<IdentifierNode> in = $identifier.ctx->m_node.cast<IdentifierNode>();
			$ctx -> m_node = new FunctionParameterNode{dtn,in};
		}
	;

functionCall: 
		identifier '(' argumentList? ')' {
			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> argument_list = new ListNode<AbstractSyntaxTreeNode>{};
			if($argumentList.ctx!=nullptr)
				argument_list = $argumentList.ctx->m_node.cast<ListNode<AbstractSyntaxTreeNode>>();
			else
				argument_list = new ListNode<AbstractSyntaxTreeNode>{};
			ReferencePtr<IdentifierNode> id = $identifier.ctx->m_node.cast<IdentifierNode>();

			$ctx->m_node = new FunctionCallNode{id,argument_list};
		}
	;

argumentList:
		 arguments+=expr (',' arguments+=expr)* {
			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
			for(auto *arg : $arguments){
				list->add(arg->m_node);
			}
			$ctx->m_node = list;
		 }
	;

block:
		'{' (items+=stmt)* '}' {
			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
			for(auto *node : $items){
				list->add(node->m_node);
			}

			$ctx->m_node = new BlockNode{ list };
		}
	;

stmt:
			declaration ';' {
				$ctx->m_node = $declaration.ctx->m_node;
			}
		|	functionCall ';' {
				$ctx->m_node = $functionCall.ctx->m_node;
			}
		|	return {
				$ctx->m_node = $return.ctx->m_node;
			}
		|	if {
				$ctx->m_node = $if.ctx->m_node;
			}
		|	while {
				$ctx->m_node = $while.ctx->m_node;
			}
		|	for {
				$ctx->m_node = $for.ctx->m_node;
			}
		| doWhile {
				$ctx->m_node = $doWhile.ctx->m_node;
			}
		|	block {
				$ctx->m_node = $block.ctx->m_node;
			}
		|	BREAK ';' {
				$ctx->m_node = new BreakNode{};
			}
		|	CONTINUE ';' {
				$ctx->m_node = new ContinueNode{};
			}
		| 'print' '(' expr ')' ';' {
				$ctx->m_node = new PrintNode{$expr.ctx->m_node};
			}
		| 'print_type' '(' expr ')' ';' {
				$ctx->m_node = new PrintTypeNode{$expr.ctx->m_node};
			}
		| expr ';'{
				$ctx->m_node = $expr.ctx->m_node;
		}
	;

blockDecl: 
		'{' (items+=memberDecl)* '}' {
			ReferencePtr<ListNode<MemberDeclarationNode>> list = new ListNode<MemberDeclarationNode>{};

			for(auto *item : $items)
				list->add(item->m_node.cast<MemberDeclarationNode>());

			$ctx->m_node = list;
		}
	;

memberDecl:
		dataType identifier ';' {
			ReferencePtr<DataTypeNode> data_type = $dataType.ctx->m_node.cast<DataTypeNode>();
			ReferencePtr<IdentifierNode> id = $identifier.ctx->m_node.cast<IdentifierNode>();

			$ctx->m_node = new MemberDeclarationNode{data_type,id};
		}
	;

declaration:
		dataType items+= declarationListItem (',' items+=declarationListItem)* {
			ReferencePtr<DataTypeNode> dtn = $dataType.ctx->m_node.cast<DataTypeNode>();
			ReferencePtr<ListNode<DeclarationListItemNode>> list = new ListNode<DeclarationListItemNode>{};

			for(auto *decl_list_item : $items)
				list->add(decl_list_item->m_node.cast<DeclarationListItemNode>());

			$ctx->m_node = new DeclarationNode{dtn,list};
		}
	;

declarationListItem: 
		identifier {
			ReferencePtr<IdentifierNode> in = $identifier.ctx->m_node.cast<IdentifierNode>();
			$ctx -> m_node = new DeclarationListItemNode{in};
		}
	|	(identifier '=' expr)  {
			ReferencePtr<IdentifierNode> in = $identifier.ctx->m_node.cast<IdentifierNode>();
			ReferencePtr<AbstractSyntaxTreeNode> expr = $expr.ctx->m_node;
			$ctx->m_node = new DeclarationListItemNode{in,expr};
		}
	;

structDecl:
		'struct' identifier blockDecl {
			ReferencePtr<IdentifierNode> id_node = $identifier.ctx->m_node.cast<IdentifierNode>();
			ReferencePtr<ListNode<MemberDeclarationNode>> decl_list = $blockDecl.ctx->m_node.cast<ListNode<MemberDeclarationNode>>();
			
			$ctx->m_node = new StructNode{id_node,decl_list};
		}
	;

unionDecl:
		'union' identifier blockDecl {
			ReferencePtr<IdentifierNode> id_node =  $identifier.ctx->m_node.cast<IdentifierNode>();
			ReferencePtr<ListNode<MemberDeclarationNode>> decl_list = $blockDecl.ctx->m_node.cast<ListNode<MemberDeclarationNode>>();
			
			$ctx->m_node = new UnionNode{id_node,decl_list}; 
		}
	;
 
fundamentalType:
			basicType  { $ctx->m_node = $basicType.ctx->m_node; }
		|	identifier { $ctx->m_node = $identifier.ctx->m_node; }
	;

dataType:
		ft = fundamentalType (modifier_list += typeModifier)* {
			ReferencePtr<ListNode<AbstractSyntaxTreeNode>> list = new ListNode<AbstractSyntaxTreeNode>{};
			ReferencePtr<AbstractSyntaxTreeNode> fundamental_type = $ft.ctx->m_node;

			for(auto *element : $modifier_list)
				list->add(element->m_node);

			$ctx->m_node = new DataTypeNode{fundamental_type,list};
		}
	;

typeModifier:
			'*' {$ctx->m_node = new PointerNode{}; }
		|	'['(e=expr)']' { $ctx->m_node = new ArrayNode{ $e.ctx->m_node }; }
		|	'const' { $ctx->m_node = new QualifierNode{IRQualifiersNode::CONST}; }
		|	'volatile' { $ctx->m_node = new QualifierNode{IRQualifiersNode::VOLATILE}; }
		|	'&' { $ctx->m_node = new ReferenceNode{}; }
	;

basicType:
			'int' { $ctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; }
		|	'int8' { $ctx -> m_node = new BasicTypeNode{IRBasicType::INT8}; }
		|	'int16' { $ctx -> m_node = new BasicTypeNode{IRBasicType::INT16}; }
		|	'int32' { $ctx -> m_node = new BasicTypeNode{IRBasicType::INT32}; }
		|	'int64' { $ctx -> m_node = new BasicTypeNode{IRBasicType::INT64}; }
		|	'uint8' { $ctx -> m_node = new BasicTypeNode{IRBasicType::UINT8}; }
		|	'uint16' { $ctx -> m_node = new BasicTypeNode{IRBasicType::UINT16}; }
		|	'uint32' { $ctx -> m_node = new BasicTypeNode{IRBasicType::UINT32}; }
		|	'uint64' { $ctx -> m_node = new BasicTypeNode{IRBasicType::UINT64}; }
		|	'float' { $ctx -> m_node = new BasicTypeNode{IRBasicType::FLOAT}; }
		|	'double' { $ctx -> m_node = new BasicTypeNode{IRBasicType::DOUBLE}; }
		|	'bool' { $ctx->m_node = new BasicTypeNode{IRBasicType::BOOL}; }
		|	'void' { $ctx->m_node = new BasicTypeNode{IRBasicType::VOID}; }
	;

return: 
		'return' expr? ';' { $ctx -> m_node = new ReturnNode{ $expr.ctx ? $expr.ctx->m_node : nullptr }; }
	;

sizeOf:
		'sizeof' '(' dataType ')' { 
			ReferencePtr<DataTypeNode> dtn = $dataType.ctx->m_node.cast<DataTypeNode>();
			$ctx->m_node = new SizeOfNode{dtn}; 
		}
	;

assertCondition: 
		'assert' '(' expr ')' {
			$ctx->m_node = new AssertNode{$expr.ctx->m_node};
		}
	;

expr:
		'(' dataType ')' expr {
			$ctx->m_node = new CastNode{$dataType.ctx->m_node.cast<DataTypeNode>(),$expr.ctx->m_node};
		}
	|	array_id = expr '[' expr ']' {
			$ctx->m_node = new ArrayAccessNode{$array_id.ctx->m_node,$expr.ctx->m_node};
		}
	|	new_left = expr '.' field = identifier { // dotMemberAccess
			ReferencePtr<AbstractSyntaxTreeNode> expr_node = $new_left.ctx->m_node;
			ReferencePtr<IdentifierNode> field_id_node = $field.ctx->m_node.cast<IdentifierNode>(); 
			
			$ctx->m_node = new MemberAccessNode{expr_node,field_id_node,false};
		}
	|	new_left = expr '->' field = identifier { // arrowMemberAccess
			ReferencePtr<AbstractSyntaxTreeNode> expr_node = $new_left.ctx->m_node; 
			ReferencePtr<IdentifierNode> field_id_node = $field.ctx->m_node.cast<IdentifierNode>();
			
			$ctx->m_node = new MemberAccessNode{expr_node,field_id_node,true};
		}
	|	e = expr '++' {
			$ctx->m_node = new IncrementationNode{$e.ctx->m_node,true};
		}
	|	'++' e = expr {
			$ctx->m_node = new IncrementationNode{$e.ctx->m_node,false};
		}
	|	e = expr '--' {
			$ctx->m_node = new DecrementationNode{$e.ctx->m_node,true};
		}
	|	'--' e = expr {
			$ctx->m_node = new DecrementationNode{$e.ctx->m_node,false};
		}
	|	'-' e = expr {
			$ctx->m_node = new UnaryMinusNode{$e.ctx->m_node};
		}
	|	'!' (e = expr) {
			$ctx->m_node = new BooleanNotNode{$e.ctx->m_node};
		}
	|	'*' e = expr {
			$ctx->m_node = new DereferenceNode{$e.ctx->m_node};
		}
	|   '&' e = expr {
			$ctx->m_node = new AddressOfNode{$e.ctx->m_node};
		}
	|	left = expr op = ('/'|'*') right = expr { 
			char oper = $op->getText().data()[0];
			OperationType basicType;
			switch(oper){
			case '*':
				basicType = OperationType::MUL;
				break;
			case '/':
				basicType = OperationType::DIV;
				break;
			}
			$ctx -> m_node = new BinaryOperatorNode{$left.ctx->m_node,$right.ctx->m_node, basicType }; }
	|	left = expr op = ('+'|'-') right = expr { 
			char oper = $op->getText().data()[0];
			OperationType basicType;
			switch(oper){
			case '+':
				basicType = OperationType::ADD;
				break;
			case '-':
				basicType = OperationType::SUB;
				break;
			}

			$ctx -> m_node = new BinaryOperatorNode{$left.ctx->m_node,$right.ctx->m_node, basicType }; 
		}
	|	left = expr op = ( '>>' | '<<') right = expr {
			std::string oper = $op->getText().data();
			OperationType op_type;

			if(oper == ">>")
				op_type = OperationType::RIGHT_SHIFT;
			else if (oper == "<<")
				op_type = OperationType::LEFT_SHIFT;

			$ctx->m_node = new BinaryOperatorNode{$left.ctx->m_node,$right.ctx->m_node,op_type};
		}
	|	left = expr op = ( '>' | '>=' | '<' | '<=' | '==' | '!=' ) right = expr {
			std::string oper = $op->getText().data();
			OperationType basicType;

			if(oper == ">")
				basicType = OperationType::GT;
			else if (oper == ">=")
				basicType = OperationType::GE;
			else if (oper == "<")
				basicType = OperationType::LT;
			else if (oper == "<=")
				basicType = OperationType::LE;
			else if (oper == "==")
				basicType = OperationType::EQ;
			else if (oper == "!=")
				basicType = OperationType::NEQ;

			$ctx->m_node = new BinaryOperatorNode{$left.ctx->m_node,$right.ctx->m_node,basicType};
		}
	|	left = expr op = '&&' right = expr {
			$ctx->m_node = new AndNode{$left.ctx->m_node,$right.ctx->m_node};
		}
	|	left = expr op = '||' right = expr {
			$ctx->m_node = new OrNode{$left.ctx->m_node,$right.ctx->m_node};
		}
	|	left = expr op = '&' right = expr {
			$ctx->m_node = new BinaryOperatorNode{$left.ctx->m_node,$right.ctx->m_node,OperationType::BITWISE_AND};
		}
	|	left = expr op = '|' right = expr {
			$ctx->m_node = new BinaryOperatorNode{$left.ctx->m_node,$right.ctx->m_node,OperationType::BITWISE_OR};
		}
	|	functionCall{ $ctx->m_node = $functionCall.ctx->m_node; }
	|	identifier{ $ctx->m_node = $identifier.ctx->m_node; }
	|	left_expr = expr '=' right_expr = expr {
			$ctx->m_node = new AssignmentNode{$left_expr.ctx->m_node,$right_expr.ctx->m_node};
		}
	|	number{ $ctx -> m_node = $number.ctx->m_node; }
	|	'(' expr ')' { $ctx->m_node = $expr.ctx->m_node; }
	|	'reinterpret_cast' '<' dataType '>' '(' expr ')' {
			$ctx->m_node = new ReinterpretNode{$dataType.ctx->m_node.cast<DataTypeNode>(),$expr.ctx->m_node};
		}
	|	sizeOf { $ctx->m_node = $sizeOf.ctx->m_node; }
	|	assertCondition { $ctx->m_node = $assertCondition.ctx->m_node; }
	|	select {
			$ctx->m_node = $select.ctx->m_node;
		}
	| 'malloc' '(' e=expr ')' {
			$ctx->m_node = new MallocNode($e.ctx->m_node);
		}
	| 'free' '(' e=expr ')' {
			$ctx->m_node = new FreeNode($e.ctx->m_node);
		}
	;

select:
			'select' '(' condition=expr ',' e_t = expr ',' e_f = expr')'{
				$ctx->m_node = new SelectNode{$condition.ctx->m_node,$e_t.ctx->m_node,$e_f.ctx->m_node};
			}
		;

number:
			integerLiteral = (INT | HEX | BINARY | OCTAL)  { 
				$ctx->m_node = m_parser_helper->parse_integer_literal($integerLiteral->getText().data());
			}
		|	FLOAT{
				$ctx -> m_node = new ConstantNode{(float) std::atof($FLOAT -> getText().data()) };
			}
		|	DOUBLE{
				$ctx -> m_node = new ConstantNode{ std::atof($DOUBLE -> getText().data()) };
			}
		|	BOOL{
				$ctx->m_node = new ConstantNode{ $BOOL -> getText() == "true" };
			}
		;

identifier: ID{
				$ctx -> m_node = new IdentifierNode{ $ID -> getText().data() };
			};

// LEXER
// TOKENS
LINE_COMMENT : '//' ~[\r\n]* -> skip ;
WS: [ \t\r\n] + -> skip ;
INT     : [0-9]([0-9]|'_'+[0-9])*([ulUL])?([ulUL])? ;
FLOAT	: [0-9]+'.'[0-9]+'f' ;
DOUBLE	: [0-9]+'.'[0-9]+ ;
BOOL : 'true'|'false' ;
BINARY : '0b'[0-1]([0-1]|'_'+[0-1])*([ulUL])?([ulUL])? ;
OCTAL : '0o'[0-7]([0-7]|'_'+[0-7])*([ulUL])?([ulUL])? ;
HEX : '0x'[0-9a-fA-F]([0-9a-fA-F]|'_'+[0-9a-fA-F])*([ulUL])?([ulUL])? ;
// KEY WORDS
CONTINUE : 'continue' ;
BREAK : 'break' ;
ID : [_a-zA-Z][_a-zA-Z0-9]* ;

