#include <stdio.h>
#include <math.h>

int bruteForce(int n);
char isPrime(unsigned int number);


/**
 * calculates nth prime number
 * @param {int} n the number to count up to
 * @return {int} the nth prime number
 **/
int bruteForce(int n) {
	int count = 0;
	for (int i = 1 ; count < n ; i+=2 ) {
		if (isPrime(i)) {
			count++;
			if (count == n) return i;
		}
	}
}

/**
 * @param {unsigned int} number
 * @return {char} is prime
 **/
char isPrime(unsigned int number) {
    if (number <= 3 && number > 1) 
        return 1;            // as 2 and 3 are prime
    else if (number%2==0 || number%3==0) 
        return 0;     // check if number is divisible by 2 or 3
    else {
        unsigned int i;
        for (i=5; i*i<=number; i+=6) {
            if (number % i == 0 || number%(i + 2) == 0) 
                return 0;
        }
        return 1; 
    }
}

char bruteForce_test() {
	printf("6th prime number is 13: %d (",bruteForce(6));
	if (bruteForce(6) == 13) printf("PASS) \n");
	else printf("FAIL) expected %d \n",13);
}

int main() {
	bruteForce_test();

	printf("%d \n",bruteForce(10001));

	return 0;
}
