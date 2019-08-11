#include <stdio.h>

char isSumOfFithPower(int n[], int length) {
	double powerSum = 0;
	double digitSum = 0;
	for (int i = 0; i < length; i++) {
		digitSum += (double) n[i];

	}
	return powerSum == digitSum;
}

int main() {
	printf("%b\n", isSumOfFithPower());
	return 0;
}
