//This is the node definition. Make sure to declare the node as a struct node *.
//For this example, we'll make a doubly linked circular list with a head node.
typedef struct list_node {
  struct list_node * next;
  struct list_node * prev;
  int value;
} list_node;

//Initialize the linked list.
list_node * LL_Create(void);

//Free all nodes, including list head.
void LL_Destroy(list_node * list);

//Insert a value at an index.
void LL_Insert(list_node * list, int value, int index);

//Delete an element.
void LL_Delete(list_node * list, int index);

//Find a value
int LL_Find(list_node * list, int value);

//Get the length of the list.
int LL_Length(list_node * list);

//Print the list.
void LL_Print(list_node * list);
