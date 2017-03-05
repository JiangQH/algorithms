TreeNode* convert(TreeNode* node) {
	if (!node)
		return NULL;
	TreeNode* lastInList = node;
	convertCore(node, lastInList);
	TreeNode* phead = lastInList;
	while (phead->left != NULL)
		phead = phead->left;
}

void convertCore(TreeNode* node, TreeNode** lastInList) {
	*lastInList = node;
	// the left
	if (node->left)
		convertCore(node->left, lastInList);
	node->left = *lastInList;
	if (*lastInList != NULL)
		(*lastInList)->right = node;
	*lastInList = node;
	if (node->right)
		convertCore(node->right, lastInList);
}