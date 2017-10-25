#include <stdio.h>

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

int main() {
	long acc = 1;
	for (int i = 1 ; i < 2000000 ; i += 2) {
		if (isPrime(i)) acc+=i;
	}

	printf("%li \n", acc);

	return 0;
}
