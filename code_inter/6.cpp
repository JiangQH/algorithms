TreeNode* buildTree(const vector<int>& nums1, const vector<int>& nums2) {
	if (nums1.empty() || nums2.empty() || nums1.size() != nums2.size())
		return NULL;
	return buildCore(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1);
}

TreeNode* buildCore(const vector<int>& pre, const vector<int>& in, int pre_s, int pre_e,
					int in_s, int in_e) {
	if (pre_s > pre_e)
		return NULL;
	// get the root
	TreeNode* root = new TreeNode();
	root->val = pre[pre_s];
	root->left = NULL;
	root->right = NULL;
	// find the index in in_order
	int index = in_s;
	while (index <= in_e) {
		if (in[index] == pre[pre_s])
			break;
		++index;
	}
	// valid check
	if (index > in_e)
		throw exception("Invalid input");
	// recursively build
	root->left = buildCore(pre, in, pre_s+1, pre_s + index - in_s,
							in_s, index-1);
	root->right = buildCore(pre, in, pre_s+index-in_s+1, pre_e,
							index+1, in_e);
	return root;
}