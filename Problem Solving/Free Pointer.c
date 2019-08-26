#include <stdio.h>
#include <malloc.h>
int main()
{ 
	int *a=(int *)malloc(sizeof(int));
	printf("%d\n",a);
	*(a+0)=11;
	int *b={1,2,3,4};
	//free(a);
	printf("%d\n",a);
	return 0;
}