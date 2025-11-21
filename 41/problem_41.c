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

/**
 * @param {int} number
 * @return {char} is pandigital
 **/
char isPandigital(int number) {
    int numDigits = (int)floor(log10(number)) + 1;
    // make sure contains each digit [1-4]
    for (int i = 1; i <= numDigits; i ++) {
        // see if each digit matches (e.g. 1 == 2 / 1 / 4 / 3)
        int n = number;
        char exists = 0;
        for (int j = numDigits; j > 0; j --) {
	        int firstDigit = (int)floor(n / pow(10, j-1));
	        if (i == firstDigit) {
	            exists = 1;
	            break;
	        }
            n = n % (int) pow(10, j-1);
        }
        if (!exists) {
            return 0;
        }
    }
    return 1;

}

int main() {
    for (int i = 987654321; i > 2134; i = i - 2) {
        if (isPandigital(i) && isPrime(i)) {
            printf("%i\n", i);
            return 0;
        }
    }


	return 1;
}
