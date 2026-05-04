class StructNode : public CompositeNode {
private:
public:
	StructNode(const ReferencePtr<IdentifierNode>& id, const ReferencePtr<ListNode<MemberDeclarationNode>>& list) : CompositeNode{ TreeNodeType::STRUCT,id,list} {
	};
};