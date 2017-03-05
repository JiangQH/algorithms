Node* lastKNode(Node* node, int k) {
	if (!node || k < 1)
		return NULL;
	// walk k-1 step
	Node* walker = node;
	while (k-1) {
		walker = walker->next;
		if (!walker)
			break;
		--k;
	}
	if (!walker)
		return NULL;
	while (walker->next) {
		node = node->next;
		walker = walker->next;
	}
	return node;
}