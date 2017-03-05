Node* cloneList(Node* l) {
	if (!l)
		return NULL;
	l = cloneCore(l);
	l = cloneSibling(l);
	return seperateList(l);
}

Node* cloneCore(Node* l) {
	Node* cur = l;
	while (cur) {
		Node* tmp = new Node();
		tmp->val = cur->val;
		tmp->next = cur->next;
		tmp->sibling = NULL;
		cur = tmp->next;
	}
	return l;
}

Node* cloneSibling(Node* l) {
	Node* cur = l;
	while(cur) {
		Node* cloned = cur->next;
		if (cur->sibling != NULL)
			cloned->sibling = cur->sibling->next;
		cur = cloned->next;
	}
	return l;
}

Node* seperateList(Node* l) {
	Node* pclonedHead = l->next;
	Node* pcloned = pclonedHead;
	Node* ori = pcloned->next;
	while (ori) {
		pcloned->next = ori->next;
		pcloned = pcloned->next;
		ori->next = pcloned->next;
		ori	= ori->next;
	}
	return pclonedHead;
}