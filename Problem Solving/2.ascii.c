// 123456 , 1+2+3  = 4+5+6
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char input[100];
    scanf("%s",&input);
    int m=strlen(input)/2;
    if((strlen(input)%2)>0)
    {
    	printf("0");
    	return 0;
    }

	int before=0,after=0;
	int i=0;
	for (i = 0; i < m; ++i)
	{
		before+=input[i]-48;
	}
	for (i = m; i < strlen(input); ++i)
	{
		after+=input[i]-48;
	}


	printf("before %d after %d\n",before,after);
	return 0;
}