Node* reverse(Node* node) {
	if (!node)
		return NULL;
	if (node->next == NULL)
		return node;
	Node* head = reverse(node->next);
	node->next->next = node;
	return head;
}

Node* reverse(Node* node) {
	if (!node)
		return NULL;
	if (node->next == NULL)
		return node;
	Node* pre = node;
	Node* cur = node->next;
	Node* head = NULL;
	while (cur) {
		Node* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		if (cur == NULL)
			head = pre;
	}
	return head;
}