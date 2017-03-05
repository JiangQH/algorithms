class SingleClass{
public:
	static SingleClass* getInstance() {
		return new SingleClass();
	}
	static destroyInstance(SingleClass* instance) {
		delete instance;
	}
private:
	SingleClass(){};
	~SingleClass(){};
};