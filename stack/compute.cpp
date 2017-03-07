#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
string convertPost(string& str) {
    if (str.empty())
        return "";
    stack<char> s;
    stringstream ss;
    int index = 0;
    while (index < str.size()) {
    	int index2 = index;
    	while (index2 < str.size() && str[index2] >= '0' && str[index2] <= '9')
    		++index2;
    	// judege if it is a num
    	if (index2 != index) {
    		string tmp = str.substr(index, index2-index);
    		ss << tmp << " ";
    		index = index2;
    		continue;
    	}
    	// else it just a simble
    	char ch = str[index];
    	++index;
    	if (ch == '(')
    		s.push(ch);
    	else if (ch == ')') {
    		while (!s.empty() && s.top() != '(') {
    			ss << s.top() << " ";
    			s.pop();
    		}
    		if (!s.empty())
    			s.pop();
    	}
    	else if (ch == '+' || ch == '-') {
    		while (!s.empty() && s.top() != '(') {
    			ss << s.top() << " ";
    			s.pop();
    		}
    		s.push(ch);
    	}
    	else if (ch == '*' || ch == '/') {
    		while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
    			ss << s.top() << " ";
    			s.pop();
    		}
    		s.push(ch);
    	}
    }
    while (!s.empty()) {
    	ss << s.top() << " ";
    	s.pop();
    }
    return ss.str();
}
bool isnumber(const string& str) {
	string::const_iterator it = str.begin();
	while (it != str.end() && isdigit(*it))
		++it;
	return (it == str.end());
}
int compute(string& str) {
	stringstream ss(str);
	stack<int> s;
	string tmp;
	while (ss >> tmp) {
		if (isnumber(tmp))
			s.push(stoi(tmp));
		else {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			if (tmp == "+")
				s.push(b+a);
			else if (tmp == "-")
				s.push(b-a);
			else if (tmp == "*")
				s.push(b * a);
			else if (tmp == "/")
				s.push(b / a);
		}
	}
	return s.top();
}

int main() {
	string in;
	cin >> in;
	string result = convertPost(in);
	cout << result << endl;
	int re = compute(result);
	cout << re << endl;
	return 0;
}