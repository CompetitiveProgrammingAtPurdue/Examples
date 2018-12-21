#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	//Strings can be declared easily.
	char * a = "Perfectly balanced, ";
	char * b = "as all things should be.\n";

	//Working with strings requires memory allocation.
	//Strlen returns the length of a string, stopping at a null character '\0'.
	char * c = malloc((strlen(a) + strlen(b)) * sizeof(char));

	//Strcpy copies a string into another.
	c = strcpy(c, a);

	//Strcat appends one string to the end of another.
	c = strcat(c, b);
	printf("%s", c);

	//Strdup does the mallocing for you.
	char * d = strdup(c);

	//Strcmp compares two springs. It returns 0 if they are the same, and negative or positive integers if they are different.
	//Negative means the first string is lower than the second, and vice versa.
	if (!strcmp(c, d)) {
		printf("Ah, victory.\n");
	}
	
	//Make sure to free your allocated pointers.
	free(c);

	//Strchr finds the first instance of a character in a string.
	char * e = "Not to worry, we're still flying half a ship.\n";
	char * f = strchr(e, 's');
	printf("%s", f);
	
	//Strstr finds substrings for you.
	char * g = "These are not the droids you are looking for.\n";
	char * h = strstr(g, "droids");
	printf("%s", h);
	//You can use this to find the index of the substring.
	printf("%d\n", (int)h - (int)g);

	//Strtok can split a string into tokens delimited by a set of characters.
	//This modifies the original string, so pass in a pointer, not a constant.
	char * i = strdup("C,C++,Java,Python");
	char * j = strtok(i, ",");
	//Strtok returns NULL when it runs out of tokens.
	while (j != NULL) {
		printf("%s\n", j);
		//Use the same string again by calling strtok with NULL.
		j = strtok(NULL, ",");
	}
}
