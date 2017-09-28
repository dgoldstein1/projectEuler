#include <stdio.h>
#include <math.h>

short isPalindrome(long n);
short _isPalindromeTest();


//////////////////
// core methods //
//////////////////

/**
 * @param {long} n
 * @return {short} true if palindrom (i.e. '101')
 **/
short isPalindrome(long n) {
	// convert n to array of char
	char temp[256];
	sprintf(temp, "%lu", n);

	// get number of digits
	int len = 0;
	while (n > 0) {
		n  = n / 10;
		len ++;
	}

	// compare front vs end values
	len--;
	int i = 0;
	while (i < floor(len / 2) + 2) {
		if (temp[i] != temp[len]) return 0;
		len--;
		i++;
	}
	return 1;
}

/**
 * finds the largest palindrome made up of two numbers of digits # of digits
 * (i.e. largest palindrom of digits = 2 is 9009)
 * @param {int} digits
 * @return {long} number
 **/
long largestPalindromeProduct(int digits) {

	long possibleAnswers[10000];
	int currIndex = 0;

	long i = pow(10, digits);
	long lim = pow(10, digits - 1);
	while (i > lim) {
		for(long j = pow(10, digits) - 1 ; j > i ; j --) {
			if(isPalindrome(i * j)) {
				printf("adding %lu \n", i * j);
				possibleAnswers[currIndex] = i * j;
				currIndex++;
			};
		}
		i--;
	}
	
	// find max among largest palindromes
	long max = 0;
	for (int i = 0 ; i < currIndex ; i ++) {
		if (possibleAnswers[i] > max) max = possibleAnswers[i];
	}
	return max;
}

///////////
// tests //
///////////

short _isPalindromeTest() {
	printf("101 is palindrome : %hi \n", isPalindrome(101));
	printf("123 is palindrome : %hi \n", isPalindrome(123));
	printf("9009 is palindrome : %hi \n", isPalindrome(9009));
	printf("956459 is palindrome : %hi \n", isPalindrome(956459));
	return 1;
}

int main() {
	// _isPalindromeTest();
	printf("%lu \n",largestPalindromeProduct(3));
	return 0;
}
