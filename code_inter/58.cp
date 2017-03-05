TreeNode* nextNode(TreeNode* node) {
	if (!node)
		return NULL;
	// if query has a right child
	if (node->right != NULL)
		return node->right;
	TreeNode* next = NULL;
	if (node->parent != NULL) {
		// if it is the father's left child
		if (node == node->parent->left)
			next = node->parent;
		else {
			// find the node
			while (node->parent != NULL) {
				if (node->parent->left == node) {
					next = node->parent;
					break;
				}
				node = node->parent;
			}
		}
	}
	return next;
}