// Division by zero is not detected, while it definitely
// will happen. However, if the initial value of "i" we replace
// with "3," the error will be detected.

int foo() {
	int sum = 0;
	for (int i = 4; i >= 0; i--) {
		sum += 42 / i;
	}
	return sum;
}
