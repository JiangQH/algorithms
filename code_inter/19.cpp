TreeNode* sysmetricTree(TreeNode* node) {
	if (!node)
		return NULL;
	// swap left and right
	TreeNode* tmp = node->left;
	node->left = node->right;
	node->right = tmp;
	node->left = sysmetricTree(node->left);
	node->right = sysmetricTree(node->right);
	return node;
}