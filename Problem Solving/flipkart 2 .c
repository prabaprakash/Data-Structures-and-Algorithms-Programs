#include<stdio.h>
unsigned long long one=0,zero=0;
unsigned long long array[200],o[200],z[200];
void reco(int n)
{
	if(array[n])
	{
		zero+=z[n];
		one+=o[n];
		return;
	}
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
    array[n]=1;
    o[n]=one;
    z[n]=zero;


}
int main()
{

	int n;
		scanf("%d",&n);
reco(n);
printf("%llu %llu\n",one,zero);
//it easy
printf("%llu %llu\n",o[n],z[n]);

return 0; 
}
