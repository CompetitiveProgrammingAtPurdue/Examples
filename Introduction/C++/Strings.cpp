#include <iostream>
#include <string>

using namespace std;

int main() {
	
	//The C++ string constructor has many options.
	string a("There's always a bigger fish\n");

	//Copy one string to another by passing into the constructor.
	string b(a);
	cout << b;

	//Get a substring by passing in the start index and the length.
	//Pass string::npos as the length to go until the end.
	string c(a, 15, string::npos);
	cout << c;

	//Get the first n characters of a C string
	string d("Not to worry, we're still flying half a ship.\n", 25);
	cout << d << '\n';

	//Use the + operator to concatenate strings. += also works.
	string e("Perfectly balanced, ");
	string f("as all things should be.\n");
	string g = e + f;
	cout << g;

	//string::compare compares the string it is called on and a string passed in.
	//It returns 0 if they are the same, and negative or positive integers if they are different.
	//Negative means the first string is lower than the second, and vice versa.
	if (!a.compare(b)) {
		cout << "Ah, victory.\n";
	}

	//string::find finds a substring in the string it is called on.
	//You can pass it a starting index, otherwise it starts from the beginning.
	string h("These are not the droids you are looking for.\n");
	int index = h.find("droids");
	cout << index << '\n';

	//You can use everything from C in C++, so check out the C examples for strtok!

}
