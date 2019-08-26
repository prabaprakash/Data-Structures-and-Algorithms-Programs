#include<stdio.h>
#include<string.h>

int GradePoints(char a)
{
	char g[7]={'s','a','b','c','d','e'};
	int c=10;
	if(a=='f')
		return 0;
	for (int i = 0; i < 7; ++i)
	{
		if(g[i]==a)
		{
			return c;
		}
		c--;
	}

}
int main()
{
	int n;
	scanf("%d",&n);
    int credits[n];
    char a[n];
    float count=0;
    float gp=0;
    for(int i = 0; i < n; ++i)
    {
    	printf("Enter the Credit \n" );
    	scanf("%d %c",&credits[i],&a[i]);
    	
    }
    for(int i = 0; i < n; ++i)
    {
       count=count+credits[i];
       gp=gp+(credits[i]*GradePoints(a[i]));
    }
	
	printf("GPA %f\n",gp/count);
	return 0;
}