#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge_Sort(int * array, int low, int high) {
	//An array of size 2 is the base case.
	if (high - low == 1) {
		int a = *(array + low);
		int b = *(array + high);
		if (a <= b) {
			return;
		} else {
			*(array + low) = b;
			*(array + high) = a;
			return;
		}
	//If it is smaller than 2, it must already be sorted.
	} else if (high - low < 1) {
		return;
	//If it is larger than 2, it must be merged.
	} else {
		//Sort the first half.
		int middle = (low + high) / 2;
		Merge_Sort(array, low, middle);
		//Sort the second half, consider odd lengths.
		Merge_Sort(array, middle + 1, high);
		//Allocate an auxiliary array.
		int * temp = malloc(high - low + 1 * sizeof(int));
		int left = low;
		int right = middle + 1;
		int i = 0;
		//Go through elements of the left and right halves of the array.
		while (left <= middle && right <= high) {
			//Insert the lower element in the temp array.
			if (*(array + left) <= *(array + right)) {
				*(temp + i) = *(array + left);
				left++;
			} else {
				*(temp + i) = *(array + right);
				right++;
			}
			i++;
		}
		//Insert the remaining elements in the temp array.
		while (left <= middle) {
			*(temp + i) = *(array + left);
			left++;
			i++;
		}
		while (right <= high) {
			*(temp + i) = *(array + right);
			right++;
			i++;
		}
		i = 0;
		//Copy the temp array to the current range.
		while (low <= high) {
			*(array + low) = *(temp + i);
			low++;
			i++;
		}
		free(temp);
		return;
	}
}

int main(int argc, char ** argv) {
	if (argc == 1) {
		printf("No array input!\n");
		return 1;
	}
	int * array = malloc((argc - 1) * sizeof(int));
	for (int i = 0; i < argc - 1; i++) {
		*(array + i) = atoi(argv[i + 1]);
	}
	Merge_Sort(array, 0, argc - 2);
	printf("< %d", *(array));
	for (int i = 1; i < argc - 1; i++) {
		printf(" %d", *(array + i));
	}
	printf("\n");
}
