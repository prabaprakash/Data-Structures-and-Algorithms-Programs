#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
char* rotate(char arr[10],int k,int n)
{
     int i,j;
     char *cip=(char *)calloc(n,sizeof(char));
     k=k%26;
     for(i=0;i<n;i++)
     {
      if(isalpha(arr[i]))
      {
                  if((arr[i]>=65)&&(arr[i]<=90))
                  {
                   if((arr[i]+k)>90)
                       {
                       cip[i]=arr[i]+k-26;
                   }
                      else
                          cip[i]=arr[i]+k;
                  }
                  else if((arr[i]>=97)&&(arr[i]<=122))
                  {
                   if((arr[i]+k)>122)
                       {
                       cip[i]=arr[i]+k-26;
                   }
                      else
                          cip[i]=arr[i]+k;
                  }
      }
      else
        {
             cip[i]=arr[i];
        }
     }
    return cip;
}
int main() {

    int n,k;
    scanf("%d",&n);
    char array[n+1];
    scanf("%s",&array);
    scanf("%d",&k);
    printf("%s\n",rotate(array,k,n));
    return 0;
}
