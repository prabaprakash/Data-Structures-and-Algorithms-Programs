#include <stdio.h>
 
int main(void)
{
    int i = 10;
    int d=100;

     const int *ptr = &i;
     ptr=&d;
    printf("i = %d\n", *ptr);

    int const *btr=&i;
    
    // const int *ptr -poniter to constant we can change only pointer
    // int const *btr -pointer to integer constant we can change only value 
    return 0;
}