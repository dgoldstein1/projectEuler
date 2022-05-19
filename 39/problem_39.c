#include <stdio.h>
#include <math.h>

/**
 * If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

 {20,48,52}, {24,45,51}, {30,40,50}

 For which value of p ≤ 1000, is the number of solutions maximised?
**/

char isSolution(int a,b,c, p) {
	if (a+b+c != p) {
		return 0;
	}
	return (pow(a,2) + pow(b, 2)) == pow(c,2);
}

// finds number of solutions where a^2 + b^2 = c^2 where a + b + c = p
int numPerimSolutions(int p) {
	int numSolutions = 0;
	for (int a = 1; a < p; ++a) {
		for (int b = 1; b < p; ++b) {
			for (int c = 1; c < p; ++c) {
				if (isSolution(a,b,c, p)) {
					numSolutions++;
				}
			}
		}
	}
	return numSolutions;
}

int main() {
	int max = 0;
	int maxN = 0;
	for (int i = 500; i <= 1000; ++i) {
		printf("checking: %d\n",i);
		int solNumber = numPerimSolutions(i);
		if (solNumber > max) {
			printf("new max: %d\n", i);
			maxN = i;
			max = solNumber;
		}
	}
	printf("n: %d max = %d\n",  maxN, max);
	return 0;
}
