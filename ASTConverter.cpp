
ASTConverter::ASTConverter(const ReferencePtr<ProgNode>& p, IRProgram* i_p, IRDataTypeManager* dtm) : m_prog{ p }, m_ir_program{ i_p }, m_coder{ i_p }, m_dtm{dtm}, m_temp_variable_count{ 0 } {}

IROperation ASTConverter::ast_op_to_ir_op(OperationType t) {
	switch (t)
	{
	case OperationType::ADD:
		return IROperation::ADD;
	case OperationType::SUB:
		return IROperation::SUB;
	case OperationType::DIV:
		return IROperation::DIV;
	case OperationType::MUL:
		return IROperation::MUL;
	case OperationType::MOD:
		return IROperation::MOD;
	case OperationType::GT:
		return IROperation::GT;
	case OperationType::GE:
		return IROperation::GE;
	case OperationType::LT:
		return IROperation::LT;
	case OperationType::LE:
		return IROperation::LE;
	case OperationType::EQ:
		return IROperation::EQ;
	case OperationType::NEQ:
		return IROperation::NEQ;
	default:
		throw std::runtime_error("can't convert from ast operation to ir operation");
	}
}

IROperand ASTConverter::get_op(const ReferencePtr<AbstractSyntaxTreeNode> &node) {
	TreeNodeType type = node->get_type();

	switch (type)
	{
	case TreeNodeType::PROG:
		break;
	case TreeNodeType::DECLARATION:
		break;
	case TreeNodeType::ASSIGNMENT:
		break;
	case TreeNodeType::DATA_TYPE:
	{
		auto casted_node = node.cast<DataTypeNode>();
		return casted_node->get_ir_data_type();
	}
	case TreeNodeType::IDENTIFIER: {
		return node->m_operand;
	}
	case TreeNodeType::MEMBER_ACCESS: {
		auto casted_node = node.cast<MemberAccessNode>();
		break;
	}
	case TreeNodeType::LIST:
		break;
	case TreeNodeType::BIN_OPERATION:
	{
		break;
	}
	case TreeNodeType::CONSTANT: {
		break;
	}
	case TreeNodeType::RETURN:
		break;
	case TreeNodeType::CAST: {
		break;
	}
	case TreeNodeType::REINTERPRET_CAST:
		break;
	default:
		break;
	}
	return node->m_operand;
}

void ASTConverter::set_op(const ReferencePtr<AbstractSyntaxTreeNode>& node,const IROperand& op) {
	// Pomyslec o setterze 
	node->m_operand = op;
}

// Collects all function signatures and ...
void ASTConverter::first_pass(const ReferencePtr<AbstractSyntaxTreeNode>& node) {
	find_function_signatures(node);
}

void ASTConverter::second_pass(const ReferencePtr<AbstractSyntaxTreeNode>& node) {
	post_order_traverse(node);
}

void ASTConverter::build_ir_data_type_from_ast(const ReferencePtr<DataTypeNode>& dtn) {
	auto list = dtn->get_modifier_list();

	// if the type for this dtn is already built we return 
	if (dtn->m_ir_data_type)
		return;

	TreeNodeType tree_node_type = dtn->get_fundamental_type()->get_tree_node_type();
	TypeRef current_ref;

	// UNIA, STRUCT, TABLICA
	if (tree_node_type == TreeNodeType::IDENTIFIER) {
		ReferencePtr<IdentifierNode> id_node = dtn->get_fundamental_type().cast<IdentifierNode>();
		std::optional<IROperand> result = m_symbol_table.find_symbol(id_node->get_identifier());
		IROperand composed_type;
		if (result.has_value())
			composed_type = result.value();
		else {
			std::string msg = std::format("type not defined", id_node->get_identifier());
			m_ast_converter_listener->error({ id_node->get_line_number(),msg });
		}
		
		current_ref = composed_type.get_data_type();
	}
	else if(tree_node_type == TreeNodeType::BASIC_TYPE) {
		ReferencePtr<BasicTypeNode> basic_type_node = dtn->get_fundamental_type().cast<BasicTypeNode>();
		current_ref = m_dtm->get_basic_type_node(basic_type_node->get_data_type());
	}

	for (size_t i=0; i < list->get_count(); i++) {
		auto element = list->get_element(i);
		TreeNodeType type = element->get_type();

		switch (type)
		{
		case TreeNodeType::ARRAY: {
			ReferencePtr<ArrayNode> node = element.cast<ArrayNode>();
			ReferencePtr<AbstractSyntaxTreeNode> m_expr = node->get_expr();
			if (m_expr->get_type()==TreeNodeType::CONSTANT) {
				ReferencePtr<ConstantNode> constant = m_expr.cast<ConstantNode>();
				if (constant->get_constant_value().convert_value_to<int>().has_value()) {
					int value = constant->get_constant_value().convert_value_to<int>().value();
					current_ref = m_dtm->add_array(current_ref,value);
				}
			}
			break;
		}
		case TreeNodeType::QUALIFIER: {
			try {
				ReferencePtr<QualifierNode> node = element.cast<QualifierNode>();
				current_ref = m_dtm->add_qualifiers(current_ref,node->get_mask());
			}
			catch (const std::runtime_error& e) {
				m_ast_converter_listener->error({dtn->get_line_number(),e.what()});
			}
			break;
		}
		case TreeNodeType::REFERENCE: {
			current_ref = m_dtm->add_reference(current_ref);
			break;
		}
		case TreeNodeType::POINTER: {
			current_ref = m_dtm->add_pointer(current_ref);
			break;
		}
		default:
			break;
		}
	}

	std::cout << current_ref.to_string() << std::endl;
	dtn->m_ir_data_type = current_ref;
}

