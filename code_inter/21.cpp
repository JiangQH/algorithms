template <typename T>
class MinStack{
public:
	void push(T t) {
		data_.push(t);
		if (min_.empty() || t < min_.top())
			min_.push(t);
		else
			min_.push(min_.top());
	}

	T pop() {
		T data = data_.top();
		data_.pop();
		min_.pop();
		return data;
	}

	T min() {
		if (min_.empty())
			throw exception("empty stack");
		else
			return min_.top();
	}
private:
	stack<T> data_;
	stack<T> min_;
};