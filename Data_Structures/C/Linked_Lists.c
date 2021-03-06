#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_Lists.h"

list_node * LL_Create(void) {
  //Allocate the head list_node
  list_node * list = malloc(sizeof(list_node));
  //Set its next and previous pointers to itself, making a circular list.
  list->next = list;
  list->prev = list;
  list->value = 0;
}

void LL_Destroy(list_node * list) {
  list_node * current;
  //While there are nodes in the list
  while (list->next != list) {
    //Save a pointer to the first node.
    current = list->next;
    //Point the list->next pointer to the second node.
    list->next = list->next->next;
    //Free the first node.
    free(current);
  }
  free(list);
}

void LL_Insert(list_node * list, int value, int index) {
  if (index < 0) {
    return;
  }
  //Start at node 0.
  list_node * current = list->next;
  //Go to the index.
  for (int i = 0; i < index; i++) {
    if (current == list) {
      return;
    }
    current = current->next;
  }
  //Allocate the new node.
  list_node * new = malloc(sizeof(list_node));
  new->value = value;
  //Weave the new node into the list before the current node.
  new->next = current;
  new->prev = current->prev;
  current->prev->next = new;
  current->prev = new;
}

void LL_Delete(list_node * list, int index) {
  if (index < 0) {
    return;
  }
  //Start at node 0.
  list_node * current = list->next;
  //Go to the index.
  for (int i = 0; i < index; i++) {
    if (current == list) {
      return;
    }
    current = current->next;
  }
  //Weave the current node out of the list.
  current->prev->next = current->next;
  current->next->prev = current->prev;
  //Free the current node.
  free(current);
}

int LL_Find(list_node * list, int value) {
  int i = 0;
  list_node * current = list->next;
  while (current != list) {
    if (current->value == value) {
      return i;
    }
    current = current->next;
  }
  return -1;
}

int LL_Length(list_node * list) {
  //Start at node 0.
  list_node * current = list->next;
  //Go to the end and count.
  int length = 0;
  while (current != list) {
    current = current->next;
    length++;
  }
  return length;
}

void LL_Print(list_node * list) {
  //Start at node 0.
  list_node * current = list->next;
  //Go to the end and print.
  while (current != list) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

int main() {
  list_node * list = LL_Create();
  printf("Options:\n");
  printf("Insert <value> <index>\n");
  printf("Delete <index>\n");
  printf("Length\n");
  printf("Print\n");
  printf("Exit\n");
  char command[10];
  int value;
  int index;
  while (1) {
    printf(">");
    memset(command, 0, 10);
    scanf("%s", command);
    if (!strcmp(command, "Insert")) {
      scanf(" %d %d", &value, &index);
      getchar();
      LL_Insert(list, value, index);
    } else if (!strcmp(command, "Delete")) {
      scanf(" %d", &index);
      getchar();
      LL_Delete(list, index);
    } else if (!strcmp(command, "Length")) {
      getchar();
      printf("%d\n", LL_Length(list));
    } else if (!strcmp(command, "Print")) {
      getchar();
      LL_Print(list);
    } else if (!strcmp(command, "Exit")) {
      getchar();
      LL_Destroy(list);
      return 0;
    } else {
      printf("Not a valid command!\n");
      while (getchar() != '\n') {
        continue;
      }
    }
  }
}
