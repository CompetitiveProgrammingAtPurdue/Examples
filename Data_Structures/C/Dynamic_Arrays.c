#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Dynamic_Arrays.h"

dynamic_array * DA_Create(int size) {
  //Allocate the struct and data.
  dynamic_array * array = malloc(sizeof(dynamic_array));
  array->data = malloc(size * sizeof(int));
  array->length = size;
  array->used = 0;
  array->min = size;
  return array;
}

void DA_Destroy(dynamic_array * array) {
  //Free data before freeing the struct.
  free(array->data);
  free(array);
}

int DA_Get(dynamic_array * array, int index) {
  return array->data[index];
}

int DA_Find(dynamic_array * array, int value) {
  int i = 0;
  for (i = 0; i < array->used; i++) {
    if (array->data[i] == value) {
      return i;
    }
  }
  return -1;
}

void DA_Insert(dynamic_array * array, int value, int index) {
  //Check bounds.
  //If index is greater than used, it is not within the current array.
  if (index > array->used || index < 0) {
    return;
  }
  //If the array is full, resize.
  if (array->used == array->length) {
    //Double the array length.
    array->length *= 2;
    //Reallocate with the new length.
    array->data = realloc(array->data, array->length * sizeof(int));
  }
  //If the index is at the end of the used data, store it.
  if (index == array->used) {
    array->data[index] = value;
  //If the index is within the used data, shift the data up.
  } else if (index < array->used) {
    //Memmove is like memcpy, but works with sources and destinations that overlap.
    memmove(array->data + index + 1, array->data + index, (array->used - index) * sizeof(int));
    array->data[index] = value;
  }
  array->used++;
}

void DA_Delete(dynamic_array * array, int index) {
  //Check bounds.
  //If the index is negative or out of bounds, quit.
  if (index < 0 || array->used == 0 || index >= array->used) {
    return;
  }
  //Shift the data down.
  memmove(array->data + index, array->data + index + 1, (array->used - index - 1) * sizeof(int));
  array->data[array->used - 1] = 0;
  array->used--;
  //If used is 1/4 of length, resize.
  if (array->used <= array->length / 4 && array->length / 2 >= array->min) {
    //Store the new length.
    array->length /= 2;
    //Realloc can be used to resize allocated pointers, but does not clear new data.
    array->data = realloc(array->data, array->length * sizeof(int));
  }
}

void DA_Print(dynamic_array * array) {
  if (array->used == 0) {
    return;
  }
  printf("%d", *(array->data));
  for (int i = 1; i < array->used; i++) {
    printf(" %d", *(array->data + i));
  }
  printf("\n");
}

int main() {
  dynamic_array * array = DA_Create(4);
  printf("Options:\n");
  printf("Get <index>\n");
  printf("Find <value>\n");
  printf("Insert <value> <index>\n");
  printf("Delete <index>\n");
  printf("Print\n");
  printf("Exit\n");
  char command[10];
  int value;
  int index;
  while (1) {
    printf(">");
    memset(command, 0, 10);
    scanf("%s", command);
    if (!strcmp(command, "Get")) {
      scanf(" %d", &index);
      getchar();
      printf("%d\n", DA_Get(array, index));
    } else if (!strcmp(command, "Find")) {
      scanf(" %d", &value);
      getchar();
      printf("%d\n", DA_Find(array, value));
    } else if (!strcmp(command, "Insert")) {
      scanf(" %d %d", &value, &index);
      getchar();
      DA_Insert(array, value, index);
    } else if (!strcmp(command, "Delete")) {
      scanf(" %d", &index);
      getchar();
      DA_Delete(array, index);
    } else if (!strcmp(command, "Print")) {
      getchar();
      DA_Print(array);
    } else if (!strcmp(command, "Exit")) {
      getchar();
      DA_Destroy(array);
      return 0;
    } else {
      printf("Not a valid command!\n");
      while (getchar() != '\n') {
        continue;
      }
    }
  }
}
