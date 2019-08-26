#include <stdio.h>

int main()
{
	int t,i,j,l;
	int n,k,p;
		 int count;
	 	 int bool;
		 int a[k];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	    bool=0;
	    count=0;
	 scanf("%d%d%d",&n,&k,&p);
	 if((n-k)<=p)
	 {
	  printf("-1\n");
	 }

	 else
	 {

	 	 for(l=0;l<k;l++)
	 	 {
	     scanf("%d",&a[l]);
	 	 }

	 	for(j=1;j<=n;j++)
	 	{
	     for(l=0;l<k;l++)
	 	 {
	      if(j==a[l])
	      {
	      	bool=1;
	      }
	 	 }
	 	 if(bool==0)
	 	 {
	 	 	count++;
	 	 }
	 	 else
	 	    bool=0;

	 	   if(count==p)
	 	   {
	 	   	printf("%d\n",j);
	 	   }
	 	}
	 }
	}
}
