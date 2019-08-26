#include <stdio.h>
int main()
{
	/*
a[100][100]

Address of a[40][50] = Base address + 40*100*element_size + 50*element_size
                      = 0 + 4000*1 + 50*1
                     = 4050

                     */
int a[100][10]; 
printf("%d\n",&a[0][0]);
//2646592
printf("%d\n",&a[40][10]);
// a[40][50]=2646592+ 40*100*4 + 50*4 =2662792

char b[100][100];
//printf("%d\n",&b[0][0]);
//printf("%d\n",&b[40][50]);
return 0;
}