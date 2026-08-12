

class UselessControlFlowEliminator {
private:
	IRFunction* m_current_fn;
public:
	UselessControlFlowEliminator(IRFunction* fn);
	// transformation 1 
	bool fold_redundant_branch(IRFunction* fn);
	// transformation 2 
	bool find_and_remove_blocks_with_one_jmp(IRFunction* fn);
	// transformation 3
	bool combine_blocks(IRFunction* fn);
	void run();
};