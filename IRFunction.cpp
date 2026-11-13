
IRFunction::IRFunction(size_t index,const std::string& name,const TypeRef& r_t) 
	: IRBaseFunction("",index, {},r_t,IRBaseFunction::Kind::INTERNAL), m_triple_count{ 0 } 
{ 
	m_basic_blocks.push_back(new IRBasicBlock{ this, m_basic_blocks.size() });
}

IRFunction::IRFunction(size_t index, const std::string& name, bool is_inline, const TypeRef& r_t, IRProgram* p) 
	: IRBaseFunction(name,index, {},r_t,IRBaseFunction::Kind::INTERNAL), m_triple_count{ 0 }, m_is_inline{ is_inline }, m_return_type{ r_t }, m_ir_program{ p } 
{ 
	m_basic_blocks.push_back(new IRBasicBlock{ this, m_basic_blocks.size() });
}

void IRFunction::set_name(const std::string &name) {
	m_identifier = name;
}

const std::string& IRFunction::get_name() {
	return m_identifier;
}


IROperandType IRFunction::get_operand_type() const {
	return IROperandType::FUNCTION;
}

IROperand IRFunction::get_operand() {
	return this;
}

void IRFunction::add_parameter(const std::string &name, const TypeRef& type) {
	IRVariable* parameter = new IRLocalVariable{name,type,m_parameters.size()};
	// its present in both vectors
	m_parameters.push_back(parameter);
	m_parameter_types.push_back(parameter->get_data_type());
	m_variables.push_back(parameter);
}

IRVariable* IRFunction::add_variable(const std::string& name,const TypeRef& type) {
	IRVariable* variable = new IRLocalVariable{ name,type,m_variables.size() };
	m_variables.push_back(variable);
	return variable;
}

bool IRFunction::is_inline() const { return m_is_inline; }

void IRFunction::remove_blk(IRBasicBlock* blk) {
	// First of all, we have to clean after removing the block
	if (!blk)
		throw std::runtime_error("block is nullptr");

	blk->replace_all_usages(nullptr);
	blk->clear();
	m_basic_blocks.erase(m_basic_blocks.begin()+blk->get_index());
	delete blk;
}

IRConstant* IRFunction::add_constant(const ConstantValue &c) {
	// TODO sprawdzac czy juz nie ma tej samej stalej 
	// zeby sie nie tarfialo 5 razy true, albo false
	// tutaj poprawic 
	IRDataTypeManager *dtm = m_ir_program->get_dtm_manager();
	IRConstant* ir_constant = new IRConstant{m_constants.size(), c,dtm->get_basic_type_node(c.get_basic_type())};
	m_constants.push_back(ir_constant);

	return ir_constant;
}

IRConstant* IRFunction::add_constant(const StringRef &str_ref) {
	// TODO sprawdzac czy juz nie ma tej samej stalej 
	// zeby sie nie tarfialo 5 razy true, albo false
	// tutaj poprawic 
	IRDataTypeManager *dtm = m_ir_program->get_dtm_manager();
	TypeRef type = dtm->get_basic_type_node(IRBasicType::CHAR);
	type = dtm->add_qualifiers(type,IRQualifiersNode::CONST);
	type = dtm->add_pointer(type);
	IRConstant* ir_constant = new IRConstant{m_constants.size(),str_ref,type};
	m_constants.push_back(ir_constant);

	return ir_constant;
}

IRVariable* IRFunction::get_variable(const std::string& name) {
	for (size_t i = 0; i < m_variables.size(); i++) {
		if (m_variables[i]->get_variable_name() == name)
			return m_variables[i];
	}

	return nullptr;
}

bool IRFunction::has_variable(const std::string& name) const {
	for (auto &var : m_variables) {
		if (var->m_identifier == name)
			return true;
	}

	return false;
}

IRBasicBlock* IRFunction::get_basic_blk(size_t index) {
	if (index > m_basic_blocks.size())
		throw std::runtime_error{"basic block index out of range"};

	return m_basic_blocks.at(index);
}

const std::vector<IRBasicBlock*>& IRFunction::get_basic_blocks() const {
	return m_basic_blocks;
}

const std::vector<IRVariable*>& IRFunction::get_variables() const {
	return m_variables;
}

const IRVariable* IRFunction::get_variable(size_t index) const {
	return m_variables.at(index);
}


const IRConstant* IRFunction::get_constant(size_t index) const {
	return m_constants.at(index);
}

const std::vector<IRConstant*>& IRFunction::get_constants() const {
	return m_constants;
}

