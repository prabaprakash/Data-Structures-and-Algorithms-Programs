#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

int main()
{
	long n,a,b,l;
    scanf("%ld",&b);
    l=0;
  char *aa=(char*)calloc(1,sizeof(char));
	while(b>0)
	{
		a=b%2;
		b=b/2;
    char *bb=(char*)calloc(1,sizeof(char));
    bb[0]=(a==0)?'0':'1';
    strcat(aa,bb);
       // l=a+l*10;
	}
  strrev(aa);
  printf("%s\n",aa);
	//printf("%ld\n",l);
	return 0;
}