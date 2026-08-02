

void IRUsedObject::add_use_site(IRTriple* triple, size_t op_index) {
	IRUseSite* site = new IRUseSite{triple,op_index};
	m_use_sites.push_back(site);
}

void IRUsedObject::remove_use_site(IRTriple* triple, size_t index) {
	for (int i = 0; i < m_use_sites.size();i++) {
		if (m_use_sites[i]->m_triple == triple && m_use_sites[i]->m_operand_index==index) {
			delete m_use_sites[i];
			m_use_sites.erase(m_use_sites.begin()+i);
			break;
		}
	}
}

void IRUsedObject::replace_all_usages(IRUsedObject* other) {
	if (other == this)
		return;

	while (!m_use_sites.empty()) {
		IRUseSite* site = m_use_sites.back();
		IRTriple* user = site->m_triple;
		size_t operand_index = site->m_operand_index;
		user->set_operand(operand_index,other);
	}
}

bool IRUsedObject::is_used() { return !m_use_sites.empty(); }