

void IRFunction::set_name(const std::string &name) {
	m_identifier = name;
}

const std::string& IRFunction::get_name() {
	return m_identifier;
}

void IRFunction::add_parameter(const std::string &name, const TypeRef& type) {
	IRVariable* parameter = new IRLocalVariable{name,type,m_parameters.size()};
	// its present in both vectors
	m_parameters.push_back(parameter);
	m_variables.push_back(parameter);
}

IRVariable* IRFunction::add_variable(const std::string& name,const TypeRef& type) {
	IRVariable* variable = new IRLocalVariable{ name,type,m_variables.size() };
	m_variables.push_back(variable);
	return variable;
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

const std::vector<IRVariable*>& IRFunction::get_parameters() {
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

const TypeRef& IRFunction::get_return_type() const {
	return m_return_type;
}

size_t IRFunction::get_index() {
	return m_index;
}

bool IRFunction::compare_arguments(const std::vector<IROperand>& arguments) {
	// show 
	// for now it will ignore operands other than variables 
	if (m_parameters.size() != arguments.size())
		return false;

	for (size_t i = 0; i < arguments.size();i++) {
		if (m_parameters[i]->get_data_type() != arguments[i].get_data_type())
			return false;
	}

	return true;
}

const std::string& IRFunction::get_identifier() const {
	return m_identifier;
}

size_t IRFunction::get_required_size() {
	return m_total_size_required;
}