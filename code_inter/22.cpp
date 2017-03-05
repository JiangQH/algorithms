bool isStackOrder(const vector<int>& num1, const vector<int>& num2) {
	if (num1.size() != num2.size())
		return false;
	stack<int> s;
	int push_index = 0;
	int pop_index = 0;
	while (pop_index < num2.size()) {
		while (s.empty() || s.top() != num2[pop_index]) {
			if (push_index == num1.size())
				break;
			s.push(push_index++);
		}
		// judge equal
		if (s.top() != num2[pop_index])
			break;
		s.pop();
		++pop_index;
	}
	return (s.empty() && pop_index == num2.size());
}