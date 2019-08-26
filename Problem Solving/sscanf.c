 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   
   char a[10]="we 32 sd",b[20];
    int c;
    sscanf(a,"%s %d",b,&c);
    printf("%s %d\n",b,c);
    return 0;
}
