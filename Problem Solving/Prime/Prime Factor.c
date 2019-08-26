#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int factor=2;
	while(n%factor==0)
	{
		printf("%d\n",factor);
		n=n/factor;
	}
	factor=3;
	//printf("%d\n",factor);
	int sq;
	sq=sqrt(n);
	while(factor<=sq)
	{
		
      while(n%factor==0)
      {
      	printf("%d\n",factor);
      	n=n/factor;
      	sq=sqrt(n);
      }
      factor=factor+2;
	}
	 if (n > 2)
        printf ("%d ", n);
	//printf("%d\n",factor);
	return 0;
}