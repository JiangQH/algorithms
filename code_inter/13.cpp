void delNode(Node** head, Node* to_del) {
	if (!head || !*head || !to_del)
		return;
	if (to_del->next != NULL) {
		Node* tmp = to_del->next;
		to_del->val = tmp->val;
		to_del->next = tmp->next;
		delete tmp;
	}
	else if (*head == to_del) {
		*head = NULL;
		delete to_del;
	}
	else {
		Node* tmp = *head;
		while (tmp->next != to_del)
			tmp = tmp->next;
		tmp->next = NULL;
		delete to_del;
	}
}