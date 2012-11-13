#include <stdio.h>
#include <stdlib.h>


char* do_something(char *in)
{
	char *copy;
	int i;

	copy = malloc(strlen(in)+1);

	for(i=0;i<strlen(in);i++)
		copy[i] = in[i];
	copy[i] = '\0';

	return copy;
}

int main()
{
	printf(do_something("Hello World\n"));
	return 0;
}
