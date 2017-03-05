void printPath(TreeNode* node, int num) {
	if (!node)
		return;
	vector<TreeNode*> path;
	int cur_num = 0;
	printPathCore(node, num, cur_num, path);
}

void printPathCore(TreeNode* node, int num, int cur_num, vector<int>& path) {
	cur_num += node->val;
	path.push_back(node);
	// having reach the leaf and condition meet
	if (node->left == NULL && node->right == NULL && cur_num == num) {
		for (auto iter : path)
			cout << iter->val << " ";
		cout << endl;
	}
	
	if (node->left)
		printPathCore(node->left, num, cur_num, path);
	if (node->right)
		printPathCore(node->right, num, cur_num, path);
	cur_num -= node->val;
	path.pop_back();
}