const std::vector<IRVariable*>& IRFunction::get_parameters() const {
	return m_parameters;
}

IRBasicBlock* IRFunction::add_basic_block() {
	IRBasicBlock* basic_blk = new IRBasicBlock{this,m_basic_blocks.size()};
	m_basic_blocks.push_back(basic_blk);
	return basic_blk;
}

IRBasicBlock* IRFunction::add_basic_block(const std::string& name) {
	IRBasicBlock* basic_blk = new IRBasicBlock{ this,m_basic_blocks.size(),name };
	m_basic_blocks.push_back(basic_blk);
	return basic_blk;
}

size_t IRFunction::get_triple_count() {
	return m_triple_count;
}

void IRFunction::reindex_triples() {
	size_t global_index = 0;

	for (IRBasicBlock *blk : m_basic_blocks) {
		auto& triples = blk->get_all_triples();
		for (size_t local_index = 0; local_index < triples.size();local_index++) {
			triples[local_index]->m_index = local_index;
			triples[local_index]->m_global_index = global_index++;
		}
	}

	m_triple_count = global_index;
}

const TypeRef& IRFunction::get_return_type() const {
	return m_return_type;
}

const std::string& IRFunction::get_identifier() const {
	return m_identifier;
}

size_t IRFunction::get_required_size() {
	return m_total_size_required;
}

IRProgram* IRFunction::get_ir_prgram() { return m_ir_program; }

std::vector<TypeRef> IRFunction::get_paramater_type() { 
	std::vector<TypeRef> paramater_types;
	for (auto& p : m_parameters)
		paramater_types.push_back(p->get_data_type());

	return paramater_types;
}

void IRFunction::sort_blocks() {
	IRBasicBlock* starting_blk = get_basic_blk(0);
	int number_of_blocks = get_basic_blocks().size();
	std::vector<bool> visited(number_of_blocks, false);
	std::queue<IRBasicBlock*> queue;
	std::vector<IRBasicBlock*> traversal_order;
	queue.push(starting_blk);
	traversal_order.push_back(starting_blk);

	visited[starting_blk->get_index()] = true;
	while (!queue.empty()) {

		IRBasicBlock* current_blk = queue.front();
		queue.pop();

		for (IRBasicBlock* successor : current_blk->get_successors()) {
			if (!visited[successor->get_index()]) {
				visited[successor->get_index()] = true;
				traversal_order.push_back(successor);
				queue.push(successor);
			}
		}
	}

	for (size_t i = 0; i < traversal_order.size(); i++)
		traversal_order[i]->set_index(i);

	for (size_t i = 0; i < number_of_blocks;i++) {
		if (!visited[i]) {
			for (IRTriple *triple : m_basic_blocks[i]->get_all_triples())
				triple->clear();
		}
	}

	for (size_t i = 0; i < number_of_blocks;i++) {
		if (!visited[i])
		{
			m_basic_blocks[i]->clear();
			delete m_basic_blocks[i];
		}
	}

	m_basic_blocks = std::move(traversal_order);
	reindex_triples();
}

void IRFunction::compute_dominator_sets() {
	sort_blocks();

	for (size_t i = 0; i < m_basic_blocks.size();i++)
		m_basic_blocks[i]->m_dominators.clear();

	// for the first one we put only itself as a dominator
	m_basic_blocks[0]->m_dominators.insert(m_basic_blocks[0]);
	for (size_t i = 1; i < m_basic_blocks.size();i++)
		m_basic_blocks[i]->m_dominators.insert(m_basic_blocks.begin(),m_basic_blocks.end());

	bool changed = true;
	while (changed) {
		changed = false;
		for (size_t i = 1; i < m_basic_blocks.size();i++) {
			auto preds = m_basic_blocks[i]->get_predecessors();
			std::set<IRBasicBlock*> intersection = preds[0]->m_dominators;

			for (size_t j = 1; j < preds.size();j++) {
				std::set<IRBasicBlock*> temp;
				std::set_intersection(
					intersection.begin(),intersection.end(),
					preds[j]->m_dominators.begin(),preds[j]->m_dominators.end(),
					std::inserter(temp,temp.begin())
				);
				intersection = std::move(temp);
			}
			
			intersection.insert(m_basic_blocks[i]);
			if (intersection != m_basic_blocks[i]->m_dominators) {
				m_basic_blocks[i]->m_dominators = std::move(intersection);
				changed = true;
			}
		}
	}

	for (size_t i = 0; i < m_basic_blocks.size();i++) {
		m_basic_blocks[i]->m_dominator_tree_successors.clear();
		m_basic_blocks[i]->m_idom = nullptr;
	}

	// to determine idom we search for a second greatest block  
	for (int i = 1; i < m_basic_blocks.size(); i++) {
		IRBasicBlock* idom = nullptr;
		int second_largest_index = -1;
		int forbidden_index = static_cast<int>(m_basic_blocks[i]->get_index());

		for (auto dom : m_basic_blocks[i]->m_dominators) {
			int index = static_cast<int>(dom->get_index());
			if ( index >second_largest_index && index != forbidden_index) {
				idom = dom;
				second_largest_index = index;
			}
		}
		
		m_basic_blocks[i]->m_idom = idom;
		if (idom != nullptr)
			idom->m_dominator_tree_successors.push_back(m_basic_blocks[i]);
	}
}

