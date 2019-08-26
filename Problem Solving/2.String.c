#include <stdio.h>
#include <string.h>
void my_toUpper(char* str, int index)
{
    *(str + index) &= ~32;
}
  
int main()
{
    char* arr = "geeksquiz";
    my_toUpper(arr, 0);
    my_toUpper(arr, 5);
    printf("%s", arr);
    return 0;
}