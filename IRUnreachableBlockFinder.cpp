
IRUnreachableBlockFinder::IRUnreachableBlockFinder(IRFunction* fn) : m_current_fn{fn} {}

std::vector<IRBasicBlock*> IRUnreachableBlockFinder::find_unreachable_blocks() {
	std::vector<IRBasicBlock*> unreachable_blks;
	IRBasicBlock* s = m_current_fn->get_basic_blk(0);
	//auto all_blks
	auto& all_blks = m_current_fn->get_basic_blocks();
	int n = all_blks.size();
	std::queue<IRBasicBlock*> q;
	std::vector<int> visited(n,false);
	q.push(s);
	visited[s->get_index()] = true;

	while (!q.empty()) {

		IRBasicBlock* b = q.front();
		q.pop();
		auto successors = b->get_successors();

		for (int i = 0; i < successors.size();i++) {
			if (!visited[successors[i]->get_index()]) {
				visited[successors[i]->get_index()] = true;
				q.push(successors[i]);
			}
		}
	}

	for (int j = 0; j < visited.size(); j++) {
		if (!visited[j])
			unreachable_blks.push_back(all_blks[j]);
	}

	return unreachable_blks;
}
