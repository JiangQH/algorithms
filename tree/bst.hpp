// binary search tree
#ifndef BST_HPP_
#define BST_HPP_


TreeNode* make_empty(TreeNode* node) {
	if (node != NULL) {
		make_empty(node->left_);
		make_empty(node->right_);
		delete node;
	}
	return NULL;
}

template <typename T>
TreeNode* find(T x, TreeNode* node) {
	if (!node)
		return NULL;
	if (x < node->val_)
		return find(x, node->left_);
	else if (x > node->val_)
		return find(x, node->right_);
	else
		return node;
}


TreeNode* findmin(TreeNode* node) {
	if (node == NULL || node->left_ == NULL)
		return node;
	else
		return findmin(node->left_);
}


TreeNode* findMax(TreeNode* node){
	if (node == NULL || node->right_ == NULL)
		return node;
	else
		return findMax(node->right_);
}

template <typename T>
TreeNode* insert(TreeNode* node, T val) {
	if (!node) {
		TreeNode* node = new TreeNode();
		if (!node)
			throw std::exception("out of space");
		node->left_ = NULL;
		node->right_ = NULL;
		node->val_ = val_;
	}
	else {
		if (val < node->val) {
			node->left_ = insert(node->left_, val);
		}
		else if (val > node->val) {
			node->right_ = insert(node->right_, val);
		}
	}
	return node;
}

template <typename T>
TreeNode* del(T val, TreeNode* node) {
	if (!node)
		return NULL;
	if (val < node->val_)
		node->left_ = del(val, node->left_);
	else if (val > node->val_)
		node->right_ = del(val, node->right_);
	else {
		// two child
		if (node->left_ && node->right_) {
			// find right left most
			TreeNode* right = node->right_;
			while (right->left_)
				right = right->left_;
			node->val = right->val;
			node->right = del(node->val, node->right_);
		}
		else {
			TreeNode* tmp = node;
			if (node->left_)
				node = node->left_;
			else
				node = node->right_;
			delete tmp;
		}
	}
	return node;
}
#endif