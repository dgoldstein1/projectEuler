#include <stdio.h>
#include <math.h>

/**
 * finds the number of factors
 * @param {int} n
 * @return {int} # factors, not including 1 && n
 **/
int sumOfDivisors(int n) { 
    // Final result of summation of divisors 
    int result = 0; 
    // find all divisors which divides 'num' 
    for (int i=2; i<=sqrt(n); i++) { 
        // if 'i' is divisor of 'n' 
        if (n%i==0) { 
            // if both divisors are same then add 
            // it only once else add both 
            if (i==(n/i)) 
                result += i; 
            else
                result += (i + n/i); 
        } 
    } 
  
    // Add 1 to the result as 1 is also a divisor 
    return (result + 1); 
} 

/**
 * determines if the sum of a number's factors are more than that
 * number. (e.g. 12 is abundant since 1+2+3+4+6 = 16 > 12)
 * @param {int} n
 * @return {int} is abundant
 **/
int isAbundant(int n) {
	return sumOfDivisors(n) > n;
} 


/**
 * can a number be written as the sum of two abundant numbers?
 *
 * e.g. can 938 be written as sume of two numbers (see isAbundant
 * number for more details)
 * 
 * @param {int} number
 * @return {int} is sum of two abundant numbers
 **/
int isSumOfTwoAbundantNumbers(int n) {
	int mid = 1 + ((n - 1) / 2);
	// first check if mid is abundant equals n
	if (mid * 2 == n && isAbundant(mid))
		return 1;
	// loop through partitions of two
	// start one int at n, and the other at 12
	// they do not need to pass each other because
	// then we're just doing the first part again
	for (int i = 12; i < mid; i++) {
		int j = n - i;
		// if i is abundant and j is abundant, n is 
		// sum of two abundant number
		if (isAbundant(i) && isAbundant(j)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	// for number 0 => 28123, can be written as sum
	// of two abundant numbers?
	int sum = 0;
	for (int i= 24; i < 28123; i++) {
		if (!isSumOfTwoAbundantNumbers(i)) 
			sum += i;
	}	
	printf("%i\n", sum);

	// answer is 4179871
	return 0;
}
