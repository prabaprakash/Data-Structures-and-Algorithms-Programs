#include <stdio.h>
int func(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num <<= 4;
    }
    return (count);
}
int main()
{
	printf("%d\n",func(435));
	return 0;
}