bool isSymmetric(TreeNode* node) {
	if (!node)
		false;
	return isSymmetric(node->left, node->right);
}

bool isSymmetric(TreeNode* left, TreeNode* right) {
	if (!left && !right)
		return true;
	if ((!left && right) || (left && !right) || (left->val != right->val))
		return false;
	return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}