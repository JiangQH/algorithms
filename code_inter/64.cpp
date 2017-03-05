template <typename T>
class DynamicArray{
public:
	void insert(T num) {
		// judge odd or even
		if ((small_max_heap_.size() + big_min_heap_.size()) & 0x1 == 1) {
			big_min_heap_.push_back(num);
			make_heap(big_min_heap_.begin(), big_min_heap_.end(), less<T>());
			num = big_min_heap_[0];
			pop_heap(big_min_heap_.begin(), big_min_heap_.end(), less<T>());
			big_min_heap_.pop_back();

			small_max_heap_.push_back(num);
			make_heap(small_max_heap_.begin(), small_max_heap_.end(), greater<T>());
		}
		else {
			small_max_heap_.push_back(num);
			make_heap(small_max_heap_.begin(), small_max_heap_.end(), greater<T>());
			num = small_max_heap_[0];
			pop_heap(small_max_heap_.begin(), small_max_heap_.end(), greater<T>());
			small_max_heap_.pop_back();

			big_min_heap_.push_back(num);
			make_heap(big_min_heap_.begin(), big_min_heap_.end(), less<T>());
		}
	}

	T getMedian() {
		if (small_max_heap_.empty() && big_min_heap_.empty())
			throw exception("empty")
		if ((small_max_heap_.size() + big_min_heap_.size()) & 0x1 == 1)
			return small_max_heap_[0];
		else
			return (small_max_heap_[0] + big_min_heap_[0]) / 2;
	}
private:
	vector<int> small_max_heap_;
	vector<int> big_min_heap_;

};