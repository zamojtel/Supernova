
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

	m_basic_blocks = std::move(traversal_order);
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
	for (size_t i = 0; i < m_basic_blocks.size(); i++) {
		m_basic_blocks[i]->m_dominance_frontiers.clear();
	}

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