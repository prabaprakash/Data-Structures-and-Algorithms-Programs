// 10 => 0000000000000000000000000000001010 , reverse it => get value , print it
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int binary()
{
	int n,i,x;
	printf("Enter th number");
	scanf("%d",&n);
	//n=x;
	char *binary=(char *)calloc(32,sizeof(char));
	for(i=0;i<=31;i++)
	{
		x=n%2;
		n=n/2;

		char *buffer;
		buffer=(x==0)?"O":"1";
		strcat(binary,buffer);
		//printf("%d",x);
		
	}
	
	strrev(binary);
	unsigned int count=0;
	printf("%d\n",strlen(binary));
	for (i = 0; i < strlen(binary); ++i)
	{
		if(binary[i]=='1')
		{
          count+=pow(2,i);
		}
	}
	printf("%s\n",binary);
	printf("%s\n",strrev(binary));
	printf("%u\n",count);

}
int main()
{
	binary();
	return 0;
}

