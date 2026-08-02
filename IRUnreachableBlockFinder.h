

class IRUnreachableBlockFinder {
private:
	IRFunction* m_current_fn;
public:
	IRUnreachableBlockFinder(IRFunction* fn);
	std::vector<IRBasicBlock*> find_unreachable_blocks();
};