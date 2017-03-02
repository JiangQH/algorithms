#ifndef AVL_HPP_
#define AVL_HPP_
template <typename T>
struct AvlNode {
	T val_;
	AvlNode* left_;
	AvlNode* right_;
	int height_;
};

static int height (AvlNode* node) {
	if (!node)
		return -1;
	else
		return node->height_;
}

template <typename T>
AvlNode* insert(AvlNode* node, T val) {
	// if node is NULL
	if (!node) {
		node = new AvlNode();
		node->val_ = val;
		node->left_ = NULL;
		node->right_ = NULL;
		node->height_ = 1;
	}
	else {
		// if small, insert to left
		if (val < node->val_) {
			// insert to left
			node->left_ = insert(node->left_, val);
			if (height(node->left_) - height(node->right_) == 2) {
				// judge
				if (val < node->left_->val_) 
					// left and left, single rotate
					node = singleRotateLeft(node);
				else 
					// left and right
					node = doubleRotateLeft(node);
			}
		}

		else if (val > node->val_) {
			node->right_ = insert(node->right_, val);
			if (height(node->right_) - height(node->left_) == 2) {
				// judge
				if (val > node->right_->val_)
					node = singleRotateRight(node);
				else
					node = doubleRotateRight(node);
			}
		}
		// else do nothing
	}
	node->height = max(height(node->left_), height(node->right_)) + 1;
	return node;
}

template <typename T>
AvlNode* del(AvlNode* node, T val) {
	if (!node)
		return NULL;
	if (val < node->val_) {
		node->left_ = del(node->left_, val);
	}
	else if (val > node->val_) {
		node->right_ = del(node->right_, val);
	}
	else {
		// if it has two child
		if (node->left_ && node->right_) {
			// find right left most
			AvlNode* right = node->right_;
			while (right->left_)
				right = right->left_;
			// change the val and del
			node->val = right->val;
			node->right = del(node->right_, node->val_);
		}
		else {
			// only left child
			AvlNode* tmp = node;
			if (node->left_)
				node = node->left_;
			else
				node = node->right_;
			delete tmp;
		}
	}
	// update info and force avl
	if (node) {
		if (height(node->left_) - height(node->right_) == 2) {
			//judge
			if (height(node->left_->left_) >= height(node->left_->right_))
				node->left_ = singleRotateLeft(node->left_);
			else
				node = doubleRotateLeft(node);
		}
		else if (height(node->right_) - height(node->left_) == 2) {
			if (height(node->right_->right_) >= height(node->right_->left_))
				node->right_ = singleRotateRight(node->right_);
			else
				node = doubleRotateRight(node);
		}
	}
	node->height = max(height(node->left_), height(node->right_)) + 1;
	return node;
}



AvlNode* singleRotateLeft(AvlNode* node) {
	AvlNode* k2 = node;
	AvlNode* k1 = node->left_;
	k2->left_ = k1->right_;
	k1->right_ = k2;
	k1->height_ = max(height(k1->left_), height(k1->right_)) + 1;
	k2->height_ = max(height(k2->left_), height(k2->right_)) + 1;
	return k1;
}

AvlNode* singleRotateRight(AvlNode* node) {
	AvlNode* k2 = node;
	AvlNode* k1 = node->right_;
	k2->right_ = k1->left_;
	k1->left_ = k2;
	k1->height_ = max(height(k1->left_), height(k1->right_)) + 1;
	k2->height_ = max(height(k2->left_), height(k2->right_)) + 1;
	return k1;
}

AvlNode* doubleRotateLeft(AvlNode* node) {
	node->left_ = singleRotateRight(node->left_);
	return singleRotateLeft(node);
}

AvlNode* doubleRotateRight(AvlNode* node) {
	node->right_ = singleRotateLeft(node->right_);
	return singleRotateRight(node);
}


#endif