
class ASTConverter {
public:
	// class resposnible for writing triples to basic blks
	IRCoder m_coder;
	SymbolTable m_symbol_table;
	ReferencePtr<ProgNode> m_prog;
	IRProgram *m_ir_program = nullptr;
	IRFunction *m_current_fn = nullptr;
	IRFunction* m_global_fn = nullptr;
	IRDataTypeManager* m_dtm;
	std::vector<IRBasicBlock*> m_after_loop_blk;
	std::vector<IRBasicBlock*> m_condition_loop_blk;
	size_t m_temp_variable_count;
	
	ASTConverterListener * m_ast_converter_listener;
	ASTConverter(const ReferencePtr<ProgNode>& p, IRProgram* i_p,IRDataTypeManager* dtm);
	// collects signatures
	void first_pass(const ReferencePtr<AbstractSyntaxTreeNode>& node);
	// it does everything else
	void second_pass(const ReferencePtr<AbstractSyntaxTreeNode>& node);

	void find_function_signatures(const ReferencePtr<AbstractSyntaxTreeNode>& node);
	void post_order_traverse(const ReferencePtr<AbstractSyntaxTreeNode>& node);
	void convert(ASTConverterListener *listener);
	//bool can_implicityly_convert_to();
	ConstantValue try_implicite_conversion(IRBasicType type, const ConstantValue& cv);


	IROperand get_op(const ReferencePtr<AbstractSyntaxTreeNode>& node);
	void set_op(const ReferencePtr<AbstractSyntaxTreeNode>& node, const IROperand& op);
	IROperation ast_op_to_ir_op(OperationType t);

	//IRBasicType data_type_to_ir_data_type(DataTypeNode type);

	void build_ir_data_type_from_ast(const ReferencePtr<DataTypeNode>& node);
	void convert_control_flow_condition(const ReferencePtr<AbstractSyntaxTreeNode>& condition,IRBasicBlock* true_blk,IRBasicBlock* false_blk);
	void convert_expression_to_bool(const ReferencePtr<AbstractSyntaxTreeNode>& condition);
};