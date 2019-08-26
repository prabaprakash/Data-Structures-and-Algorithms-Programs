#include <stdio.h>
unsigned long long arr[100000];
unsigned long long factorial[100000];
unsigned long long temp;
unsigned long long factor(unsigned long long n)
{
	if(n==0)
	{
		return 1;
	}
   temp=n*factor(n-1);
   return temp;
}
int main()
{
	printf("%llu\n",factor(60));
}