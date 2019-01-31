#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int peak(int * range, int length) {
  int min = 0;
  int max = length - 1;
  int mid = (min + max) / 2;
  while (min < max) {
    if (mid - 1 < 0 || mid + 1 > length - 1) {
      return -1;
    }
    if (range[mid - 1] < range[mid] && range[mid] > range[mid + 1]) {
      return range[mid];
    } else if (range[mid - 1] < range[mid] && range[mid] < range[mid + 1]) {
      min = mid + 1;
    } else if (range[mid - 1] > range[mid] && range[mid] > range[mid + 1]) {
      max = mid - 1;
    } else {
      printf("The array is not continuously increasing or decreasing!\n");
      return -1;
    }
    mid = (min + max) / 2;
  }
  return -1;
}

int main(int argc, char ** argv) {
  if (argc == 1) {
    printf("No array input!\n");
    return 1;
  }
  int length = argc - 1;
  int * range = malloc(length * sizeof(int));
  int i;
  for (i = 0; i < length; i++) {
    range[i] = atoi(argv[i + 1]);
  }
  int p = peak(range, length);
  if (p == -1) {
    printf("No peak!\n");
  } else {
    printf("Peak: %d\n", p);
  }
}
