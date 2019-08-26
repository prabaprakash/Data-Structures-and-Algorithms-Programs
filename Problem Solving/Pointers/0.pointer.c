#include<stdio.h>
int f2(int *a) {
*a = 5;
return 0;
}
int main()
{
    // a. Pointer
    int a[10];
    a[2]=10;
    int b[10][10];
    printf("%d\n",*(a+2));
    // b. Pointer for Array
    b[1][2]=40;
    printf("%d\n",*(*(b+1)+2));
    // C.Pointer Reference
    int c[10];
    f2(c);
    printf("%d\n",*c);
return 0;
}
