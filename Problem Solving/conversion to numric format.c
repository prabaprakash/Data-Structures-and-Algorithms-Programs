#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %0*d \n", 5, 10);
   // atof
   printf("%4.3f\n",atof("2.3"));
   printf("%d\n",atoi("323"));
    printf("Decimal Value for %s is  %d \n","92",  strtol("92",NULL,10));

    printf("Ocatl Value for %s is  %o \n","92",    strtol("92",NULL,10));

    printf("Hex Value for %s is  %x \n","92",      strtol("92",NULL,10));
    
   
    

	return 0;
}