void ASTConverter::find_function_signatures(const ReferencePtr<AbstractSyntaxTreeNode>& node) {
	if (!node)
		return;

	TreeNodeType type = node->get_type();
	switch (type)
	{
	case TreeNodeType::PROG: {
		ReferencePtr<ProgNode> current_node = node.cast<ProgNode>();

		m_current_fn = m_global_fn;
		auto nodes = current_node.get_ptr()->m_items;
		m_coder.set_basic_block(m_current_fn->get_basic_blk(0));
		for (size_t i = 0; i < nodes->get_count(); i++) {
			auto node = nodes->get_child(i);
			// currently only functions are processed 
			if (node->get_tree_node_type() != TreeNodeType::DECLARATION)
				find_function_signatures(node);
		}
		break;
	}
	case TreeNodeType::FUNCTION: {
		ReferencePtr<FunctionNode> current_node = node.cast<FunctionNode>();
		std::string fn_name = current_node->get_identifier_node()->get_identifier();
		current_node;

		ReferencePtr<DataTypeNode> fn_return_type = current_node->get_data_type_node();
		/*IRBasicType fn_type = current_node->get_data_type_node()->get_basic_type()->get_data_type();*/
		std::cout << "Built type: " << std::endl;
		build_ir_data_type_from_ast(fn_return_type);

		std::vector<IRVariable*> fn_parameters;

		if (!m_symbol_table.can_add(fn_name)) {
			std::string msg = std::format("symbol {} is already used.",fn_name);
			m_ast_converter_listener->error({ current_node->get_line_number(),msg});
		}

		auto list_with_params = current_node->get_parameters();
		std::vector<std::string> l_param_names;

		std::vector<TypeRef> l_param_types;
		for (size_t i = 0; i < list_with_params.get_ptr()->get_child_count(); i++) {
			ReferencePtr<FunctionParameterNode> param_node = list_with_params.get_ptr()->get_element(i);
			std::string parameter_name = param_node->get_identifier_node()->get_identifier();

			ReferencePtr<DataTypeNode> parameter_type_node = param_node->get_data_type_node();
			build_ir_data_type_from_ast(parameter_type_node);

			l_param_types.push_back(parameter_type_node->m_ir_data_type);
			l_param_names.push_back(parameter_name);
		}
	
		IRFunction* fn = m_ir_program->add_function(fn_name, fn_return_type->m_ir_data_type, l_param_names, l_param_types);
		current_node->set_function_ptr(fn);

		break;
	}
	case TreeNodeType::LIST: {
		int count = node->get_child_count();
		for (size_t i = 0; i < count; i++)
			find_function_signatures(node->get_child(i));
		break;
	}
	case TreeNodeType::DECLARATION: {
		ReferencePtr<DeclarationNode> current_node = node.cast<DeclarationNode>();
		find_function_signatures(current_node->get_data_type_node());
		find_function_signatures(current_node->get_declarations());
		auto list = current_node->get_declarations();

		ReferencePtr<DataTypeNode> dtn = current_node->get_data_type_node();
		build_ir_data_type_from_ast(dtn);

		for (size_t i = 0; i < list->get_child_count(); i++) {
			ReferencePtr<DeclarationListItemNode> current_item = list->get_element(i).cast<DeclarationListItemNode>();

			std::string variable_name = current_item->get_indentifier_node()->get_identifier();

			if (!m_symbol_table.can_add(variable_name)) {
				std::string msg = std::format("symbol {} is already used.",variable_name);
				m_ast_converter_listener->error({ current_node->get_line_number(),msg});
			}
			
			IRGlobalVariable* variable = m_ir_program->add_variable(variable_name, dtn->m_ir_data_type);
			m_symbol_table.add_symbol(variable_name,{variable});
		}
		break;
	}
	case TreeNodeType::DECLARATION_LIST_ITEM: {
		ReferencePtr<DeclarationListItemNode> current_node = node.cast<DeclarationListItemNode>();

		break;
	}
	// gather into one
	case TreeNodeType::STRUCT: {
		ReferencePtr<StructNode> current_node = node.cast<StructNode>();
		ReferencePtr<IdentifierNode> identifier_node = current_node->get_identifier_node();
		std::string struct_name = identifier_node->get_identifier();

		TypeRef ref_struct = m_dtm->add_struct(struct_name);
		m_symbol_table.add_symbol(identifier_node->get_identifier(), ref_struct);
		current_node->m_ir_composite_data_type = ref_struct;

		break;
	}
	case TreeNodeType::UNION: {
		ReferencePtr<UnionNode> current_node = node.cast<UnionNode>();
		ReferencePtr<IdentifierNode> identifier_node = current_node->get_identifier_node();
		std::string union_name = identifier_node->get_identifier();

		TypeRef ref_struct = m_dtm->add_struct(union_name);
		m_symbol_table.add_symbol(identifier_node->get_identifier(), ref_struct);
		current_node->m_ir_composite_data_type = ref_struct;
		break;
	}
	default:
		break;
	}

	return;
}

