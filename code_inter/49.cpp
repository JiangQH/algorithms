bool valid_input = false;
int str2Num(string num) {
	if (num.empty()) {
		valid_input = false;
		return -1;
	}
	// first sign check
	string coreNum = num;
	bool negative = false;
	if (num[0] == '-') {
		negative = true;
		coreNum = coreNum.substr(1);
	}
	if (num[0] == '+')
		coreNum = coreNum.substr(1);
	// the core convert
	int result = str2NumCore(coreNum, negative);
	return result;
}

int str2NumCore(string coreNum, bool negative) {
	long long result = 0;
	for (int i = 0; i < coreNum.size(); ++i) {
		if (coreNum[i] >= '0' && coreNum[i] <= '9'){
			int flag = negative ? -1 : 1;
			result = result * 10 + flag * (coreNum[i] - '0');
			if (result > 0x7FFFFFFF || result < (signed int)0x80000000) {
				valid_input = false;
				return -1;
			}
		}
		else {
			valid_input = false;
			return -1;
		}
	}
	valid_input = true;
	return int(result);
}