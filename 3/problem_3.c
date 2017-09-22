#include <stdio.h>
#include <math.h>

int primeFactors(long n);


/**
 * finds largest prime factor for a number n
 * uses 2-3-5 factorization wheel
 * taken from [stack overflow](https://stackoverflow.com/questions/12756335/fast-prime-factorization-algorithm)
 * @param {long} number to factorize
 * @return {int} largest prime factor
 **/
int primeFactors(long n) {
    long ws[] = {1,2,2,4,2,4,2,4,6,2,6};
    long f = 2; int w = 0;

    while (f * f <= n) {
        if (n % f == 0) {
            printf("%ld\n", f);
            n /= f;
        } else {
            f += ws[w];
            w = (w == 10) ? 3 : (w+1);
        }
    }
    printf("%ld\n", n);
    return 0;
}


int main() {
	primeFactors(600851475143);
	return 0;
}