void IRFunction::compute_dominance_frontiers() {
	for (size_t i = 0; i < m_basic_blocks.size(); i++)
		m_basic_blocks[i]->m_dominance_frontiers.clear();

	for (int i = 0; i < m_basic_blocks.size();i++) {
		auto current_blk = m_basic_blocks[i];
		if (current_blk->get_predecessors().size()>1) {
			for (IRBasicBlock *pred : current_blk->get_predecessors()) {
				auto runner = pred;
				while (runner!=current_blk->m_idom) {
					runner->m_dominance_frontiers.insert(current_blk);
					runner = runner->m_idom;
				}
			}
		}
	}
}

void IRFunction::compute_live_variables() {
	for (size_t i = 0; i < m_basic_blocks.size();i++) {
		m_basic_blocks[i]->m_use.clear();
		m_basic_blocks[i]->m_def.clear();
		m_basic_blocks[i]->m_live_in.clear();
		m_basic_blocks[i]->m_live_out.clear();
	}

	// the entry block B0 for parameters 
	// is treated as the place where parameters are defined
	for (size_t i = 0; i < m_parameters.size(); i++)
		m_basic_blocks[0]->m_def.insert(m_parameters[i]);

	for (IRBasicBlock* blk : m_basic_blocks) {
		const std::vector<IRTriple*> triples = blk->get_all_triples();
		for (size_t i = 0; i < triples.size(); i++) {
			switch (triples[i]->get_ir_operation())
			{
			case IROperation::INIT_ASSIGN:
			case IROperation::ASSIGN:{
				IROperand right_operand = triples[i]->m_operands[1];
				IROperand left_operand = triples[i]->m_operands[0];
				if (right_operand.m_operand_type == IROperandType::VARIABLE) {
					IRVariable* variable = right_operand.get_variable();
					if (blk->m_def.count(variable) == 0)
						blk->m_use.insert(variable);
				}

				if (left_operand.m_operand_type == IROperandType::VARIABLE) {
					IRVariable* variable = left_operand.get_variable();
					blk->m_def.insert(variable);
				}
				break;
			}
			case IROperation::INC:
			case IROperation::DEC: {
				IROperand operand = triples[i]->m_operands[0];
				
				if (operand.m_operand_type == IROperandType::VARIABLE) {
					IRVariable* variable = operand.get_variable();
					if (blk->m_def.count(variable)==0) {
						blk->m_use.insert(variable);
						blk->m_def.insert(variable);
					}
				}

				break;
			}
			default:
				for (size_t j = 0; j < triples[i]->m_operands.size();j++) {
					IROperand current_operand = triples[i]->m_operands[j];
					if (current_operand.m_operand_type==IROperandType::VARIABLE) {
						IRVariable* variable = current_operand.get_variable();
						if(blk->m_def.count(variable)==0)
							blk->m_use.insert(variable);
					}
				}
				break;
			}
		}
	}

	bool changed = true;
	while (changed) {

		changed = false;
		for (int i = static_cast<int>(m_basic_blocks.size()) - 1 ; i >= 0;i--) {
			IRBasicBlock* current_blk = m_basic_blocks[i];
			std::vector<IRBasicBlock*> successors = current_blk->get_successors();
			std::set<IRVariable*> live_out_sum;

			for (int j = 0; j < successors.size();j++)
				live_out_sum.insert(successors[j]->m_live_in.begin(),successors[j]->m_live_in.end());
			
			if (current_blk->m_live_out != live_out_sum) {
				current_blk->m_live_out = std::move(live_out_sum);
				changed = true;
			}

			std::set<IRVariable*> live_in_result;
			live_in_result.insert(current_blk->m_use.begin(),current_blk->m_use.end());
			
			std::set<IRVariable*> difference_result;
			std::set_difference(current_blk->m_live_out.begin(),current_blk->m_live_out.end(),current_blk->m_def.begin(),current_blk->m_def.end(),std::inserter(difference_result,difference_result.begin()));
			live_in_result.insert(difference_result.begin(),difference_result.end());
			if (current_blk->m_live_in != live_in_result) {
				current_blk->m_live_in = std::move(live_in_result);
				changed = true;
			}
		}
	}
}

