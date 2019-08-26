#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char c='A';
	char d[]="0x1e";
	printf("%d\n", isalnum(c));
	printf("%d Alphabets \n", isalpha('A') );
	printf("%d\n",islower(c) );
	printf("%d\n",isupper(c) );
	printf("%d\n",isdigit(c) );
	printf("%d Isxdigit() \n",isxdigit(d[0]));
	printf("%d\n", isgraph(c));
	printf("%d\n",isspace(' '));
	printf("%d\n",isblank(NULL));
    printf("%d\n",isprint(c));
	printf("Puntuation %d\n", ispunct('+'));
	printf("%c\n",toupper(c));
    printf("%c\n",tolower(c));
	return 0;
}
