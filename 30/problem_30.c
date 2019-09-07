#include <stdio.h>
#include <math.h>

// checks if
//   n[0]**5 + n[1]**5 ... n[j]**5 
//      equals number 
//   n[0:j] joined together
//
// returns sum of powers if is valid sum, else returns 0
double isSumOfPower(double n[], int length, int power) {
	double nJoinedTogether = 0;
	double sumOfPowers = 0;
	// start at end	
	for (int i = 0; i < length; i++) {
		nJoinedTogether += pow(10, length - 1 - i) * n[i];
		sumOfPowers += pow(n[i],power);
	}
	if (nJoinedTogether != sumOfPowers || sumOfPowers == 1.0) {
		return 0;
	}
	return sumOfPowers;
}

int main() {
	// constants
	int length = 6;
	int power = 5;
	double sum = 0;
	// run tests
	for (int a = 0; a < 10; ++a) {
		for (int b = 0; b < 10; ++b) {
			for (int c = 0; c < 10; ++c) {
				for (int d = 0; d < 10; ++d) {
					for (int e = 0; e < 10; ++e) {
						for (int f = 0; f < 10; ++f) {
								double n[] = {a,b,c,d,e,f};
								double t = isSumOfPower(n, length, power);
								if (t) {
									printf("%lf\n", t);
									sum += t;
								}
							

						}
					}
				}
			}
		}
	}

	printf("total sum: %lf\n", sum);

	return 0;
}
