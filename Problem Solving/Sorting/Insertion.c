#include<stdio.h>

int main()
{
    int a[5]={10,8,9,7,2};
    int i,j,k;
    int n=5;
    for(i=1;i<n;i++)
    {
    	for(j=0;j<i;j++)
    	{
    		if(a[j]>a[i])
    		{
    			int t=a[j];
    			a[j]=a[i];
    			for (k=i; k > j; k--)
                {
                    a[k]=a[k-1];
                }
                a[k]=t;
    		}
    	}
    }
 for(i=0;i<n;i++)
    {
    	printf("%d\n",a[i]);
    }	return 0;
}