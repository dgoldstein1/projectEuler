#include <stdio.h>	
#include <math.h>

/**
 * util which gets indicies from double
 * for example trailingDec(0.3535343,0,5) = 35353
 **/
double trailingDec(double n, int start, int stop) {
	// get rid of leading digits
	n = n - floor(n);
	// bit shift to get starting index
	n =  n * pow(10, start);
	// remove leading digits
	n = n - floor(n);
	// bit shift to get end index
	n = n * pow(10, stop - start + 1);
	// remove trailing digits
	return floor(n);
}

/**
 * finds length of repeating decimal
 * where repition is the same sequence ocurring ten times
 * @param {double} demimal
 * @return {double} length of repition
 **/
double lengthOfRepeatingDecimal(double n, int i1) {
	int currentSequence = -1;
	// try and see if each 0:i makes a reocurring loop 
	for (int i = 0; i < 1000; i++) {
		// check to see if there are multiple reocurring sequences
		double seq1 = trailingDec(n, 0, i);
		double seq2 = trailingDec(n, i+1, (i * 2) + 1);
		double seq3 = trailingDec(n, (i * 2) + 2, (i * 3) + 2);
		
		// printf("%d, %f, %f == %f\n", i1, n, seq1, seq2);
		//repition has been found
		if (seq1 == seq2 && seq2 == seq3) {
			// return length of number
			return ceil(log10(seq1));
		}
	}
	return -1;

}

int main() {
	double max = -1;
	double d = -1;
	int value = 0;
	for (int i = 1; i < 1000; i++) {
		d = lengthOfRepeatingDecimal(1.0/i, i);
		if (d > max) {
			max = d;
			value = i;
		}		
	}
	printf("%d: %f\n",value, max);
	// this is not the right solution.. correct taken from https://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/
	return 0;
}
