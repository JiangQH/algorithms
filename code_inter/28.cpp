void printString(string& str) {
	if (str.empty())
		return;
	printString(str, 0);
}

void printString(string& str, int index) {
	if (index == str.size()) {
		cout << str;
		return;
	}
	else {
		for (int i = index; i < str.size(); ++i) {
			// swap them
			char tmp = str[index];
			str[index] = str[i];
			str[i] = tmp;
			printString(str, index+1);
			str[i] = str[index];
			str[index] = tmp;
		}
	}
}