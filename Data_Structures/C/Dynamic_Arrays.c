#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Dynamic_Arrays.h"

dynamic_array * DA_Create(int size) {
	//Allocate the struct and data.
	dynamic_array * array = malloc(sizeof(dynamic_array));
	//Use calloc to guarantee cleared data.
	array->data = calloc(size, sizeof(int));
	array->length = size;
	return array;
}

void DA_Destroy(dynamic_array * array) {
	//Free data before freeing the struct.
	free(array->data);
	free(array);
}

void DA_Shrink(dynamic_array * array) {
	//Half the length.
	array->length /= 2;
	//Reallocate the new length.
	array->data = realloc(array->data, array->length * sizeof(int));
}

void DA_Set(dynamic_array * array, int value, int index) {
	//Track if it needs to be resized.
	bool reallocate = false;
	int initial_size = array->length;
	//If the needed index is outside the length, resize.
	while (index >= array->length) {
		array->length *= 2;
		reallocate = true;
	}
	//Reallocate the array.
	if (reallocate) {
		//Use calloc to guarantee clear data.
		int * temp = calloc(array->length, sizeof(int));
		//Copy the current data into the new data.
		memcpy(temp, array->data, initial_size * sizeof(int));
		//Free the old data.
		free(array->data);
		//Save the new data.
		array->data = temp;
	}
	//Set the value at the index.
	*(array->data + index) = value;
}

int DA_Get(dynamic_array * array, int index) {
	return *(array->data + index);
}

void DA_Print(dynamic_array * array) {
	printf("%d", *(array->data));
	for (int i = 1; i < array->length; i++) {
		printf(" %d", *(array->data + i));
	}
	printf("\n");
}

int main() {
	dynamic_array * array = DA_Create(4);
	printf("Options:\n");
	printf("Shrink\n");
	printf("Set <value> <index>\n");
	printf("Get <index>\n");
	printf("Print\n");
	printf("Exit\n");
	char command[10];
	int value;
	int index;
	while (1) {
		printf(">");
		memset(command, 0, 10);
		scanf("%s", command);
		if (!strcmp(command, "Shrink")) {
			getchar();
			DA_Shrink(array);
		} else if (!strcmp(command, "Set")) {
			scanf(" %d %d", &value, &index);
			getchar();
			DA_Set(array, value, index);
		} else if (!strcmp(command, "Get")) {
			scanf(" %d", &index);
			getchar();
			printf("%d\n", DA_Get(array, index));
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
