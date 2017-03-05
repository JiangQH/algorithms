class AddClass{
public:
	AddClass() {
		++cur_;
		sum_ += cur_;
	}
	static void reset() {
		cur_ = 0;
		sum_ = 0;
	}
	static int getSum() {
		return sum_;
	}
private:
	static int cur_;
	static int sum_;
};

int getSum(int n) {
	AddClass::reset();
	vector<AddClass> tmp(n);
	return AddClass::getSum();
}