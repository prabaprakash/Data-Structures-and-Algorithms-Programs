#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

       char c= 'd';
      char *str=(char*)malloc(sizeof(char));
      char *buffer;
        fgets(str, 10000, stdin);
        int i=0;
        for(buffer=strtok(str,"-");buffer!=NULL;buffer=strtok(NULL,"-"))
        {
        	printf("%s\n",buffer);
        }
        printf("%c %s\n",c,str);
return 0;
    }
