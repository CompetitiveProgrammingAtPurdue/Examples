#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heaps.h"

heap * H_Create(heap_type type, int value, int priority) {
	heap * heap = malloc(sizeof(heap));
	heap->left = NULL;
	heap->right = NULL;
	heap->priority = priority;
	heap->value = value;
	heap->type = type;
	return heap;
}
