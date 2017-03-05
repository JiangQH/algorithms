bool isSubTree(TreeNode* node1, TreeNode* node2) {
	if (!node1 || !node2)
		return false;
	bool is = false;
	if (node1->val == node2->val)
		is = isSubTreeCore(node1, node2);
	if (!is)
		is = isSubTree(node1->left, node2);
	if (!is)
		is = isSubTree(node1->right, node2);
	return is;
}

bool isSubTreeCore(TreeNode* node1, TreeNode* node2) {
	if (!node1 && !node2)
		return true;
	if (!node1 || !node2)
		return false;
	if (node1->val != node2->val)
		return false;
	return isSubTreeCore(node1->left, node2->left) && isSubTreeCore(node1->right, node2->right);
}
