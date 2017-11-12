#include <stdio.h>

/**
 * converts an int to the number of letters needed to spell it
 * @param {int} less than 100 (not tested)
 * @return {int} number of letter
 **/
int numberToLetters(int n) {
	int sum = 0;
	if (n > 9 && n < 100) {
		// tens digit
		if (n == 10) return 3;// ten
		if (n == 11) return 6;// eleven
		if (n == 12) return 6;// twelve
		if (n == 13) return 8;// thirteen
		if (n == 14) return 8;// fourteen
		if (n == 15) return 7;// fifteen
		if (n == 16) return 7;// sixteen
		if (n == 17) return 9;// seventeen
		if (n == 18) return 8;// eighteen
		if (n == 19) return 8;// nineteen

		int tensPlace = (n - (n % 10)) / 10;

		if (tensPlace == 2) sum += 6;// twenty
		if (tensPlace == 3) sum += 6;// thirty
		if (tensPlace == 4) sum += 5;// forty
		if (tensPlace == 5) sum += 5;// fifty
		if (tensPlace == 6) sum += 5;// sixty
		if (tensPlace == 7) sum += 7;// seventy
		if (tensPlace == 8) sum += 6;// eighty
		if (tensPlace == 9) sum += 6;// ninety

		// ones digit
		sum += numberToLetters(n - (n - (n % 10)));

		return sum;
	}
	if (n == 0) return 0; // zero at end of number does not add anything	
	if (n == 1) return 3; // one
	if (n == 2) return 3; // two
	if (n == 3) return 5; // three
	if (n == 4) return 4; // four
	if (n == 5) return 4; // five
	if (n == 6) return 3; // six
	if (n == 7) return 5; // seven
	if (n == 8) return 5; // eight
	if (n == 9) return 4; // nine
}

char testNumerToLetters() {
	int result = numberToLetters(5);	
	int expected = 4;

	// five = 4 letters
	printf("%s%i ---- %s\n","numberToLetters(5) is ",expected, result == expected ? "PASS" : "FAIL");

	// forty-two = 8 letters
	result = numberToLetters(42);
	expected = 8;
	printf("%s%i ---- %s\n","numberToLetters(42) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(20);
	expected = 6; // twenty
	printf("%s%i ---- %s\n","numberToLetters(20) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(21);
	expected = 9; // twenty-one
	printf("%s%i ---- %s\n","numberToLetters(21) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(22);
	expected = 9; // twenty-two
	printf("%s%i ---- %s\n","numberToLetters(22) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(37);
	expected = 11; // thirty-seven
	printf("%s%i ---- %s\n","numberToLetters(37) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(99);
	expected = 10; // ninety-nine
	printf("%s%i ---- %s\n","numberToLetters(99) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(91);
	expected = 9; // ninety-one
	printf("%s%i ---- %s\n","numberToLetters(91) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(89);
	expected = 10; // eighty-nine
	printf("%s%i ---- %s\n","numberToLetters(89) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(46);
	expected = 8; // forty-six
	printf("%s%i ---- %s\n","numberToLetters(46) is ",expected, result == expected ? "PASS" : "FAIL");

	result = numberToLetters(72);
	expected = 10; // seventy-two
	printf("%s%i ---- %s\n","numberToLetters(72) is ",expected, result == expected ? "PASS" : "FAIL");
}

int main() {
	// run tests
	// testNumerToLetters();

	int sum = 0;

	// get length of 1-99
	int oneToNinetyNineSum = 0;
	for (int i = 1; i < 100; i++) {
		oneToNinetyNineSum += numberToLetters(i);
	}
	sum += oneToNinetyNineSum;

	// add in hundred's place
	int hundred = 7; // hundred is seven char long
	int and = 3;
	for (int i = 1 ; i < 10 ; i ++) {
		// i.e. 'one hundred'
		sum += numberToLetters(i) + hundred;
		// then there is 'one hundred and' 99 times
		sum += 99 * (numberToLetters(i) + hundred + and);
		// add in all of tens and ones places
		sum += oneToNinetyNineSum;
	}

	// add 'one thousand'
	sum += 11;

	printf("%i\n", sum);


	return 0;
}
