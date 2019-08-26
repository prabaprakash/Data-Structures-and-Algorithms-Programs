#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int n;
    scanf("%d",&n);
    while(n--)
    {
     int a;
     char *buffer=(char *)calloc(100,sizeof(char));
     scanf("%d",&a);
     sprintf(buffer,"%d",a);
     //printf("%s\n",buffer);
     int i=0;
     int count=0;
        for(i=0;i<strlen(buffer);i++)
        {
            char buff[10];
            buff[0]=buffer[i];
           //printf("%s\n",buff);
            int k=atoi(buff);
            if(k==0)
                {
                continue;
            }
            if((a%k)==0)
            {
               count++;
            }
        }
        printf("%d\n",count);
    }
        
    return 0;
}
