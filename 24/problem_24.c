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
 * https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
 * @param {int[]} current sequence
 * @param {int} length of array
 * @return {void} pass by reference
 **/
void getNext(int curr[], int length) {
	_printArray(curr, length);
	// first find 'pivot'
	int pivot = -1;
	int pivotValue = -1;
	for (int i = length - 1; i > 0; i--) {
		if (curr[i] > curr[i - 1]) {
			pivot = i - 1;
			pivotValue = curr[pivot];
			break;
		}
	}

	// if there is no pivot, this means that 
	// the permutation is still in it's initial form
	if(pivot == -1) {
		int lastEl = curr[length - 1];
		// switch last two digits
		curr[length - 1] = curr[length - 2];
		curr[length - 2] = lastEl;
		return;
	}

	// find the smallest element in the
	// suffix that is greater than the pivot
	int minElSuffxLTPivot = -1;
	int minElSuffxLTPivotValue = -1;
	// loop through starting at back until you get to pivot
	for (int i = length - 1; i > pivot; i --) {
		if (curr[i] > pivotValue) {
			// switch them out
			minElSuffxLTPivot = i;
			minElSuffxLTPivotValue = curr[i];
			break;
		}
	}
	
	printf("pivot %d\n", pivotValue);
	printf("minElSuffxLTPivot : %d\n", minElSuffxLTPivotValue);


	// if could not find a min value, likely error
	// but could also be last permutation
	if (minElSuffxLTPivot == -1) {
		printf("Could not find minElSuffxLTPivot\n");
		return;
	}


}

int main() {

	// int length = 3;
	// int permuation[length] = {0,1,2};
	int length = 7;
	int permuation[length] = {0, 1, 2, 5, 3, 3, 0};

	getNext(permuation, length);


	return 0;
}
