Node* firstCommonNode(Node* node1, Node* node2) {
	if (!node1 || !node2)
		return NULL;
	// get there length
	int k1 = 0;
	Node* tmp = node1;
	while (tmp) {
		++k1;
		tmp = tmp->next;
	}
	int k2 = 0;
	tmp = node2;
	while (tmp) {
		++k2;
		tmp = tmp->next;
	}
	// get the longer and smaller
	Node* longer = node1;
	Node* smaller = node2;
	int distance = k1 - k2;
	if (distance < 0) {
		longer = node2;
		smaller = node1;
		distance = -distance;
	}
	// now longer walk
	while(distance) {
		longer = longer->next;
		--distance;
	}
	// now walk together
	while(smaller != longer) {
		smaller = smaller->next;
		longer = longer->next;
	}
	return smaller;
}