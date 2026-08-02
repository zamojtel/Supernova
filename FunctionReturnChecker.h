
class FunctionReturnChecker {
public:
	FunctionReturnChecker();
	std::vector<IRBasicBlock*> check_all_paths(IRFunction* fn);

};