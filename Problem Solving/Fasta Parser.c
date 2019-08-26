#include <stdio.h>
#include <string.h>
int main()
{
	FILE *p;
	p=fopen("a.fasta","r");
	char a[1000];
	while(!feof(p))
	{
		char b[1000];
     fscanf(p,"%s",b);
     strcat(a,b);
     ///printf("%s\n",b);
	}
	printf("%d\n",strlen(a));
	int n=strlen(a);
	int k=14;
	int l=0,i=0,j;
	for (i = -1; i <n; ++i)
	{
		if((n-i)>k)
		{ 
		for (j = i+1; j <= k+i; ++j)
		{
			if(k+i==j)
			printf("%c",a[j]);
		else
			printf("%c,",a[j]);
		}
		printf("\n");
	    }
		
	}
	return 0;
}