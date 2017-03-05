int treeDepth(TreeNode* node) {
	if (!node)
		return 0;
	return max(treeDepth(node->left), treeDepth(node->right)) + 1;
}


bool isBalanceTree(TreeNode* node, int& height) {
	if (!node) {
		height = 0;
		return true;
	}
	int left_hegiht;
	bool left = isBalanceTree(node->left, left_hegiht);
	int right_height;
	bool right = isBalanceTree(node->right, right_height);
	if (left && right && abs(left_hegiht-rihgt_height) <= 1)
		return true;
	else
		return false;
}