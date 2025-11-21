#include <stdio.h>
#include <math.h>


int main() {
	int digitIndex = 0, product = 1, nextDigitTenPower = 1;
	for (int i = 1; i < 1000000; i++) {
        // we need to break down numbers 10 +
	    int numDigits = (int)floor(log10(i)) + 1;
	    int j = i;
	    while (numDigits > 0) {
	        // get 1 from 153, floor(153 / 10^2) = 1
	        int firstDigit = (int)floor(j / pow(10, numDigits-1));
	        digitIndex++;
            if (digitIndex == nextDigitTenPower) {
                product *= firstDigit;
                nextDigitTenPower *= 10;
                printf("firstDigit: %i, product %i\n",firstDigit, product);
                if (digitIndex == 1000000) {
                    return 0;
                }
            }
	        j = j % (int) pow(10, numDigits-1);
	        numDigits--;
	    }
	}
	return 1;
}
