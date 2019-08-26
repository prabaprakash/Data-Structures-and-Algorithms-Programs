#include <stdio.h>
int f(int n)
{
    static int r = 0;
    if (n <= 0) return 1;
    if (n > 3)
    {
        r = n;
        return f(n-2)+2;
    }
    return f(n-1)+r;
}
 
int main()
{
    printf("%d", f(5));
}