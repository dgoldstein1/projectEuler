#include <stdio.h>
#include <math.h>


/**
 * @param {long} number
 * @return {char} is prime
 **/
char isPrime(int number) {
    if (number <= 3 && number > 1) 
        return 1;            // as 2 and 3 are prime
    else if (number%2==0 || number%3==0) 
        return 0;     // check if number is divisible by 2 or 3
    else {
        int i;
        for (i=5; i*i<=number; i+=6) {
            if (number % i == 0 || number%(i + 2) == 0) 
                return 0;
        }
        return 1; 
    }
}

/**
 * finds the number of factors
 * @param {int} n
 * @return {int} # factors, not including 1 && n
 **/
int sumOfDivisors(int n) {
	if (n == 1) return 1;
	if (isPrime(n)) return 1;

	int sumOfFactors = 1;
	for(int i=1; i < (int) sqrt(n); ++i) {
        if (n%i == 0 && i != n && i != 1) {
        	sumOfFactors += i;
        	sumOfFactors += n / i;
        }
    }

    // is perfect square
    if (sqrt(n) == (int) sqrt(n)) {
    	sumOfFactors += sqrt(n);
    }

	return sumOfFactors;
}
/**
 * proper divisors e.g. 
 * 220 = 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110 = 284;
 * 284 = 1, 2, 4, 71 and 142; so d(284) = 220.
 **/
int hasAmicablePair(int a) {
    int b = sumOfDivisors(a);
    return(a != b && sumOfDivisors(b) == a);
}



int main() {
	int amicablePairSum = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		if (hasAmicablePair(i))
			amicablePairSum += i; 
	}
	printf("%i\n", amicablePairSum);
	return 0;
}
