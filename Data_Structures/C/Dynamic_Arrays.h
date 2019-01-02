//This struct is used to store meta data about the array.
typedef struct {
	int * data;
	int length;
} dynamic_array;

//Initialize the dynamic array
dynamic_array * DA_Create(int size);

//Free the dynamic array
void DA_Destroy(dynamic_array * array);

//Shrink the dynamic array
void DA_Shrink(dynamic_array * array);

//Set a value at an index
void DA_Set(dynamic_array * array, int value, int index);

//Get a value at an index
int DA_Get(dynamic_array * array, int index);

//Print the dynamic array
void DA_Print(dynamic_array * array);
