#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	//int m[5][5]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int m[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	printf("%d\n",m[2][2]);
	int i,j;
	int r[5][5];
	int n=3;
	for (i= 0; i < n; ++i)
	{
		for (j= 0; j < n; ++j)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n\n");
	}
	for (i= 0; i < n; ++i)
	{
		for (j= 0; j < n; ++j)
		{
			r[i][j]=m[n-j-1][i];
		}
	}
	 for (  i = 0; i < n; i++ ) {
        for (  j = 0; j < n; j++ ) {
           // r[j][i]=m[i][j];
        }
    }
	for (i= 0; i < n; ++i)
	{
		for (j= 0; j < n; ++j)
		{
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}

return 0;
}