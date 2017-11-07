#include <stdio.h>

/**
 * recursive helper for factorial
 **/
double factorialHelper(int n, double acc){
	if (n == 1) return acc;
	return factorialHelper(n-1, n * acc);
}

/**
 * finds factorial of n
 **/
double factorial(int n){
	return factorialHelper(n, 1);
}


/**
 * (2n)!/n!×n!  
 * @param {int} size of grid (number of Rs and Ds)
 * @return {long} number of combinations
 **/
double binomialCoeff(int n) {
	return factorial( 2 * n)  / (factorial(n) * factorial(n));
}

int main() {
	printf("%lf\n",binomialCoeff(20));
	return 0;
}
