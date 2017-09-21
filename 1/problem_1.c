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
	printf("%f \n",consecutiveSum(3, 999) + consecutiveSum(5, 999) - consecutiveSum(15, 999));
	return 0;
}
