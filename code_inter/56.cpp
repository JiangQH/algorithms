Node* meetingNode(Node* node) {
	if (!node)
		return NULL;
	Node* slower = node;
	Node* faster = node;
	while (faster->next) {
		slower = slower->next;
		faster = faster->next->next;
		if (slower == faster)
			break;
	}
	// no cycle
	if (faster->next == NULL)
		return NULL;
	faster = node;
	while (faster != slower) {
		faster = faster->next;
		slower = slower->next;
	}
	return slower;
}