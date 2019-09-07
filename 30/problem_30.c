#include <stdio.h>
#include <math.h>

// checks if
//   n[0]**5 + n[1]**5 ... n[j]**5 
//      equals number 
//   n[0:j] joined together
char isSumOfFithPower(double n[], int length) {
	double nJoinedTogether = 0;
	// start at end	
	for (int i = length - 1; i >= 0; i--) {
		nJoinedTogether += pow(10, i) * n[i];
	}
	printf("%lf\n", nJoinedTogether);


	return 1;
}

int main() {
	double test[] = {1,2,3,4,5,6};
	int length = 6;
	printf("%d\n", isSumOfFithPower(test, length));
	return 0;
}
