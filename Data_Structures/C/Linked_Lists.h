//This is the node definition. Make sure to declare the node as a struct node *.
//For this example, we'll make a doubly linked circular list with a head node.
typedef struct node {
  struct node * next;
  struct node * prev;
  int value;
} node;

//Initialize the linked list.
node * LL_Create(void);

//Free all nodes, including list head.
void LL_Destroy(node * list);

//Insert a value at an index.
void LL_Insert(node * list, int value, int index);

//Delete an element.
void LL_Delete(node * list, int index);

//Find a value
int LL_Find(node * list, int value);

//Get the length of the list.
int LL_Length(node * list);

//Print the list.
void LL_Print(node * list);
