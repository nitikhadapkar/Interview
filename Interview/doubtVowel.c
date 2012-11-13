/*
Write a function to reverse the vowels of a string
(vowels are a, e, i, o, u) in place.
In other words, the same memory that the
string is stored in is used as both input and output:

Examples:
"deadbeef" becomes "deedbaef"
"Mad cow disease" becomes "Med caw desiosa"
*/

#include <stdio.h>
#include <string.h>

void reverse(char *str);
int is_vowel(char c);

int main()
{
	char *str = "deadbeef";

	printf("Original String: %s\n", str);	
	reverse(str);
	printf("Reversed Vowel String: %s\n", str);	

	return 0;
}

void reverse(char *str)
{
	int i, j, length = strlen(str);
	char temp;

	i = 0;
	j = length-1;

	while(i<j)
	{
		while(!is_vowel(str[i]))
		{
			printf("I%c\n",str[i]);
			i++;
		}

		while(!is_vowel(str[j]))
		{
			printf("J%c\n",str[j]);
			j--;
		}

		if(i<j)
		{
			printf("I%c\n",str[i]);
			printf("J%c\n",str[j]);
			temp = str[i];
			printf("temp%c\n",temp);
			str[i] = str[j];
			printf("I%c\n",str[j]);
			str[j] = temp;
			printf("I%c\n",str[i]);
			printf("J%c\n",str[j]);
			i++; j--;
			printf("I%d\n",i);
			printf("J%d\n",j);
		}
	}
}

int is_vowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 1;

	else
		return 0;
}
