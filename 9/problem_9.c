#include <stdio.h>
#include <math.h>

int main() {
	for (int a = 999; a  > 0 ; a --) {
		for (int b = 999 ; b > 0; b--) {
			for(int c = 999 ; c > 0 ; c --) {
				if (a + b + c == 1000 && (pow(a,2) + pow(b,2) == pow(c,2))) {
					printf("%i \n", a * b * c);
					return 0;
				}
			}
		}
	}
	return 0;
}
