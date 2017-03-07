void printList(Node* node) {
	if (!node)
		return;
	if (!node->next)
		printList(node->next);
	cout << node->val << " ";
}