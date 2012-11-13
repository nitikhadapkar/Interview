/*
 Find the beginning of the first word that is a palindrom 
char *find_first_palindrome(char *input)
{
          Your code here 
}

int main()
{
       char *input="Hello mom and dad, how is it going?";
       char *mom=find_first_palindrom(input);
       printf("%s\n", mom);
       return 0;
}

Should print "mom and dad, how is it going?"
*/

#include <stdio.h>

char *find_first_palindrome(char *input);

int main()
{
//      char *input="Hello mom and dad, how is it going?";

	char input[100], *mom;
	printf("\nEnter a string: ");
	gets(input);
        mom=find_first_palindrome(input);
	if(mom)
	        printf("%s\n", mom);
	else
		printf("No Palindrome in the sentence.\n");
        return 0;
}

char *find_first_palindrome(char *input)
{
	int first, last, ftemp = 0, ltemp = 0;

	first = 0;
	last = first;

	while(input[first]!='\0')
	{

		//if the string starts with lots of spaces and special characters.
		while(!((input[first]>'a' && input[first]<'z') || (input[first]>'A' && input[first]<'Z')) && input[first]!='\0')
			first++;

		if(input[first] == '\0')
			break;

		ftemp = first;
		last = first;

		//tokenize the word
		while(input[last] != ' ' && input[last]!='\0')
		{
			last++;
		}
		last--;
		ltemp = last;

		if(first == last)
		{
			first = ltemp+2; //as ltemp+1 is space
			continue;
		}

		//if not a character, might be some punctuation. Could be more than one.
		while(!((input[last]>'a' && input[last]<'z') || (input[last]>'A' && input[last]<'Z')))
			last--;

		//check if the word is not palindrome
		while(tolower(input[first]) == tolower(input[last]) && first<=last)
		{
			first++; last--;
		}

		if(last<first) //palindrome
		{
			return &input[ftemp];
		}
		else
		{
			first = ltemp;
		}
	}

	return NULL;
}
