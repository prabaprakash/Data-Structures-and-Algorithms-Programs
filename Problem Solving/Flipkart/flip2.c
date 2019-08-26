#include<stdio.h>
unsigned long long one=0,zero=0;
void reco(int n)
{
	if(n<=0)
	{
	  zero++;
	  return;
	}
	if(n==1)
	{
	  one++;
	  return;
	}
	else
    {
	reco(n-1);
	reco(n-2);
	reco(n-3);
}
}
int main()
{
reco(30);
printf("%llu %llu",one,zero);

return 0; 
}