void IRFunction::compute_phi_functions() {
	// phi insertion 
	for (IRBasicBlock* blk : m_basic_blocks)
		blk->m_variable_has_phi.clear();

	for (IRVariable* var : m_ssa_variable_candidates) {
		std::queue<IRBasicBlock*> work_list;
		std::unordered_set<IRBasicBlock*> ever_on_work_list;

		for (IRBasicBlock* blk : m_basic_blocks) {
			if (blk->m_def.count(var) > 0) {
				work_list.push(blk);
				ever_on_work_list.insert(blk);
			}
		}

		// X is currently processed block
		// Y is an element from the dominance_froniter list of block X
		while (!work_list.empty()) {
			IRBasicBlock* X = work_list.front();
			work_list.pop();

			for (IRBasicBlock* Y : X->m_dominance_frontiers) {
				if (Y->m_live_in.count(var) > 0 && Y->m_variable_has_phi.count(var) == 0) {
					Y->m_variable_has_phi.insert(var);

					if (ever_on_work_list.count(Y) == 0) {
						work_list.push(Y);
						ever_on_work_list.insert(Y);
					}
				}
			}
		}
	}
}

void IRFunction::insert_phi_functions() {
	IRCoder coder(m_ir_program);
	
	for (IRBasicBlock *blk : m_basic_blocks) {
		if (blk->m_variable_has_phi.size()>0) {
			coder.set_position_at_start(blk);
			int current_line_number = 0;
			for (IRVariable* var : blk->m_variable_has_phi) {
				std::vector<IROperand> operands;
				operands.push_back(var);
				
				for (IRBasicBlock* pred : blk->get_predecessors()) {
					operands.push_back(pred);
					operands.push_back(IROperand{});
				}

				coder.add_triple(current_line_number++,IROperation::PHI,operands);
			}
		}
	}
	reindex_triples();
}

void IRFunction::collect_ssa_variable_candidates() {
	m_ssa_variable_candidates.clear();
	for (IRVariable* variable : m_variables) {
		const TypeRef type = variable->get_data_type();
		if (type.is_reference())
			continue;

		const TypeRef clean_type = type.remove_qualifiers();

		if (clean_type.is_array() || clean_type.is_pointer())
			continue;

		if (clean_type.is_basic_data_type())
			m_ssa_variable_candidates.insert(variable);
	}
}

void IRFunction::filter_addressable_variables() {
	// there are 4 cases in which we remove the variable
	// 1. We take the address of this variable anywhere in the code
	// 2. if the left operand is a reference example int& r = x;
	// 3. if a reference is passed as a parameter
	// 4. in cases of INC and DEC because both of them modify the variable in place

	for (IRBasicBlock* blk : m_basic_blocks) {
		std::vector<IRTriple*> triples = blk->get_all_triples();
		for (int i = 0; i < triples.size(); i++) {
			IROperation operation = triples[i]->get_ir_operation();

			if (operation == IROperation::ADDRESS_OF) {
				if (triples[i]->m_operands[0].m_operand_type == IROperandType::VARIABLE)
				{
					IRVariable* variable = triples[i]->m_operands[0].get_variable();
					m_ssa_variable_candidates.erase(variable);
				}
			}

			if (operation == IROperation::INIT_ASSIGN) {
				if (triples[i]->m_operands[0].get_data_type().is_reference() && triples[i]->m_operands[1].m_operand_type == IROperandType::VARIABLE) {
					IRVariable* variable = triples[i]->m_operands[1].get_variable();
					m_ssa_variable_candidates.erase(variable);
				}
			}

			if (operation == IROperation::FUNCTION_CALL || operation == IROperation::EXTERNAL_FUNCTION_CALL) {
				
				IRBaseFunction * fn = triples[i]->m_operands[0].get_base_function();
				const std::vector<TypeRef> parameter_types = fn->get_parameter_types();

				for (size_t j = 0; j < parameter_types.size();j++) {
					if (parameter_types[j].is_reference() && triples[i]->m_operands[j+1].m_operand_type==IROperandType::VARIABLE) {
						IRVariable* variable = triples[i]->m_operands[j+1].get_variable();
						m_ssa_variable_candidates.erase(variable);
					}
				}
			}

			if (operation == IROperation::INC || operation == IROperation::DEC) {
				if(triples[i]->m_operands[0].m_operand_type==IROperandType::VARIABLE)
					m_ssa_variable_candidates.erase(triples[i]->m_operands[0].get_variable());
			}
		}
	}
}

