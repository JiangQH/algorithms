void printTree(TreeNode* node) {
	if (!node)
		return;
	queue<TreeNode*> q;
	q.push(node);
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		cout << tmp->val << " ";
		if (tmp->left)
			q.push(tmp->left);
		if (tmp->right)
			q.push(tmp->right);
	}
}