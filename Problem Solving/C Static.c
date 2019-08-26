#include <stdio.h>
int a, b, c = 0;
void prtFun (void);
int main ()
{
    static int a = 1; /* line 1 */
    prtFun();
    prtFun();
    a += 1;
   
    printf ( "\n %d %d " , a, b) ;
}
  
void prtFun (void)
{
    static int a = 2; /* line 2 */
    int b = 1;
    a += ++b;
    printf (" \n %d %d " , a, b);
}