void printTree(TreeNode* node) {
	if (!node)
		return;
	queue<TreeNode*> q;
	q.push(node);
	int cur_level = 1;
	int next_level = 0;
	while (!q.empty()) {
		for (int i = 0; i < cur_level; ++i) {
			TreeNode* tmp = q.front();
			q.pop();
			cout << tmp->val << " ";
			if (tmp->left) {
				++next_level;
				q.push(tmp->left);
			}
			if (tmp->right) {
				++next_level;
				q.push(tmp->right);
			}
		}
		cout << endl;
		cur_level = next_level;
		next_level = 0;
	}
}