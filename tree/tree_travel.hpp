void preorderRecur(TreeNode* node, vector<int>& res) {
	if (!node)
		return;
	res.push_back(node->val);
	preorderRecur(node->left, res);
	preorderRecur(node->right, res);
}

void preorder(TreeNode* node, vector<int>& res) {
	if (!node)
		return;
	stack<TreeNode*> s;
	TreeNode* cur = node;
	while (cur || !s.empty()) {
		if (cur) {
			res.push_back(cur->val);
			s.push(cur);
			cur = cur->left;
		}
		else if (!s.empty()) {
			cur = s.top();
			s.pop();
			cur = cur->right;
		}
	}
}

void inorderRecur(TreeNode* node, vector<int>& res) {
	if (!node)
		return;
	inorderRecur(node->left, res);
	res.push_back(node->val);
	inorderRecur(node->right, res);
}

void inorder(TreeNode* node, vector<int>& res) {
	if (!node)
		return;
	stack<TreeNode*> s;
	TreeNode* cur = node;
	while (cur || !s.empty()) {
		if (cur) {
			s.push(cur);
			cur = cur->left;
		}
		else if (!s.empty()) {
			// visit it now
			cur = s.top();
			s.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}
	}
}

void postOrderRecur(TreeNode* node, vector<int>& res) {
	if (!node)
		return;
	postOrderRecur(node->left, res);
	postOrderRecur(node->right, res);
	res.push_back(node->val);
}

void postOrder(TreeNode* node, vector<int>& res) {
	if (!node)
		return;
	stack<TreeNode*> s;
	TreeNode* pre = NULL;
	s.push(node);
	while (!s.empty()) {
		TreeNode* cur = s.top();
		if ((cur->left == NULL) && (cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right))) {
			s.pop();
			res.push_back(cur->val);
			pre = cur;
		}
		else {
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
	}
}

