#include <stdio.h>
#include <malloc.h>
void getitem(char *c[10],int n)
{
	//a=(char*)malloc(4*sizeof(char));
	int i;
  for (i = 0; i <4; ++i)
	{
	   // c[i] = calloc(10, sizeof(char));
	   c[i] =malloc(sizeof(char));
		scanf("%s",c[i]);
	}
	for (i = 0; i <4; ++i)
	{
		printf("%s\n",c[i]);
	}


}

int main()
{

	//char **c=(char *)malloc(10*sizeof(char));
	char *c[10];
	 int i,j;

	getitem(c,4);
	for (i = 0; i<4; ++i)
	   //printf("%c\n",c[i]);


	return 0;
}
