#include <stdio.h>
#include <gmp.h>

/**
 * calulates the number of digits in 
 **/
int numberOfDigits(char n[]) {
	char oneChar;
	return gmp_snprintf (&oneChar, 1, "%Zd", n);
}

int main() {
	for (int i = 100; i < 10000; i++) {
		// initialize gmp values
		mpz_t n;
		mpz_init(n);
		// set sum of digits to 0
		mpz_fib_ui(n, i);
		if (numberOfDigits(n) == 1000) {
			printf("%i\n", i);
			break;
		}
		
	}
	return 0;
}
