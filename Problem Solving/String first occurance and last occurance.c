#include <stdio.h>

#include <string.h>

int main()
{
/*
	strlen returns the length of a given string
    strcmp compares two strings
    strncmp compares a certain amount of characters of two strings
    strchr finds the first occurrence of a character
    strrchr finds the last occurrence of a character
    strspn returns the length of the maximum initial segment that consists
of only the characters found in another byte string
    strcspn First matched character is at
   strpbrk finds the first location of any character in one string, in another string
   strstr finds the first occurrence of a substring of characters
   strtok finds the next token in a byte string
*/

   int b;
   printf("%d\n",b);

   char a[100]="qwertyuiopasdfghjkelzxcvbnm";
   printf("%d\n",strlen(a));

   printf("%d\n",strcmp(a,"z"));

   printf("%d\n",strncmp(a,"qwerty",7));

   printf("first occurrence of a character --> %d\n",strlen(a)-strlen(strchr(a,'e')));

   printf("last occurrence of a character --> %d\n",strlen(a)-strlen(strrchr(a,'e')));


   return 0;
   }