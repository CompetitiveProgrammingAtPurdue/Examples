#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> //Use gcc -lm to compile.
#include "Heaps.h"

heap * H_Create(heap_type type, int size) {
  //Allocate the struct
  heap * h = malloc(sizeof(heap));
  //Allocate the data
  h->data = calloc(size, sizeof(heap_node));
  h->length = size;
  h->used = 0;
  h->min = size;
  return h;
}

void H_Destroy(heap * h) {
  //Free data before freeing the struct.
  free(h->data);
  free(h);
}

//Helper function to swap nodes
void H_Swap(heap_node * a, heap_node * b) {
  heap_node temp;
  //Store b into temp.
  memcpy(&temp, b, sizeof(heap_node));
  //Store a into b.
  memcpy(b, a, sizeof(heap_node));
  //Store temp into a.
  memcpy(a, &temp, sizeof(heap_node));
}

void H_Insert(heap * h, int value, int priority) {
  //Check bounds.
  //If the data is full, resize.
  if (h->used == h->length) {
    //Double the data length.
    h->length *= 2;
    //Reallocate with the new length.
    h->data = realloc(h->data, h->length * sizeof(heap_node));
  }
  //Store the values in the next available space in the heap.
  int i = h->used;
  h->data[i].value = value;
  h->data[i].priority = priority;
  h->used++;
  //Raise up through the heap if necessary.
  if (h->type == min) {
    //If the node's priority is less than its parent's priority, swap.
    while (h->data[i].priority < h->data[(i - 1) / 2].priority) {
      H_Swap(&h->data[i], &h->data[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  } else {
    //If the node's priority is greater than its parent's priority, swap.
    while (h->data[i].priority > h->data[(i - 1) / 2].priority) {
      H_Swap(&h->data[i], &h->data[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }
}

int H_Extract(heap * h) {
  //Check bounds.
  if (h->used == 0) {
    return 0;
  }
  //Save the value with best priority.
  int top = h->data[0].value;
  //Replace the node with the last node.
  H_Swap(&h->data[0], &h->data[h->used - 1]);
  h->used--;
  //Sink the node down the heap.
  int i, left, right, swap;
  i = 0;
  if (h->type == min) {
    //Don't go out of bounds.
    while (i < h->used) {
      //Find the left and right nodes.
      left = (2 * i) + 1;
      right = (2 * i) + 2;
      swap = i;
      //If the current priority is greater than the left priority, it can swap.
      if (left < h->used
          && h->data[swap].priority > h->data[left].priority) {
        swap = left;
      }
      //If the current priority is greater than the right priority, it can swap.
      if (right < h->used
          && h->data[swap].priority > h->data[right].priority ) {
        swap = right;
      }
      //If we can swap, do it.
      if (i != swap) {
        H_Swap(&h->data[i], &h->data[swap]);
        i = swap;
      } else {
        break;
      }
    }
  } else {
    //Don't go out of bounds.
    while (i < h->used) {
      //Find the left and right nodes.
      left = (2 * i) + 1;
      right = (2 * i) + 2;
      swap = i;
      //If the current priority is less than the left priority, it can swap.
      if (left < h->used
          && h->data[swap].priority < h->data[left].priority) {
        swap = left;
      }
      //If the current priority is less than the right priority, it can swap.
      if (right < h->used
          && h->data[swap].priority < h->data[right].priority ) {
        swap = right;
      }
      //If we can swap, do it.
      if (i != swap) {
        H_Swap(&h->data[i], &h->data[swap]);
        i = swap;
      } else {
        break;
      }
    }
  }
  //If used is 1/4 of length, resize.
  if (h->used <= h->length / 4 && h->length / 2 >= h->min) {
    //Store the new length.
    h->length /= 2;
    //Realloc can be used to resize allocated pointers, but does not clear new data.
    h->data = realloc(h->data, h->length * sizeof(heap_node));
  }
  return top;
}

int H_Peek(heap * h) {
  //The best priority value is always at index 0.
  return h->data[0].value;
}

void H_Print(heap * h) {
  printf("Priority:\n");
  int j = 0;
  int k = 1;
  for (int i = 0; i < h->used; i++) {
    printf("%d", h->data[i].priority);
    if (i == j || i == h->used - 1) {
      printf("\n");
      j += (int)pow(2, k);
      k++;
    } else {
      printf(" ");
    }
  }
  printf("Value:\n");
  j = 0;
  k = 1;
  for (int i = 0; i < h->used; i++) {
    printf("%d", h->data[i].value);
    if (i == j || i == h->used - 1) {
      printf("\n");
      j += (int)pow(2, k);
      k++;
    } else {
      printf(" ");
    }
  }
}

int main() {
  heap_type t;
  char type[10];
  char command[10];
  int value, priority;
  while (1) {
    printf("Min or Max heap?\n> ");
    scanf(" %s", type);
    getchar();
    if (!strcmp(type, "Min")) {
      t = min;
      break;
    } else if (!strcmp(type, "Max")) {
      t = max;
      break;
    } else {
      printf("Valid types are Min or Max.\n");
    }
  }
  heap * h = H_Create(t, 4);
  printf("Options:\n");
  printf("Insert <value> <priority>\n");
  printf("Extract\n");
  printf("Peek\n");
  printf("Print\n");
  printf("Exit\n");
  while (1) {
    printf(">");
    memset(command, 0, 10);
    scanf("%s", command);
    if (!strcmp(command, "Insert")) {
      scanf(" %d %d", &value, &priority);
      getchar();
      H_Insert(h, value, priority);
    } else if (!strcmp(command, "Extract")) {
      getchar();
      printf("%d\n", H_Extract(h));
    } else if (!strcmp(command, "Peek")) {
      getchar();
      printf("%d\n", H_Peek(h));
    } else if (!strcmp(command, "Print")) {
      getchar();
      H_Print(h);
    } else if (!strcmp(command, "Exit")) {
      getchar();
      H_Destroy(h);
      return 0;
    } else {
      printf("Not a valid command!\n");
      while (getchar() != '\n') {
        continue;
      }
    }
  }
}
