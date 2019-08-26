#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* writes(char *a,int i,int j)
{
  int k=0;
  char *sub=(char *)calloc(1,sizeof(char));
  int h=0;
  for (k = i; k < j; ++k)
  {
    sub[h]=a[k];
    h++;
  }
  return sub;
}
int main()
{
/*char *str =(char *)malloc(sizeof(char)*5);
  strcpy(str,"abcd");
  printf("%c\n",*(str+3));*/
  char str[10]="123";
  char sub[10]="a";
char *buffer=(char *)calloc(30,sizeof(char));
int i,j;
int n=strlen(str);
int count=0;
    //str[strlen(str) - 1] = '\0';
	for (i = 0; i <n; i++)
	{ 
	     for (j = i+1 ; j <=n ; j++)
	     {
	       strncpy(buffer,&str[i],j);
	        buffer[j]='\0';
	        printf("%s\n",writes(str,i,j));
	       //printf("%s %d\n",buffer,strspn(sub,buffer));
	       if(strspn(sub,buffer)>=strlen(sub))
	        	count++; 	
	     	
	     }
	}
    printf("%d\n",count);

	     
}