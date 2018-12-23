#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_Lists.h"

node * LL_Create(void) {
	//Allocate the head node
	node * list = malloc(sizeof(node));
	//Set its next and previous pointers to itself, making a circular list.
	list->next = list;
	list->prev = list;
	list->value = 0;
}

void LL_Destroy(node * list) {
	node * current;
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

void LL_Insert(node * list, int value, int index) {
	if (index < 0) {
		return;
	}
	//Start at node 0.
	node * current = list->next;
	//Go to the index.
	for (int i = 0; i < index; i++) {
		if (current == list) {
			return;
		}
		current = current->next;
	}
	//Allocate the new node.
	node * new = malloc(sizeof(node));
	new->value = value;
	//Weave the new node into the list before the current node.
	new->next = current;
	new->prev = current->prev;
	current->prev->next = new;
	current->prev = new;
}

int LL_Remove(node * list, int index) {
	if (index < 0) {
		return 0;
	}
	//Start at node 0.
	node * current = list->next;
	//Go to the index.
	for (int i = 0; i < index; i++) {
		if (current == list) {
			return 0;
		}
		current = current->next;
	}
	//Save the value.
	int value = current->value;
	//Weave the current node out of the list.
	current->prev->next = current->next;
	current->next->prev = current->prev;
	//Free the current node.
	free(current);
	return value;
}

int LL_Length(node * list) {
	//Start at node 0.
	node * current = list->next;
	//Go to the end and count.
	int length = 0;
	while (current != list) {
		current = current->next;
		length++;
	}
	return length;
}

void LL_Print(node * list) {
	//Start at node 0.
	node * current = list->next;
	//Go to the end and print.
	while (current != list) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int main() {
	node * list = LL_Create();
	printf("Options:\n");
	printf("Insert <value> <index>\n");
	printf("Remove <index>\n");
	printf("Length\n");
	printf("Print\n");
	printf("Exit\n");
	char command[10];
	int value;
	int index;
	while (1) {
		printf(">");
		scanf("%s", command);
		if (!strcmp(command, "Insert")) {
			scanf(" %d %d", &value, &index);
			getchar();
			LL_Insert(list, value, index);
		} else if (!strcmp(command, "Remove")) {
			scanf(" %d", &index);
			getchar();
			printf("%d\n", LL_Remove(list, index));
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
