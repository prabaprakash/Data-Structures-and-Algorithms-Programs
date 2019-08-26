#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	int n=10;
	int a[5],b[n];
	int i,j;
	for ( i = 0; i < 3; ++i)
	{
	  scanf("%d",&a[i]);
	}
	for ( i = 1; i <=n; ++i)
	{
		b[i]=i;
		for ( j = 0; j < 3; ++j)
		{
			if(i==a[j]&&i==n)
			{
             n--;
			}
          if(i==a[j])
          {
          	b[i]=n;
            n--;
          }

		}
	}
	for ( i = 1; i <=n; ++i)
	{
		printf("%d\n",b[i]);
	}
	return 0;
}