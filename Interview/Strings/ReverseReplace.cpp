/*
Write a function called reverseReplace that takes three arguments. 
The first will be a string of many words, the second will be a 
single word that we are going to search for, and the third and 
final will be the string we want to replace the second word with. 

Example output:

reverseReplace("I like cats", "cats", "dogs") -> "dogs like I"
reverseReplace("I like cats", "mice", "dogs") -> "cats like I"

You should test it against the examples above as well as a larger test suite.
*/

#include <iostream>
#include <string.h>

using namespace std;

void reverseReplace(char *str, char *find, char *replace);
int main()
{
	char str[] = "I like cats";	
	reverseReplace(str, "mice", "dogs");
	//reverseReplace("I like cats", "cats", "dogs");
	return 0;
}
void reverseReplace(char *str, char *find, char *replace)
{
	int i, len = strlen(str), findlen = strlen(find);
	int j,k, len1, l, m;
	char temp;

	for(i=0, j=i;i<len;i++)
	{
		while(str[i] != ' ' && str[i] != '\0')
			i++;

		k = i-1;

		//replace the word
		len1 = k-j+1;
		if(len1 == findlen)
		{
			if(strncmp((str+j), find, findlen)==0)
			{
				l = j; m=0;
				while(m<findlen)
					str[l++] = replace[m++];
			}
		}

		//reverse the word
		while(j<k)
		{
			temp = str[j];
			str[j] = str[k];
			str[k] = temp;
			j++; k--;
		}
		j = i+1;
	}

	j = len-1;
	for(i=0;i<j;i++, j--)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}
	cout<<"Reversed String: "<<str<<endl;
}
