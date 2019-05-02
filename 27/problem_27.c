#include <stdio.h>
#include <math.h>

/**
 * @param {int} number
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

int main() {

	int largestConsec = 0;
	int largestA = 0;
	int largestB = 0;

	for(int b = -1000; b <= 1000; b++) {
		for (int a = -1000; a <= 1000; a++) {
			if (isPrime(abs(b))) {
				int n = 0;
				char keepGoing = 1;
				while(keepGoing) {
					// check if quadratic is prime
					int quadratic =  n * n + a * n + b;
					if(isPrime(abs(quadratic))) {
						n++;
					} else {
						keepGoing = 0;
					}
				}
				if (n > largestConsec) {
					largestA = a;
					largestB = b;
					largestConsec = n;
				}
			}

		}
	}

	printf("(a=%d, b=%d) with %d consecutive primes \n",largestA, largestB, largestConsec );
	printf("a * b = %d\n",largestA * largestB );

	return 0;
}