void ASTConverter::post_order_traverse(const ReferencePtr<AbstractSyntaxTreeNode> &node) {
	if(!node)
		return;

	TreeNodeType type = node->get_type();
	switch (type)
	{
	case TreeNodeType::ASSIGNMENT: {
		// OK
		ReferencePtr<AssignmentNode> current_node = node.cast<AssignmentNode>();

		post_order_traverse(current_node->get_left_expr_node());
		post_order_traverse(current_node->get_right_expr_node());

		IROperand variable = get_op(current_node->get_left_expr_node());
		IROperand expr = get_op(current_node->get_right_expr_node());

		IRTriple* t = m_coder.add_triple(current_node->get_line_number(), IROperation::ASSIGN, variable, expr);
		set_op(current_node, t);

		break;
	}
	case TreeNodeType::FUNCTION_CALL: {
		ReferencePtr<FunctionCallNode> current_node = node.cast<FunctionCallNode>();
		std::string fn_name = current_node->get_identifier_node()->get_identifier();
		std::vector<IROperand> arg_operands;

		auto arguments = current_node->get_arguments();
		for (size_t i = 0; i < arguments->get_count(); i++)
			post_order_traverse(arguments->get_child(i));

		for (size_t i = 0; i < arguments->get_count(); i++)
			arg_operands.push_back(get_op(arguments->get_child(i)));

		// pick the function with the same arguments
		// we have to get a pointer to a function 
		IRFunction* fn_ptr = m_ir_program->get_function(fn_name, arg_operands);
		if (fn_ptr != nullptr)
			std::cout << "Function Found" << std::endl;

		arg_operands.insert(arg_operands.begin(), fn_ptr);

		IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::FUNCTION_CALL, arg_operands); //1

		set_op(current_node,triple);
		break;
	}
	case TreeNodeType::BIN_OPERATION: {
		// OK
		ReferencePtr<BinaryOperatorNode> current_node = node.cast<BinaryOperatorNode>();
		post_order_traverse(current_node->m_left);
		post_order_traverse(current_node->m_right);

		IROperand left = get_op(current_node->m_left);
		IROperand right = get_op(current_node->m_right);
		auto op = ast_op_to_ir_op(current_node->get_operation_type());

		IRTriple* t = m_coder.add_triple(current_node->get_line_number(), op, left, right);
		set_op(current_node, t);
		break;
	}
	case TreeNodeType::CONSTANT: {
		ReferencePtr<ConstantNode> current_node = node.cast<ConstantNode>();
		IRBasicType type = current_node->get_data_type();
		IRConstant* constant = m_current_fn->add_constant(current_node->get_constant_value());
		set_op(current_node, constant);
		break;
	}
	case TreeNodeType::DATA_TYPE: {
		// OK
		break;
	}
	//second_pass
	case TreeNodeType::DECLARATION: {
		ReferencePtr<DeclarationNode> current_node = node.cast<DeclarationNode>();
		ReferencePtr<ListNode<DeclarationListItemNode>> list = current_node->get_declarations();
		ReferencePtr<DataTypeNode> dtn = current_node->get_data_type_node();

		build_ir_data_type_from_ast(dtn);

		std::cout << "Build DataType: " << std::endl;
		std::cout << dtn->m_ir_data_type.to_string() << std::endl;
		
		if (m_current_fn) {
			for (size_t i = 0; i < list->get_child_count(); i++) {
				ReferencePtr<DeclarationListItemNode> current_item = list->get_element(i).cast<DeclarationListItemNode>();
				current_item->get_child(i);

				std::string variable_name = current_item->get_indentifier_node()->get_identifier();

				TypeRef type = dtn->m_ir_data_type;

				if (!m_symbol_table.can_add(variable_name))
					m_ast_converter_listener->error({ current_node->get_line_number(),"symbol " + variable_name + " is already used." });

				IRVariable* variable = m_current_fn->add_variable(variable_name, type);
				m_symbol_table.add_symbol(variable_name,variable);

				set_op(current_item, variable);

				AbstractSyntaxTreeNode* expr_node = current_item->get_expr_node();
				post_order_traverse(expr_node);

				if (expr_node != nullptr) {
					IROperand op_expr = get_op(expr_node);
					IRTriple* expr_triple = m_coder.add_triple(current_node->get_line_number(), IROperation::ASSIGN, variable, op_expr);
				}
			}
		}

		break;
	}
	case TreeNodeType::DECLARATION_LIST_ITEM: {
		ReferencePtr<DeclarationListItemNode> current_node = node.cast<DeclarationListItemNode>();
		// EMPTY
		break;
	}
	case TreeNodeType::IF: {
		// OK
		ReferencePtr<IfNode> current_node = node.cast<IfNode>();

		IRBasicBlock* stmt_blk = m_current_fn->add_basic_block("if_stmt");
		IRBasicBlock* else_stmt_blk = nullptr;
		IRBasicBlock* current_blk = m_coder.get_basic_block();

		if (current_node->m_else_stmt)
			else_stmt_blk = m_current_fn->add_basic_block("else_stmt");

		IRBasicBlock* after_if_basic_block = m_current_fn->add_basic_block("after_if");

		if (else_stmt_blk) {
			convert_control_flow_condition(current_node->m_expr, stmt_blk, else_stmt_blk);
		}
		else
			convert_control_flow_condition(current_node->m_expr, stmt_blk, after_if_basic_block);

		IROperand condition = get_op(current_node->m_expr);

		m_coder.set_basic_block(stmt_blk);
		post_order_traverse(current_node->m_stmt);

		if (current_node->m_else_stmt) {
			post_order_traverse(current_node->m_else_stmt);
			m_coder.set_basic_block(current_blk);

			m_coder.set_basic_block(stmt_blk);
			m_coder.add_triple(current_node->m_stmt->get_line_number(), IROperation::JMP, after_if_basic_block); // 1 

			m_coder.set_basic_block(else_stmt_blk);
			m_coder.add_triple(current_node->m_else_stmt->get_line_number(), IROperation::JMP, after_if_basic_block);//1

			m_coder.set_basic_block(after_if_basic_block);
		}
		else {
			m_coder.set_basic_block(current_blk);

			m_coder.set_basic_block(stmt_blk);
			m_coder.add_triple(current_node->m_stmt->get_line_number(), IROperation::JMP, after_if_basic_block); // 1
			m_coder.set_basic_block(after_if_basic_block);
		}

		break;
	}
	case TreeNodeType::WHILE: {
		ReferencePtr<WhileNode> current_node = node.cast<WhileNode>();

		IRBasicBlock* condition_blk = m_current_fn->add_basic_block("Condition");
		IRBasicBlock* while_blk = m_current_fn->add_basic_block("Body");
		IRBasicBlock* after_while_blk = m_current_fn->add_basic_block("AfterWhile");
		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, condition_blk); // 1

		m_coder.set_basic_block(condition_blk);

		convert_control_flow_condition(current_node->get_condition(), while_blk, after_while_blk);
		IROperand condition = get_op(current_node->get_condition());

		m_after_loop_blk.push_back(after_while_blk);
		m_condition_loop_blk.push_back(condition_blk);
		m_coder.set_basic_block(while_blk);
		post_order_traverse(current_node->get_block());
		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, condition_blk); //1 
		m_after_loop_blk.pop_back();
		m_condition_loop_blk.pop_back();

		m_coder.set_basic_block(after_while_blk);
		break;
	}
	case TreeNodeType::DO_WHILE: {
		// continue trzeba tutaj przemyslec 
		ReferencePtr<DoWhileNode> current_node = node.cast<DoWhileNode>();
		IRBasicBlock* do_while_blk = m_current_fn->add_basic_block("Body");
		IRBasicBlock* condition_blk = m_current_fn->add_basic_block("do_while Condition");
		IRBasicBlock* after_do_while_blk = m_current_fn->add_basic_block("After do_while");

		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, do_while_blk);
		m_coder.set_basic_block(do_while_blk);
		post_order_traverse(current_node->get_block());
		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, condition_blk);

		m_coder.set_basic_block(condition_blk);
		convert_control_flow_condition(current_node->get_condition(), do_while_blk, after_do_while_blk);

		IROperand condition = get_op(current_node->get_condition());
		m_coder.add_triple(current_node->get_line_number(), IROperation::JC, condition, do_while_blk, after_do_while_blk);
		m_coder.set_basic_block(after_do_while_blk);

		break;
	}
	// #TODO remove lines with m_current_basic_block = ... 
	case TreeNodeType::FOR: {
		ReferencePtr<ForNode> current_node = node.cast<ForNode>();

		IRBasicBlock* condition_blk = m_current_fn->add_basic_block();
		IRBasicBlock* for_blk = m_current_fn->add_basic_block();
		IRBasicBlock* for_expr_blk = m_current_fn->add_basic_block();
		IRBasicBlock* after_for_blk = m_current_fn->add_basic_block();

		post_order_traverse(current_node->get_init_stmt());
		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, condition_blk);

		m_coder.set_basic_block(condition_blk);

		convert_control_flow_condition(current_node->get_condition(),for_blk,after_for_blk);
		IROperand condition = get_op(current_node->get_condition());

		m_after_loop_blk.push_back(after_for_blk);
		m_condition_loop_blk.push_back(condition_blk);
		m_coder.set_basic_block(for_blk);
		post_order_traverse(current_node->get_block());
		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, for_expr_blk);
		m_after_loop_blk.pop_back();
		m_condition_loop_blk.pop_back();

		m_coder.set_basic_block(for_expr_blk);
		post_order_traverse(current_node->get_exprs());
		m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, condition_blk);

		m_coder.set_basic_block(after_for_blk);
		break;
	}
	case TreeNodeType::BREAK:
	{
		ReferencePtr<BreakNode> current_node = node.cast<BreakNode>();

		if (!m_after_loop_blk.empty())
			m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, m_after_loop_blk.back());
		else
			m_ast_converter_listener->error({ current_node->get_line_number(),"a break statement can only be used within a loop or a switch" });
		break;
	}
	case TreeNodeType::CONTINUE: {
		ReferencePtr<ContinueNode> current_node = node.cast<ContinueNode>();

		if (!m_condition_loop_blk.empty())
			m_coder.add_triple(current_node->get_line_number(), IROperation::JMP, m_condition_loop_blk.back());
		else
			m_ast_converter_listener->error({ current_node->get_line_number(),"a continue statement can only be used within a loop" });

		break;
	}
	case TreeNodeType::BLOCK: {
		//OK
		ReferencePtr<BlockNode> current_node = node.cast<BlockNode>();
		for (size_t i = 0; i < current_node->get_child_count(); i++)
			post_order_traverse(current_node->get_child(i));

		break;
	}
	case TreeNodeType::IDENTIFIER: {
		ReferencePtr<IdentifierNode> current_node = node.cast<IdentifierNode>();
		if (node->m_operand.m_operand_type == IROperandType::NO_OPERAND) {
			std::optional<IROperand> operand = m_symbol_table.find_symbol(current_node->get_identifier());
			if (operand.has_value())
				set_op(current_node,*operand);
			else
			{
				std::string msg = std::format("identifier {} not found",current_node->get_identifier());
				m_ast_converter_listener->error({ current_node->get_line_number(), msg });
			}
		}

		break;
	}
	case TreeNodeType::LIST: {
		int count = node->get_child_count();
		for (size_t i = 0; i < count; i++)
			post_order_traverse(node->get_child(i));
		break;
	}
	// second_pass
	case TreeNodeType::PROG: {
		ReferencePtr<ProgNode> current_node = node.cast<ProgNode>();
		m_current_fn = m_global_fn;
		auto nodes = current_node.get_ptr()->m_items;
		m_coder.set_basic_block(m_current_fn->get_basic_blk(0));
		for (size_t i = 0; i < nodes->get_count();i++) {
			auto node = nodes->get_child(i);
			if (node->get_tree_node_type() == TreeNodeType::DECLARATION)
			{
				ReferencePtr<DeclarationNode> dcl_node = node.cast<DeclarationNode>();
				ReferencePtr<ListNode<DeclarationListItemNode>> items = dcl_node->get_declarations();
				ReferencePtr<DataTypeNode> dtm = dcl_node->get_data_type_node();
				build_ir_data_type_from_ast(dtm);

				for (size_t j = 0; j < items->get_child_count();j++) {
					ReferencePtr<DeclarationListItemNode> item = items->get_child(j).cast<DeclarationListItemNode>();

					post_order_traverse(item->get_expr_node());
					std::string variable_name = item->get_indentifier_node()->get_identifier();
					IRGlobalVariable* variable = m_ir_program->add_variable(variable_name,dtm->m_ir_data_type);
					m_symbol_table.add_symbol(variable_name,variable);

					set_op(item,variable);

					AbstractSyntaxTreeNode* expr_node = item->get_expr_node();
					post_order_traverse(expr_node);

					if (expr_node != nullptr) {
						IROperand op_expr = get_op(expr_node);
						IRTriple* expr_triple = m_coder.add_triple(current_node->get_line_number(), IROperation::ASSIGN, variable, op_expr);
					}
				}
			}
			else if (node->get_tree_node_type() == TreeNodeType::STRUCT || node->get_tree_node_type() == TreeNodeType::UNION) {

				ReferencePtr<CompositeNode> composite_node = node.cast<CompositeNode>();
				ReferencePtr<IdentifierNode> m_identifier = composite_node->get_identifier_node();
				ReferencePtr<ListNode<MemberDeclarationNode>> declarations = composite_node->get_declarations();
				TypeRef current_composite_type = composite_node->m_ir_composite_data_type;
				IRCompositeTypeNode* casted_composite_node_type = static_cast<IRCompositeTypeNode*>(current_composite_type.get_data_type_node());

				for (size_t i = 0; i < declarations->get_child_count();i++) {
					ReferencePtr<MemberDeclarationNode> member_dcl = declarations->get_child(i).cast<MemberDeclarationNode>();

					std::string field_name = member_dcl->get_identifier()->get_identifier();
					build_ir_data_type_from_ast(member_dcl->get_data_type_node());
					TypeRef member_data_type_ref = member_dcl->get_data_type_node()->m_ir_data_type;
					casted_composite_node_type->add_field(member_data_type_ref,field_name);
				}

				// struct or union are fully processed
				try {
					casted_composite_node_type->close();
				}
				catch (std::runtime_error& e) {
					m_ast_converter_listener->error({ composite_node->get_line_number(),e.what() });
				}

			}
			else {
				ReferencePtr<FunctionNode> current_node = node.cast<FunctionNode>();
				m_current_fn = current_node->get_function_ptr();
				const std::vector<IRVariable*>& parameters = m_current_fn->get_parameters();
				
				m_symbol_table.add_layer();

				for (size_t i = 0; i < parameters.size();i++) {
					m_symbol_table.add_symbol(parameters[i]->get_variable_name(),parameters[i]);
				}

				m_coder.set_basic_block(m_current_fn->get_basic_blk(0));
				post_order_traverse(current_node->get_block_node());
	
				if (m_current_fn->get_return_type().is_void()) {
					auto blks = m_current_fn->get_basic_blocks();
					for (size_t i = 0; i < blks.size(); i++) {
						if (
							blks[i]->get_all_triples().back()->get_ir_operation() != IROperation::RETURN &&
							blks[i]->get_all_triples().back()->get_ir_operation() != IROperation::JMP &&
							blks[i]->get_all_triples().back()->get_ir_operation() != IROperation::JC
							) {
							m_coder.set_basic_block(blks[i]);
							m_coder.add_triple(current_node->get_line_number(), IROperation::RETURN, std::vector<IROperand>{});
						}
					}
				}

				m_symbol_table.pop_layer();
			}
		}
		break;
	}
	case TreeNodeType::TYPE_MODIFIER: {
		ReferencePtr<TypeModifierNode> current_node = node.cast<TypeModifierNode>();
		break;
	}
	case TreeNodeType::PARAMETER: {
		break;
	}
	case TreeNodeType::FUNCTION: {
		//ReferencePtr<FunctionNode> current_node = node.cast<FunctionNode>();
		//ReferencePtr<ListNode<FunctionParameterNode>> list = current_node->get_parameters();
		//m_current_fn = current_node->get_function_ptr();


		//for (size_t i = 0; i < list->get_child_count();i++) {
		//	ReferencePtr<FunctionParameterNode> param_node = list->get_child(i).cast<FunctionParameterNode>();
		//	ReferencePtr<IdentifierNode> id_node = param_node->get_identifier_node();

		//}

		break;
	}
	case TreeNodeType::SIZE_OF: {
		ReferencePtr<SizeOfNode> current_node = node.cast<SizeOfNode>();
		ReferencePtr<DataTypeNode> dtn = current_node->m_data_type;
		build_ir_data_type_from_ast(dtn);
		uint64_t size = 0;
		try {
			size = (uint64_t)dtn->m_ir_data_type.get_size();
		}
		catch (std::runtime_error &e) {
			m_ast_converter_listener->error({ current_node->get_line_number(),e.what()});
		}
	
		ConstantValue cv = { size };
		IRConstant* constant = m_current_fn->add_constant(cv);
		set_op(current_node, constant);

		break;
	}
	case TreeNodeType::ASSERT: {
		ReferencePtr<AssertNode> current_node = node.cast<AssertNode>();
		post_order_traverse(current_node->m_expr);
		IROperand op = get_op(current_node->m_expr);

		IRTriple *triple = m_coder.add_triple(current_node->get_line_number(),IROperation::ASSERT,op);
		break;
	}
	case TreeNodeType::PRINT: {
		ReferencePtr<PrintNode> current_node = node.cast<PrintNode>();
		post_order_traverse(current_node->m_expr);
		// only numeric types can be printed as for now 
		IROperand op = get_op(current_node->m_expr);
		
		IRTriple* triple = m_coder.add_triple(current_node->get_line_number(),IROperation::PRINT,op);
		set_op(current_node,triple);
		break;
	}
	case TreeNodeType::RETURN: {
		ReferencePtr<ReturnNode> current_node = node.cast<ReturnNode>();
		post_order_traverse(current_node->get_expr());
		if (current_node->get_expr()) {
			IROperand expr = get_op(current_node->get_expr());
			AbstractSyntaxTreeNode* node_operand_1 = current_node->get_expr();
			TreeNodeType type = node_operand_1->get_type();

			IRVariable* variable = nullptr;
			IRTriple* triple = nullptr;
			switch (type)
			{
				case TreeNodeType::IDENTIFIER: {
					std::string name = static_cast<IdentifierNode*>(node_operand_1)->get_identifier();
					variable = m_current_fn->get_variable(name);
					if (variable == nullptr)
						std::runtime_error("variable can't be nullptr");

					triple = m_coder.add_triple(current_node->get_line_number(), IROperation::RETURN, variable);
					break;
				}
				default: {
					IROperand return_triple = get_op(node_operand_1);
					triple = m_coder.add_triple(current_node->get_line_number(), IROperation::RETURN, return_triple);
					break;
				}
			}
			set_op(current_node, triple);
		}
		else {
			m_coder.add_triple(current_node->get_line_number(), IROperation::RETURN, std::vector<IROperand>{});
		}

		break;
	}
	case TreeNodeType::CAST: {
		ReferencePtr<CastNode> current_node = node.cast<CastNode>();
		post_order_traverse(current_node->get_expr_node());
		build_ir_data_type_from_ast(current_node->get_data_type_node());

		IROperand cast_type_op = get_op(current_node->get_data_type_node());
		IROperand expr_op = get_op(current_node->get_expr_node());
		IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::CAST, cast_type_op, expr_op);
		set_op(current_node, triple);
		break;
	}
	case TreeNodeType::REINTERPRET_CAST: {
		ReferencePtr<ReinterpretNode> current_node = node.cast<ReinterpretNode>();
		post_order_traverse(current_node->get_expr_node());
		build_ir_data_type_from_ast(current_node->get_data_type_node());

		IROperand cast_type_op = get_op(current_node->get_data_type_node());
		IROperand expr_op = get_op(current_node->get_expr_node());

		IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::REINTERPRET_CAST, cast_type_op, expr_op);

		set_op(current_node, triple);
		break;
	}
	case TreeNodeType::INC: {
		ReferencePtr<IncrementationNode> current_node = node.cast<IncrementationNode>();
		post_order_traverse(current_node->get_expr_node());
		// collect the old value 
		IROperand expr_op = get_op(current_node->get_expr_node());
		if (current_node->get_post_inc()) {
			IRTriple* coppied_value_triple = m_coder.add_triple(current_node->get_line_number(), IROperation::COPY, expr_op);
			IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::INC, expr_op);
			set_op(current_node, coppied_value_triple);
		}
		else {
			IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::INC, expr_op);
			set_op(current_node, triple);
		}
		break;
	}
	case TreeNodeType::DEC: {
		ReferencePtr<DecrementationNode> current_node = node.cast<DecrementationNode>();
		post_order_traverse(current_node->get_expr_node());
		IROperand expr_op = get_op(current_node->get_expr_node());

		if (current_node->get_post_dec()) {
			IRTriple* coppied_value_triple = m_coder.add_triple(current_node->get_line_number(), IROperation::COPY, expr_op);
			IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::DEC, expr_op);
			set_op(current_node, coppied_value_triple);
		}
		else {
			IRTriple* triple = m_coder.add_triple(current_node->get_line_number(), IROperation::DEC, expr_op);
			set_op(current_node, triple);
		}
		break;
	}
	case TreeNodeType::OR:
	case TreeNodeType::AND:
	case TreeNodeType::BOOLEAN_NOT: {
		convert_expression_to_bool(node);
		break;
	}
	case TreeNodeType::STRUCT: {
		ReferencePtr<StructNode> current_node = node.cast<StructNode>();
		
		break;
	}
	case TreeNodeType::UNION: {
		ReferencePtr<UnionNode> current_node = node.cast<UnionNode>();
		break;
	}
	// tutaj teraz
	case TreeNodeType::MEMBER_ACCESS: {
		// TODO wygenerowaæ triple 
		/*
			struct A {
				int m_a;
			};
		*/
		// A fun();
		// fun().m_a;
		ReferencePtr<MemberAccessNode> current_node = node.cast<MemberAccessNode>();
		ReferencePtr<IdentifierNode> id_node = current_node->get_field_identifier();
		ReferencePtr<AbstractSyntaxTreeNode> left_expr = current_node->get_expr();
		post_order_traverse(left_expr);

		IROperand left_expr_op = get_op(left_expr);
		TypeRef data_type_ref = left_expr_op.get_data_type();
		
		// it's a node that TypeRef indicates
		//IRDataTypeNode* data_type_node = data_type_ref.get_data_type_node();
		
		data_type_ref = data_type_ref.remove_reference();

		if (current_node->is_arrow()) {
			if (data_type_ref.is_pointer_with_qualifiers())
				data_type_ref = data_type_ref.remove_pointer_with_qualifiers();
			else {
				std::string msg = std::format("arrow used on non-pointer type");
				m_ast_converter_listener->error({ current_node->get_line_number(),msg });
				break;
			}
		}

		data_type_ref = data_type_ref.remove_qualifiers();
		
		if (data_type_ref.is_composite()) {
			std::string field_name = id_node->get_identifier();
			IRCompositeTypeNode* composite_node = static_cast<IRCompositeTypeNode*>(data_type_ref.get_data_type_node());
			if (IRMember* member = composite_node->get_member(field_name)) {
				IRTriple* member_access = m_coder.add_triple(current_node->get_line_number(), IROperation::MEMBER_ACCESS, left_expr_op, member);
				set_op(current_node, member_access);
			}
			else {
				std::string msg = std::format("composite type does not have field with name {}", field_name);
				m_ast_converter_listener->error({ current_node->get_line_number(),msg });
				break;
			}
		}

		break;
	}
	case TreeNodeType::ARRAY_ACCESS: {
		ReferencePtr<ArrayAccessNode> current_node = node.cast<ArrayAccessNode>();

		ReferencePtr<AbstractSyntaxTreeNode> array_name_expr = current_node->get_array_name_expr();
		ReferencePtr<AbstractSyntaxTreeNode> index_expr = current_node->get_index_expr();

		post_order_traverse(array_name_expr);
		post_order_traverse(index_expr);
		// t[1] = 10; write 
		// x = x + t[0]; read 
		IROperand array_name_expr_op =  get_op(array_name_expr);
		IROperand array_index_expr_op =  get_op(index_expr);

		IRTriple* array_assignment = m_coder.add_triple(current_node->get_line_number(),IROperation::ARRAY_ACCESS,array_name_expr_op,array_index_expr_op);

		set_op(current_node,array_assignment);
		break;
	}
	default:
		break;
	}
}
// special function for generating blocks of code for conditions
void ASTConverter::convert_control_flow_condition(const ReferencePtr<AbstractSyntaxTreeNode>& condition, IRBasicBlock* true_blk, IRBasicBlock* false_blk) {
	//schodzimi tutaj kiedy chcemy wygenerowac poprawny kod dla warunkow logicznych
	// czyli odpowiednie skoki do blkow itd.

	switch (condition.get_ptr()->get_tree_node_type())
	{
	case TreeNodeType::AND: {
		IRBasicBlock* new_true_blk = m_current_fn->add_basic_block();
		convert_control_flow_condition(condition.get_ptr()->get_child(0),new_true_blk, false_blk);
		m_coder.set_basic_block(new_true_blk);
		convert_control_flow_condition(condition.get_ptr()->get_child(1),true_blk,false_blk);
		break;
	}
	case TreeNodeType::OR: {
		IRBasicBlock* new_false_blk = m_current_fn->add_basic_block();
		convert_control_flow_condition(condition.get_ptr()->get_child(0), true_blk, new_false_blk);
		m_coder.set_basic_block(new_false_blk);
		convert_control_flow_condition(condition.get_ptr()->get_child(1), true_blk, false_blk);
		break;
	}
	case TreeNodeType::BOOLEAN_NOT: {
		// swaping blocks 
		convert_control_flow_condition(condition,false_blk,true_blk);
		break;
	}
	default:
		post_order_traverse(condition);
		auto boolean_condition = get_op(condition);
		m_coder.add_triple(condition,IROperation::JC,boolean_condition,true_blk,false_blk);
		break;
	}
}

