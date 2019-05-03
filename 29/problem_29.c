#import <math.h>
#define arraySize (100000)
double *double_array;
int count = 0;

/**
 * @param {double} n
 * loops through current numbers and adds it if not already there
 **/
void addToArrayAndIncrementCount(double n) {
	for (int i = 0; i < count; i++) {
		if (double_array[i] == n) return;
	}
	double_array[count] = n;
	count++;
}

int main() {
	double_array = malloc(arraySize * sizeof(double));
	for (int a = 2; a <= 100; a++) {
		for(int b = 2; b <= 100; b++) {
			addToArrayAndIncrementCount(pow(a,b));
			addToArrayAndIncrementCount(pow(b,a));
		}
	}
	printf("count of unique numbers: %d\n", count);

	return 0;
}
