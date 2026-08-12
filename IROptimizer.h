

class IROptimizer {
private:
	IROperationExecutor m_operation_executor;
public:
	bool is_triple_dead(IRTriple* triple);
	bool check_if_all_constants(size_t n, const IRTriple* triple);
	void run(IRFunction* fn);
};