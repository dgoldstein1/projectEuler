#include <stdio.h>
#include <gmp.h>

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


int main() {
    // initialize gmp values
    mpz_t n;
    mpz_t sum;
    mpz_init(n);
    mpz_init(sum);

    // set sum of digits to 0
    mpz_init_set_str(sum, "0", 10);
    mpz_init_set_str(n, "0", 10);

    // set value to factorial of one hundred (100!)
    const char stringFactorial[159] = "93326215443944175354307254139643190247129328132295862491935879110669343325734178368282822618707234467717279847537548956702435362278960753539491860335688679424";

    // // loop through chars adding each digits to sum
    for (int i = 0 ; i < 159 ; i ++) {
        // cast char as string
        char * charAsString[1] = { stringFactorial[i] };
        // set n to the current digit
        mpz_init_set_str(n, charAsString, 10);
        // add to sum
        mpz_add(sum, sum, n);
    }

    mpz_out_str(stdout,10,sum);
    printf("\n");

	return 0;
}
