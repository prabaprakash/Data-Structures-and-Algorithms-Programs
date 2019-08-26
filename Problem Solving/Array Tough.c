#include <stdio.h>
#define SIZE(arr) sizeof(arr) / sizeof(*arr);
void fun(int* arr, int n)
{
    int i;
    *arr += *(arr + n - 1) += 10;
}
 
void printArr(int* arr, int n)
{
    int i;
    for(i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
 
int main()
{
    int arr[] = {10, 20, 30};
    int size = SIZE(arr);
    printf("%d\n",size);
    fun(arr, size);
    printArr(arr, size);

    //Next 
    int c[]={10,20,30,40};
    (c+1)[3]=85012345;
    printf("%d\n",c[4]);

    int d;
    d=3,12;
    printf("%d\n",d);
    
    


    return 0;
}