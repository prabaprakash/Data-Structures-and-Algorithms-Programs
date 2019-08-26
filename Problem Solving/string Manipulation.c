#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	// Concat char to String
	 char a[10]="";
	 while(strlen(a)<5)
	 {
	 int l=strlen(a);
	 a[l]='5';
	 }
	 printf("%s\n",a);


    strcpy(a,"dd");
	printf("%s\n",a);

    strncpy(a,"hello world",5);
	printf("%s\n",a);


    strcat(a," world");
	printf("%s\n",a);


    strncat(a," Earth",5);
	printf("%s\n",a);
	return 0;
}
