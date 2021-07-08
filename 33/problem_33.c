#include <stdio.h>

char isCuriousFraction(int a, int b, int c, int d) {
	// check less than one
	float frac = (float)((a * 10) + b) / (float)((c * 10) + d);
	if (frac > 1.0) {
		return 0;
	}
	if (b != c || b == d) {
		return 0;
	}
	return frac == (float)(a) / d;
}

int main() {
	for (int a = 1; a <= 9; ++a) {
		for (int b = 1; b <= 9; ++b) {
			for (int c = 1; c <= 9; ++c) {
				for (int d = 1; d <= 9; ++d) {
					if (isCuriousFraction(a,b,c,d)) {
						printf("%d%d / %d%d\n",a,b,c,d);
					}
				}	
			}	
		}		
	}
}
