/* 
   Write a C program to find out if the underlying 
   architecture is little endian or big endian. 
 */
 
#include <stdio.h>
int main ()
{
	int value=0x10;
	int bit_mask=0x10;
  if ((value & bit_mask) == 0)
  	printf("same");
  else 
  	printf("not same");



  unsigned int x = 0x0F1A0A0A;
  unsigned int y = 0x0F1A;
  char *c = (char*) &x;
 
  printf ("*c is: decimal value of %d\n", *(c+0));
   printf ("*c is: 0x %x\n", *c);
  if (x == y)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
 
  return 0;
}