#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i,j;

  char a[10][10]={"aa","bb","cdf","fgh"};


  char b[10];
  for (i = 0; i <4; ++i)
  {
  	for (j = 0; j < 4; ++j)
  	{
  		if(strcmp(a[i],a[j])<0)
  		{
         strcpy(b,a[i]);
         strcpy(a[i],a[j]);
         strcpy(a[j],b);
  		}

  	}
  }
  for (i = 0; i < 4; ++i)
  {
  	printf("%s\n",a[i]);
  }
	return 0;
}
