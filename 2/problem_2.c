#include <stdio.h>
#include <math.h>

// implements root of problem
unsigned long modulusFib(unsigned long modulus, unsigned long max);
unsigned long _modulusFibHelper(unsigned long modulus, unsigned long max, unsigned long nMinusOne, unsigned long nMinusTwo, unsigned long answer, unsigned long agg);

/**
 *
 * @param {int} the modulus accepted (i.e. 2 === even)
 * @param {int} the max sum (i.e 10 means stops at first number before 10 (8))
 **/
unsigned long modulusFib(unsigned long modulus, unsigned long max) {
	// start recursion at 0
	return _modulusFibHelper(modulus, max, 2, 1, 2, 3);
}

// recusive helper for above function
unsigned long _modulusFibHelper(unsigned long modulus, unsigned long max, unsigned long nMinusOne, unsigned long nMinusTwo, unsigned long answer, unsigned long agg) {
	// stopping condition
	if (agg  - nMinusOne >= max) return answer;
	unsigned long curr = nMinusOne + nMinusTwo;
	agg += curr;

	// if acceptable modulus, add to answer
	if (curr % modulus == 0) answer += curr;
	return _modulusFibHelper(modulus, max, curr, nMinusOne, answer, agg);

}

int main() {
	printf("%lu \n",modulusFib(2, 4000000));
	return 0;
}
