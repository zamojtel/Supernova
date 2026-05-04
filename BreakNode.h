
class BreakNode :public AbstractSyntaxTreeNode {
public:
	BreakNode() :AbstractSyntaxTreeNode{ TreeNodeType::BREAK } {}
};