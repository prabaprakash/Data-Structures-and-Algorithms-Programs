#include <stdio.h>
#include <stdlib.h>

int main ()
{

  int i=92;
  char buffer [33];
  printf ("Enter a number: ");
  //scanf ("%d",&i);
  itoa (i,buffer,10);
  printf ("decimal: %s\n",buffer);
   itoa (i,buffer,8);
  printf ("Octal: %s\n",buffer);
  itoa (i,buffer,16);
  printf ("hexadecimal: %s\n",buffer);
  itoa (i,buffer,2);
  printf ("binary: %s\n",buffer);


  //left shift

  i=i>>2;
   itoa (i,buffer,2);
  printf ("binary: %s\n",buffer);

  sprintf(buffer,"%x",10);
  printf("%s\n",buffer);
  return 0;
}