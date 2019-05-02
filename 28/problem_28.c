#include <stdio.h>

int main() {
	int nRows = 1001;
	int sum = 1;
	int n = 1;
	int currDifference = 2;
	while (n < nRows * nRows) {
		for (int i = 0; i < 4; i ++) {
			n += currDifference;
			sum += n;
		}
		currDifference+=2;
	}
	printf("sum is = %d\n", sum);
	return 0;
}
