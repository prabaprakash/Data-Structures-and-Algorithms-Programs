#include<stdio.h>

int finbonacci(int n)
{
	if(n==0)return 1;
	if(n==1)return 2;
	return finbonacci(n-1)+finbonacci(n-2);
}

int main()
{
	/* code */
    printf("%d\n",finbonacci(10));
	return 0;
}