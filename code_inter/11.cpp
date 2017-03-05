bool valid_input = false;
double power(double base, int exponent) {
	// valid check
	if (exponent < 0 && isequal(base, 0)) {
		valid_input = false;
		return 0;
	}
	bool negative = false;
	if (exponent < 0) {
		negative = true;
		exponent = -exponent;
	}
	// compute
	double result = powerCore(base, exponent);
	if (negative)
		result = 1.0 / result;
	valid_input = true;
	return result;
}

double powerCore(double base, int exp) {
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;
	double result = powerCore(base, exp >> 1);
	result = result * result;
	if (exp & 1)
		result *= base;
	return result;
}

bool isequal(double a, double b) {
	return (a-b > -0.0000001) && (a-b < 0.0000001);
}