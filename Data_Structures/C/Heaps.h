//We will use this enum to determine if the heap is a min heap or max heap.
typedef enum {
	MIN,
	MAX,
} heap_type;

//This is the heap definition. Make sure to declare the heap as a struct heap *.
typedef struct {
	int priority;
	int value;
	heap_type type;
} heap;

//Initialize the heap.
heap * H_Create(void);

//Free all nodes of the heap, including the root.
void H_Destory(heap * heap);

//Insert a value with a priority.
void H_Insert(heap * heap, int value, int priority);

//Extract the element with the highest priority.
int H_Extract(heap * heap);

//Peek at the element with the highest priority.
int H_Peek(heap * heap);
