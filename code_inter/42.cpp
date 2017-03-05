void reverse(string& num) {
	int begin = 0;
	int end = num.size()-1;
	while (begin < end) {
		char tmp = num[begin];
		num[begin] = num[end];
		num[end] = tmp;
		++begin;
		--end;
	}
}

string reverseSentence(string& str) {
	if (str.empty())
		return;
	// reverse the whole sentence
	reverse(str);
	// reverse every word
	stringstream ss(str);
	string result;
	string tmp;
	while (ss >> tmp) {
		reverse(tmp);
		result += tmp;
	}
	return result;
}