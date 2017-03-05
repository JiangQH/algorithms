bool getPath(TreeNode* cur, TreeNode* node, vector<TreeNode*>path) {
	path.push_back(cur);
	if (cur == node)
		return true;
	bool found = false;
	for (auto iter = cur->childs.begin(); iter != cur->childs.end(); ++iter) {
		found = getPath(*iter, node, path);
		if (found)
			break;
	}
	// have we find it?
	if (!found)
		path.pop_back();
	return found;
}

TreeNode* FirstCommonNode(TreeNode* root, TreeNode* node1, TreeNode* node2) {
	if (!root || !node1 || !node2)
		return NULL;
	// get there path
	vector<TreeNode*> path1;
	vector<TreeNode*> path2;
	bool found1 = getPath(root, node1, path1);
	bool found2 = getPath(root, node2, path2);
	if (!found1 || !found2)
		return NULL;
	// get the last common node
	return LastCommonNode(path1, path2);
}

TreeNode* LastCommonNode(const vector<TreeNode*>& path1, const vector<TreeNode*> path2) {
	if (path1.empty() || path2.empty())
		return NULL;
	TreeNode* node = NULL;
	for (int i = 0; i < path1.size(), i < path2.size(); ++i) {
		if (path1[i] == path2[i])
			node = path1[i];
		else
			break;
	}
	return node;
}