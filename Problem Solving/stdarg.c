#include <stdio.h>
#include <stdarg.h>
int fun(int n, ...)
{
    int i, j = 1, val = 0;
    va_list p;
    va_start(p, n);
    for (; j < n; ++j)
    {
        i = va_arg(p, int);
       // printf("%d\n",i);
        val += i;
    }
    va_end(p);
    return val;
}
int main()
{
    printf("%d\n", fun(4, 1, 2, 3));
    return 0;
}