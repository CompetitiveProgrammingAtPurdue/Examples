#include <stdio.h>

int main() {

	//Scanf starts with a format string, then pointers to the variables to store input in.
	//It can be dangerous to use scanf for strings of unknown length, overflowing buffers.
	printf("Type a character, decimal, float, and string. I will add commas.\n");
	char c;
	int d;
	float f;
	char s[20];
	//Pass in pointers to the variables.
	scanf("%c %d %f %s", &c, &d, &f, s);
	//Output formatting works almost the same way. There are many format options.
	printf("%c, %d, %f, %s\n", c, d, f, s);
	//Be careful, because scanf will leave your newline in the stdin stream.
	//To fix this, add a whitespace to the beginning of your next format string.
	//In this case, I will use a getc() to remove it.
	getc(stdin);

	//Getc is also available. It is much safer than scanf.
	//A file stream must be specified, so you can use this on files as well.
	//It is a safe option, because you know what you're going to get.
	printf("Type a single character.\n");
	c = getc(stdin);
	printf("You typed %c.\n", c);
	//Getc also leaves a newline. Getchar is like getc but automatically uses stdin.
	getchar();

	//Fgets is a bit stronger than getc. Pass in the length and string to receive into.
	//Fgets adds a trailing '\0' to the string, so add 1 to your size.
	//This works on files as well.
	//This option is fairly safe, because you decide how much to read.
	printf("Now type a string 4 characters long.\n");
	fgets(s, 5, stdin);
	printf("You cant say %s! That's a bad word!\n", s);
}