void IRFunction::rename_variables_in_block(IRBasicBlock* blk) {
	std::vector<IRVariable*> pushed_variables;
	std::vector<IRTriple*> triples = blk->get_all_triples();
	
	for (IRTriple* triple : triples) {
		IROperation operation = triple->get_ir_operation();

		switch (operation) {
			case IROperation::PHI: {
				IRVariable* variable = triple->m_operands[0].get_variable();
				m_ssa_variable_stacks[variable].push_back(triple);
				pushed_variables.push_back(variable);

				break;
			}
			case IROperation::INIT_ASSIGN:
			case IROperation::ASSIGN:
			{
				if (operation == IROperation::ASSIGN || operation == IROperation::INIT_ASSIGN) {
					if (triple->m_operands[1].m_operand_type == IROperandType::VARIABLE) {
						IRVariable* right_variable = triple->m_operands[1].get_variable();
						if (m_ssa_variable_candidates.count(right_variable) > 0 && !m_ssa_variable_stacks[right_variable].empty())
							triple->set_operand(1, m_ssa_variable_stacks[right_variable].back());
					}

					if (triple->m_operands[0].m_operand_type == IROperandType::VARIABLE) {
						IRVariable* left_variable = triple->m_operands[0].get_variable();
						if (m_ssa_variable_candidates.count(left_variable) > 0) {
							m_ssa_variable_stacks[left_variable].push_back(triple->m_operands[1]);
							pushed_variables.push_back(left_variable);
							// removing triple
							blk->remove_triple(triple);
						}
					}
				}

				break;
			}
			default:
			{	
				for (size_t j = 0; j < triple->m_operands.size();j++) {
					if (triple->m_operands[j].m_operand_type == IROperandType::VARIABLE && m_ssa_variable_candidates.count(triple->m_operands[j].get_variable()))
					{
						IRVariable* variable = triple->m_operands[j].get_variable();
						if(!m_ssa_variable_stacks[variable].empty())
							triple->set_operand(j,m_ssa_variable_stacks[variable].back());
					}
				}
				break;
			}
		}
	}

	for (IRBasicBlock* succ : blk->get_successors()) {
		std::vector<IRTriple*> triples = succ->get_all_triples();
		for (IRTriple * triple : succ->get_all_triples()) {
			IROperation operation = triple->get_ir_operation();
			if (operation==IROperation::PHI) {
				IRVariable* phi_variable = triple->m_operands[0].get_variable();
				for (size_t k = 1; k < triple->m_operands.size();k+=2) {
					if (triple->m_operands[k].m_operand_type == IROperandType::BASIC_BLOCK) {
						if (triple->m_operands[k].get_basic_block()==blk) {
							if (!m_ssa_variable_stacks[phi_variable].empty())
								triple->set_operand(k + 1, m_ssa_variable_stacks[phi_variable].back());
						}
					}
				}
			}
		}
	}

	for (IRBasicBlock* child : blk->m_dominator_tree_successors)
		rename_variables_in_block(child);

	for (IRVariable* variable : pushed_variables)
		m_ssa_variable_stacks[variable].pop_back();

}

void IRFunction::rename_variables() {
	if (m_basic_blocks.empty())
		return;

	m_ssa_variable_stacks.clear();
	for (auto parameter : m_parameters) {
		if (m_ssa_variable_candidates.count(parameter) > 0)
			m_ssa_variable_stacks[parameter].push_back(parameter);
	}

	rename_variables_in_block(m_basic_blocks[0]);
	reindex_triples();
	m_ir_program->calculate_size_required_for_fn(this);
}

void IRFunction::convert_to_ssa() {
	compute_dominator_sets();
	compute_dominance_frontiers();
	compute_live_variables();

	collect_ssa_variable_candidates();
	filter_addressable_variables();
	compute_phi_functions();
	insert_phi_functions();
	rename_variables();
}