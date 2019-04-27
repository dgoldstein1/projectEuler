#include <stdio.h>
#include <math.h>

/**
 * util which gets indicies from double
 * for example getDecimalInidiciesOfDouble(0.3535343,0,5) = 35353
 **/
int getDecimalInidiciesOfDouble(double n, int start, int stop) {
	// get rid of leading digits
	n = n - floor(n);
	return 1;
}

/**
 * finds length of repeating decimal
 * where repition is the same sequence ocurring ten times
 * @param {double} demimal
 * @return {int} length of repition
 **/
int lengthOfRepeatingDecimal(double n) {
	int currentSequence = -1;
	// try and see if each 0:i makes a reocurring loop 
	for (int i = 0; i < 1000; i++) {
	}

	double temp = 0.142857142857142857142857142857;
	printf("%d\n", getDecimalInidiciesOfDouble(temp, 0, 3));
	return -1;

}

int main() {
	lengthOfRepeatingDecimal(35.3);
	return 0;
}
