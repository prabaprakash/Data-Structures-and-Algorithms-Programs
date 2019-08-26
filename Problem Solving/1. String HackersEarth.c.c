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
  int n;
  scanf("%d",&n);
  while(n--)
  {
    char str[200];
    scanf("%s",&str);
    int m,count=0;
    char sub[200];
    scanf("%d",&m);
    while(m--)
    {
      scanf("%s",&sub);
      int i,j;
      for(i=0;i<strlen(str);i++)
      {
        for (j = i+1; j <= strlen(str); ++j)
        {
          //char *buffer=(char*)calloc(1,sizeof(char));
          //strncpy(buffer,&str[i],j);
          //printf("%s %d\n",buffer,strspn(sub,buffer));
         if(strspn(sub,writes(str,i,j))>=strlen(sub))
            count++;  
        }
      }
      printf("%d\n",count);
      
      count=0;
    }
  }
    return 0;
}
