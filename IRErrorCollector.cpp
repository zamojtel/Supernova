
void IRErrorCollector::add_error(size_t line_number,ErrorType type,const std::string& error_msg){
	m_errors.push_back(new IRError{ line_number,type,error_msg });
}

const std::vector<IRError*>& IRErrorCollector::get_errors() const { return m_errors; }