Node* delDuplicate(Node* node) {
	if (!node)
		return NULL;
	Node* head = node;
	Node* pre = NULL;
	while (node) {
		// check
		bool tobeDel = false;
		if (node->next && node->next->val == node->val)
			tobeDel = true;
		if (!tobeDel) {
			pre	= node;
			node = node->next;
		}
		else {
			// delete them all
			int val = node->val;
			while (node && node->val == val) {
				Node* tmp = node->next;
				delete node;
				node = tmp;
			}
			if (pre == NULL)
				head = node;
			else
				pre->next = node;
		}
	}
	return head;
}