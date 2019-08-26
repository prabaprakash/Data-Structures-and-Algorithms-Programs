#include <stdio.h>
extern int i=0;
int main()
{
  i=100;
  printf("%d ", i);
  {
       int i = 10;
       printf("%d ", i);
  }
}