//We will use this enum to determine if the heap is a min heap or max heap.
typedef enum {
  min,
  max,
} heap_type;

//This is a heap node.
typedef struct {
  int value;
  int priority;
} heap_node;

//This is the heap definition.
typedef struct {
  heap_node * data;
  int length;
  int used;
  int min;
  heap_type type;
} heap;

//Initialize the heap with a type.
heap * H_Create(heap_type type, int size);

//Free the heap.
void H_Destroy(heap * heap);

//Insert a value into the heap with a priority.
void H_Insert(heap * heap, int value, int priority);

//Extract a value from the heap.
int H_Extract(heap * heap);

//Peek at the top of the heap.
int H_Peek(heap * heap);
