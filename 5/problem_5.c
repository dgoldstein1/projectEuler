#include <stdio.h>

long gcd(long a, long b);
long lcm(long a, long b);

/**
 * finds gcd of two numbers (i.e. gcd of 10 and 25 is 5)
 * note -- a should be larger than b
 * @param {long} a
 * @param {long} b
 * @return {long} gcd
 **/
long gcd(long a, long b) {
	if (b > a) return -1; // 'a' should always be larger than 'b'
	// stopping condition, remainer is 0
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

/**
 * finds lowest common multiple of two numbers
 * @param {long} a note -- 'a' must be bigger than 'b'
 * @param {long} b
 * @return {long}
 **/
long lcm(long a, long b) {
	if (b > a) return -1;
	return (a * b) / gcd(a,b);
}

char testGCD() {
	printf("GCD of 210 and 45 is 15 is: %d (",gcd(210, 45));
	if (gcd(210, 45) == 15) printf("PASS) \n");
	else printf("FAIL) expected %d \n",15);

	printf("GCD of 210 and 60 is 30 is: %d (",gcd(210, 60));
	if (gcd(210, 60) == 30) printf("PASS) \n");
	else printf("FAIL) expected %d \n",30);

	printf("GCD of 210 and 153 is 30 is: %d (",gcd(210, 153));
	if (gcd(210, 153) == 3) printf("PASS) \n");
	else printf("FAIL) expected %d \n",3);

	printf("GCD of 25326 and 2351 is 30 is: %d (",gcd(25326, 2351));
	if (gcd(25326, 2351) == 1) printf("PASS) \n");
	else printf("FAIL) expected %d \n",1);	
	
	printf("GCD of 998526 and 2562 is 30 is: %d (",gcd(998526, 2562));
	if (gcd(998526, 2562) == 6) printf("PASS) \n");
	else printf("FAIL) expected %d \n",6);

	printf("GCD of 24 and 60 is 30 is: %d (",gcd(60, 24));
	if (gcd(60, 24) == 12) printf("PASS) \n");
	else printf("FAIL) expected %d \n",12);

	return 1;
}

int main() {
	int lessThan20[9] = {20,19,18,17,16,14,13,12,11};

	long currLcm = lessThan20[0];
	for (int i = 0; i < 9 - 1; i++) {
		currLcm = lcm(currLcm, lessThan20[i+1]);
	}

	printf("lcm of 1-20 is %lu \n",currLcm);

	return 0; 
}
