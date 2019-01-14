//This struct is used to store meta data about the array.
typedef struct {
	int * data;
	int length;
	int used;
	int min;
} dynamic_array;

//Initialize the dynamic array
dynamic_array * DA_Create(int size);

//Free the dynamic array
void DA_Destroy(dynamic_array * array);

//Get a value at an index
int DA_Get(dynamic_array * array, int index);

//Find the index of a value
int DA_Find(dynamic_array * array, int value);

//Insert a value at an index
void DA_Insert(dynamic_array * array, int value, int index);

//Delete an element
void DA_Delete(dynamic_array * array, int index);

//Print the dynamic array
void DA_Print(dynamic_array * array);
