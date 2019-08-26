#include<stdio.h>
int main()
{
	int a,b,i,count=0,n;
	printf("Enter the N number \n");
	scanf("%d",&n);
    int m;
	for(i=1;i<n;i++)
	{
		a=i;
		while(b!=0)
		{
	      m=a%b;
	      a=b;
	      b=m;
		}
		b=n;
		//printf("%d\n",a);
	    if(a==1)
	    	count++;
    }
    printf("%d\n",count);
    return 0;
}