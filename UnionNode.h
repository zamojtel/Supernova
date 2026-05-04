class UnionNode : public CompositeNode {
private:
public:
	UnionNode(const ReferencePtr<IdentifierNode>& id,const ReferencePtr<ListNode<MemberDeclarationNode>> &list) : CompositeNode{ TreeNodeType::UNION,id, list} {};
};