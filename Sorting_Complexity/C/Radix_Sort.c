#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Radix_Sort.h"

void Radix_Sort(int * array, int size) {
  //Allocate buckets.
  int * set = malloc(size * sizeof(int));
  int * unset = malloc(size * sizeof(int));
  int i, j, s, u;
  //Go through all bits from least to most significant.
  for (i = 0; i < 8 * sizeof(int); i++) {
    int mask = 1 << i;
    s = 0;
    u = 0;
    //Store all elements in the buckets.
    for (j = 0; j < size; j++) {
      if (mask & array[j]) {
        set[s] = array[j];
        s++;
      } else {
        unset[u] = array[j];
        u++;
      }
    }
    //Reset j for storing back into the list.
    j = 0;
    //If this is not the sign bit, put unset back first.
    if (i != 8 * sizeof(int) - 1) {
      while (j < u) {
        array[j] = unset[j];
        j++;
      }
      while (j - u < s) {
        array[j] = set[j - u];
        j++;
      }
    //If this is the sign bit, put negative numbers back first.
    } else {
      while (j < s) {
        array[j] = set[j];
        j++;
      }
      while (j - s < u) {
        array[j] = unset[j - s];
        j++;
      }
    }
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
	Radix_Sort(array, argc - 1);
	printf("> %d", *(array));
	for (int i = 1; i < argc - 1; i++) {
		printf(" %d", *(array + i));
	}
	printf("\n");
}
