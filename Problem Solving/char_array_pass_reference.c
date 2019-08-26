#include <stdio.h>

void getitem(char *c,int n)
{
	//a=(char*)malloc(4*sizeof(char));
	int i;
  for (i = 0; i <4; ++i)
	{
		scanf("%c",&c[i]);
	}


}

int main()
{

	//char **c=(char *)malloc(10*sizeof(char));
	char c[10];
	 int i,j;

	getitem(c,4);
	for (i = 0; i<4; ++i)
	   printf("%c\n",c[i]);


	return 0;
}
