template <typename T>
class Queue{
public:
	void append(T t) {
		s1.push(t);
	}
	T deleteHead() {
		if (s1.empty() && s2.empty())
			throw exception("empty queue");
		if (s2.empty()) {
			while (!s1.empty()) {
				T tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
		T tmp = s2.top();
		s2.pop();
		return tmp;
	}
private:
	stack<T> s1;
	stack<T> s2;
};


template <typename T>
class Stack{
public:
	void push(T t) {
		q.push(t);
	}
	T pop() {
		if (q.empty())
			throw exception("empty stack");
		int count = q.size() - 1;
		for (int i = 0; i < count; ++i) {
			T tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		T tmp = q.front();
		q.pop();
		return tmp;
	}
private:
	queue<T> q;
};