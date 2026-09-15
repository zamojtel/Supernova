
OverloadResolver::OverloadResolver(IRProgram* p) :m_ir_program{ p } { }

std::vector<IRFunction*> OverloadResolver::find_matching_functions(size_t line_number, const std::string& fn_name, const std::vector<IROperand>& arguments) {
	std::vector<IRFunction*> fns_with_name = m_ir_program->get_functions_with_name(fn_name);
	std::vector<bool> matching_fns_after_implicit_casting(fns_with_name.size(), true);
	std::vector<bool> exact_matching_fn(fns_with_name.size(), true);

	for (size_t j = 0; j < fns_with_name.size();j++) {
		IRFunction* fn = fns_with_name[j];
		if (fn->get_parameters().size()!=arguments.size()) {
			matching_fns_after_implicit_casting[j] = false;
			exact_matching_fn[j] = false;
		}
	}

	for (size_t i = 0; i < arguments.size(); i++) {

		for (size_t j = 0; j < fns_with_name.size(); j++) {
			if (!matching_fns_after_implicit_casting[j])
				continue;
			if (
				exact_matching_fn[j] &&
				fns_with_name[j]->get_parameters()[i]->get_data_type() != arguments[i].get_data_type() &&
				fns_with_name[j]->get_parameters()[i]->get_data_type().remove_qualifiers() != arguments[i].get_data_type().remove_qualifiers()
				) {
				exact_matching_fn[j] = false;
			}
			
			if (!IRDataTypeTraits::can_implicitly_convert_argument(arguments[i], fns_with_name[j]->get_parameters()[i]->get_data_type())) {
				exact_matching_fn[j] = false;
				matching_fns_after_implicit_casting[j] = false;
			}
		}
	}
	// somewhere here is a mistake 
	int exactly_matching_fn_index = -1;
	for (size_t i = 0; i < exact_matching_fn.size(); i++) {
		if (exact_matching_fn[i]) {
			exactly_matching_fn_index = i;
			break;
		}
	}

	if (exactly_matching_fn_index != -1)
		return { fns_with_name[exactly_matching_fn_index] };

	std::vector<size_t> matching_fn_indexes;
	for (size_t i = 0; i < matching_fns_after_implicit_casting.size(); i++) {
		if (matching_fns_after_implicit_casting[i])
			matching_fn_indexes.push_back(i);
	}

	if (matching_fns_after_implicit_casting.size() == 1 && matching_fns_after_implicit_casting[0])
		return { fns_with_name[0] };
	else if (matching_fns_after_implicit_casting.size() == 0)
		return {};
	else {
		std::vector<IRFunction*> matching_functions;
		for (size_t i = 0; i < matching_fns_after_implicit_casting.size(); i++) {
			if (matching_fns_after_implicit_casting[i])
				matching_functions.push_back(fns_with_name[i]);
		}

		return matching_functions;
	}
}

// for modules we consider that there might be more than one exact match  
bool OverloadResolver::is_better(const IRFunction *fn_1,const IRFunction* fn_2,const std::vector<IROperand>& arguments) {
	const std::vector<IRVariable*>& parameters_fn_1 = fn_1->get_parameters();
	const std::vector<IRVariable*>& parameters_fn_2 = fn_2->get_parameters();
	
	bool better_at_one_position = false;
	for (size_t i = 0; i < arguments.size();i++) {
		IROperand arg = arguments[i];
		TypeRef T_1 = parameters_fn_1[i]->get_data_type();
		TypeRef T_2 = parameters_fn_2[i]->get_data_type();

		if (T_1 == arg.get_data_type()) {
			if (T_2!=arg.get_data_type())
				better_at_one_position = true;
			// if there are equivalent then we just go further
		}
		else if (T_2 == arg.get_data_type()) {
			// fn_2 is better at this position
			return false;
		}
		else {
			if (IRDataTypeTraits::can_implicitly_convert(T_1, T_2))
			{
				if (!IRDataTypeTraits::can_implicitly_convert(T_2, T_1)) {
					better_at_one_position = true;
				}
				// else there are equivalent 
			}
			else {
				if (IRDataTypeTraits::can_implicitly_convert(T_2, T_1))
					return false;
			
				if (T_1.is_integer() && T_2.is_integer()) {
					if (T_1.is_signed() && !T_2.is_signed()) {
						better_at_one_position = true;
					}
					else if (!T_1.is_signed() && T_2.is_signed()) {
						return false;
					}
				}
			}
		}
	}

	return better_at_one_position;
}

OverloadMatch OverloadResolver::run(size_t line_number,const std::string& fn_name, const std::vector<IROperand>& arguments) {
	std::vector<IRFunction*> matching_fns = find_matching_functions(line_number,fn_name,arguments);
	if (matching_fns.size()==0)
		return OverloadMatch{MatchStatus::NO_MATCH,nullptr};

	for (size_t i = 0; i < matching_fns.size();i++) {
		bool ith_better_than_others = true;
		for (size_t j = 0; j < matching_fns.size();j++) {
			if (i == j)
				continue;

			if (!is_better(matching_fns[i], matching_fns[j], arguments)) {
				ith_better_than_others = false;
				break;
			}
		}

		if (ith_better_than_others) {
			return OverloadMatch{ MatchStatus::RESOLVED,matching_fns[i] };
		}
	}

	return { MatchStatus::AMBIGUOUS,nullptr };
}