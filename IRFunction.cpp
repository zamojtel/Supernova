
IRFunction::IRFunction(size_t index,const std::string& name,const TypeRef& r_t) 
	: IRBaseFunction("", {},r_t,IRBaseFunction::Kind::INTERNAL), m_triple_count{ 0 }, m_index{ index } 
{ 
	m_basic_blocks.push_back(new IRBasicBlock{ this, m_basic_blocks.size() });
}

IRFunction::IRFunction(size_t index, const std::string& name, bool is_inline, const TypeRef& r_t, IRProgram* p) 
	: IRBaseFunction(name, {},r_t,IRBaseFunction::Kind::INTERNAL), m_triple_count{ 0 }, m_index{ index }, m_is_inline{ is_inline }, m_return_type{ r_t }, m_ir_program{ p } 
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

size_t IRFunction::get_index() {
	return m_index;
}
//
//bool IRFunction::compare_arguments(const std::vector<IROperand>& arguments) {
//	// for now it will ignore operands other than variables 
//	if (m_parameters.size() != arguments.size())
//		return false;
//
//	for (size_t i = 0; i < arguments.size();i++) {
//		if (m_parameters[i]->get_data_type().remove_reference() != arguments[i].get_data_type().remove_reference())
//			return false;
//	}
//
//	return true;
//}

//bool IRFunction::compare_arguments(const std::vector<TypeRef>& argument_types) {
//	// for now it will ignore operands other than variables 
//	auto parameter_types = get_parameter_types();
//	if (parameter_types.size() != argument_types.size())
//		return false;
//
//	for (size_t i = 0; i < argument_types.size();i++) {
//		if (parameter_types[i].remove_reference() != argument_types[i].remove_reference())
//			return false;
//	}
//
//	return true;
//}

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