#include<stdio.h>
int main()
{
	int a,b;
    scanf("%d%d",&a,&b);
	int m;
	while(b!=0)
	{
      m=a%b;
      a=b;
      b=m;
	}
    printf("%d\n",a);
    return 0;
}