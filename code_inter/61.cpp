void printTree(TreeNode* node) {
	if (!node)
		return;
	stack<TreeNode*> s[2];
	s[0].push(node);
	int cur = 0;
	int next = 1 - cur;
	bool left_to_right = true;
	while (!s[cur].empty() || !s[next].empty()) {
		while (!s[cur].empty()) {
			TreeNode* tmp = s[cur].top();
			s[cur].pop();
			cout << tmp->val << " ";
			if (left_to_right) {
				if (tmp->left)
					s[next].push(tmp->left);
				if (tmp->right)
					s[next].push(tmp->right);
			}
			else {
				if (tmp->right)
					s[next].push(tmp->right);
				if (tmp->left)
					s[next].push(tmp->left);
			}
		}
		cout << endl;
		left_to_right = !left_to_right;
		cur = next;
		next = 1 - cur;
	}
}