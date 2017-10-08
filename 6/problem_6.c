#include <stdio.h>
#include <math.h>

/**
 * @param {double} (i.e. compute sum of n + (n + step))
 * @param {double} max
 * @return {double} sum of all consecutive integers within range
 */
double consecutiveSum(double step, double max) {
	max = floor(max / step);
	return step * floor((pow(max,2) + max) / 2);
}
int main() {
	// find sum of first 100 int
	long consec100 = consecutiveSum(1, 100);

	// raise to second power to find square of sums (1 : 100)
	consec100 = pow(consec100, 2);

	long sumOfSqures = 1;
	for(long i = 2; i <= 100 ; i++) {
		sumOfSqures += pow(i, 2);
	}

	printf("%lu \n", consec100 - sumOfSqures);
	return 0;
}
