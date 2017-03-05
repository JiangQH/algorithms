BstTreeNode* kthNode(BstTreeNode* node, int k) {
	if (!node || k <= 0)
		return NULL;
	return kthNodeCore(node, k);
}

BstTreeNode* kthNodeCore(BstTreeNode* node, int& k) {
	target = NULL;
	// find left
	if (node->left != NULL)
		target = kthNodeCore(node->left, k);
	if (target == NULL) {
		--k;
		if (k == 0)
			target = node;
	}
	if (target == NULL && node->right)
		target = kthNodeCore(node->right, k);
	return target;
}