#include <stdio.h>
#include <math.h>

/**
 * @param {double} (i.e. compute sum of n + (n + step))
 * @param {double} n
 * @return {double} sum of all consecutive integers within range
 */
double consecutiveSum(double step, double n) {
	n = floor(n / step);
	return step * floor((pow(n,2) + n) / 2);
} 


/**
 * @param {long} number
 * @return {char} is prime
 **/
char isPrime(long number) {
    if (number <= 3 && number > 1) 
        return 1;            // as 2 and 3 are prime
    else if (number%2==0 || number%3==0) 
        return 0;     // check if number is divisible by 2 or 3
    else {
        long i;
        for (i=5; i*i<=number; i+=6) {
            if (number % i == 0 || number%(i + 2) == 0) 
                return 0;
        }
        return 1; 
    }
}
/**
 * finds the number of factors
 * @param {long} n
 * @return {int} # factors, not including 1 && n
 **/
int numberOfFactors(long n) {
	if (n == 1) return 1;
	if (isPrime(n)) return 2;

	int numberOfFactors = 0;
	for(long i=1; i < (int) sqrt(n); ++i) {
        if (n%i == 0) {
            numberOfFactors += 2;
        }
    }

    if (sqrt(n) == (int) sqrt(n)) {
    	numberOfFactors++;
    }

	return numberOfFactors;
}

int numberOfFactors_test() {
	int result = numberOfFactors(3);	
	int expected = 2;
	printf("%s%i ---- %s\n","numberOfFactors(3) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberOfFactors(28);
	expected = 6;
	printf("%s%i ---- %s\n","numberOfFactors(28) is ",expected, result == expected ? "PASS" : "FAIL");

	return 0;
}

int main() {


	numberOfFactors_test();

	// find triangle number with # factors >= 500
	int i = 0;
	while(1) {
		long n = consecutiveSum(1,i);
		if (numberOfFactors(n) >= 500) {
			printf("%li \n", n);
			return 0;
		}
		i++;
	}
	return 0;
}
