/* longjmp example */
#include <stdio.h>      /* printf */
#include <setjmp.h>     /* jmp_buf, setjmp, longjmp */
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <malloc.h>
#include <stdarg.h>
#include <unistd.h>
int main()
{
  jmp_buf env;
  int val;

  val=setjmp(env);

  printf ("val is %d\n",val);

  if (!val) longjmp(env, 10);

  return 0;
}