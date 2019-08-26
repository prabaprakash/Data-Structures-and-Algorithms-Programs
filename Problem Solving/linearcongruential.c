#include<stdio.h>
int main()
{
	int a=5,b=3,m=11;
	for (int i = 1; i <=10; ++i)
	{
		int v=((i*a)+b)%m;
		printf("%d is %d\n",i+1,v);
	}
	return 0;
}