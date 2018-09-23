#include <stdio.h>


/**
 * helper to print out all elements of array
 **/
void _printArray(int array[], int length) {
	printf("[");
	for(int i = 0; i < length; i++) {
		printf("%d", array[i]);
		if (i != length - 1)
			printf(", ");
	}
	printf("]\n");
}

/**
 * gets next sequence in permutation
 * @param {int[]} current sequence
 * @param {int} length of array
 * @return {void} pass by reference
 **/
void getNext(int curr[], int length) {
	_printArray(curr, length);
}

int main() {

	int length = 3;
	int permuation[length] = {0,1,2};

	getNext(permuation, length);

	return 0;
}
