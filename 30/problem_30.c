#include <stdio.h>
#include <math.h>

// checks if
//   n[0]**5 + n[1]**5 ... n[j]**5 
//      equals number 
//   n[0:j] joined together
char isSumOfPower(double n[], int length, int power) {
	double nJoinedTogether = 0;
	double sumOfPowers = 0;
	// start at end	
	for (int i = 0; i < length; i++) {
		nJoinedTogether += pow(10, length - 1 - i) * n[i];
		sumOfPowers += pow(n[i],power);
	}
	printf("sumOfPowers: %lf \n", sumOfPowers);
	printf("nJoinedTogether: %lf \n", nJoinedTogether);
	return nJoinedTogether == sumOfPowers;
}

int main() {
	double test[] = {1,6,3,4};
	int length = 4;
	printf("%d\n", isSumOfPower(test, length, 4));
	return 0;
}
