

void IRInliner::expand_function_call(IRTriple* function_call) {
	// Sprawdzic czy parametery s¹ modyfikowane czy nie

	// Nie zawsze trzeba tworzyc FunctionResult
	
	IRFunction* fn = function_call->m_basic_blk->get_function();
	TypeRef return_type = fn->get_return_type();
	IRVariable* ir_variable = fn->add_variable("#function_result",return_type);

	// todo 
	//for () {

	//}

}