void ASTConverter::convert_expression_to_bool(const ReferencePtr<AbstractSyntaxTreeNode>& expr) {
	
	IRBasicBlock* true_blk = m_current_fn->add_basic_block();
	IRBasicBlock* false_blk = m_current_fn->add_basic_block();
	IRBasicBlock* after_expr = m_current_fn->add_basic_block();

	std::string var_name = std::format("!tmp{}",m_temp_variable_count++);
	//m_dtm->get_bool;
	//IRVariable* temp_var = m_current_fn->add_variable(var_name,IRBasicType::BOOL);
	IRVariable* temp_var = m_current_fn->add_variable(var_name,m_dtm->get_bool());
	
	IRConstant* true_constant = m_current_fn->add_constant(true);
	IRConstant* false_constant = m_current_fn->add_constant(false);
	convert_control_flow_condition(expr,true_blk,false_blk);

	m_coder.set_basic_block(true_blk); 
	m_coder.add_triple(expr->get_line_number(), IROperation::ASSIGN, temp_var, true_constant);
	m_coder.add_triple(expr->get_line_number(),IROperation::JMP,after_expr);

	m_coder.set_basic_block(false_blk);
	m_coder.add_triple(expr->get_line_number(), IROperation::ASSIGN, temp_var, false_constant);
	m_coder.add_triple(expr->get_line_number(),IROperation::JMP,after_expr);

	m_coder.set_basic_block(after_expr);

	set_op(expr,temp_var);
}

void ASTConverter::convert(ASTConverterListener* listener) {
	m_ast_converter_listener = listener;
	m_dtm->get_void();
	//m_global_fn = m_ir_program->add_function("_global_function", IRBasicType::VOID, {}, {});
	m_global_fn = m_ir_program->add_function("_global_function", m_dtm->get_void(), {}, {});

	m_symbol_table.add_layer();
	first_pass(m_prog);
	second_pass(m_prog);
	m_symbol_table.pop_layer();

}
