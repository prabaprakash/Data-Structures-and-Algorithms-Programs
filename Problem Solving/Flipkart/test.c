#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
// Type Casting	
char c;
c=97;
printf("%c\n",c);

char a[10];
a[0]=c;
printf("%s\n",a);



int i ;
for (i= 65; i < 100; ++i)
{
//printf("%c\n",i);
}
// Upper to Lower
c='G';
if( 'A'<=c && c<='Z' )
putchar(c+'a'-'A');
else
putchar(c); 

// Lower to Upper
c='g';
if( 'A'<=c && c<='Z' )
putchar(c-'a'+'A');
else
putchar(c); 
}