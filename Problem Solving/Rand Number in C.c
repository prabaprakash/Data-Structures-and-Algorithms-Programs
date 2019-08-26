#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
     srand(time(NULL)); 
     //use current time as seed for random generator
    for (int i = 0; i < 10; ++i)
    {
    	/* code */
    	int random_variable = rand()%21+10;
  //  printf(" %d\n", random_variable);
    }
    

}