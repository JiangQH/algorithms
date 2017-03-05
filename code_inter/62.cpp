string encodeTree(TreeNode* node) {
	if(!node) {
		return "#";
	}
	string result = to_string(node->val);
	left = encodeTree(node->left);
	right = encodeTree(node->right);
	return result + " " + left + " " + right;
}

TreeNode* decodeTree(const string& str) {
	istream ss(str);
	return decodeTreeCore(ss);
}

TreeNode* decodeTreeCore(istream& ss) {
	int number;
	if (readNum(ss, number)) {
		TreeNode* node = new TreeNode(number);
		node->left = NULL;
		node->right = NULL;
		node->left = decodeTreeCore(ss);
		node->right = decodeTreeCore(ss);
		return node;
	}
	return NULL;
}