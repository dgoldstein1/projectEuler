#include <stdio.h>

/**
 * helper for collatz sequence, performance actual sequence
 * the collatz sequence is an iterative sequence on integers :
 *
 * if even :  n → n/2
 * if odd  : n → 3n + 1
 * @param {long} n
 * @return {long} n after sequence
 **/
long collatzSequence(long n) {
	if (n % 2 == 0) return n / 2;
	return (n * 3) + 1;
}

/**
 * @param {long} n to perform sequence on
 * @return {long} number of terms in sequence (i.e.steps taken to reach 1, inclusive)
 **/
long collatzSequenceLength(long n) {
	long count = 1;
	while (n != 1) {
		n = collatzSequence(n);
		count ++;
	}
	return count;
}

int main() {

	long currNumber = 0;
	long currMax = 0;
	long curr = 0;

	for (int i = 1000000; i > 500000; --i) {
		curr = collatzSequenceLength(i);
		if (curr > currMax) {
			currNumber = i;
			currMax = curr;
		}
	}

	printf("%li\n", currNumber);
	
	return 0;
}
