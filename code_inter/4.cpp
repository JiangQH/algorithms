void replaceSpace(string& str) {
	if (str.empty())
		return;
	int space_count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ')
			++space_count;
	}
	// append space
	string result = str + string(2*space_count, ' ');
	int real_walker = result.size() - 1;
	int ori_walker = str.size() - 1;
	while (real_walker > ori_walker) {
		if (result[ori_walker] == ' ') {
			result[real_walker--] = '0';
			result[real_walker--] = '2';
			result[real_walker--] = '%';
			--ori_walker;
		}
		else {
			result[real_walker--] = result[ori_walker--];
		}
	} 
	str = result;
}