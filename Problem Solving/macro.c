#include <stdio.h>
#include <stdlib.h>
#define PRINT(i, limit) do \
                        { \
                            if (i++ < limit) \
                            { \
                                printf("GeeksQuiz\n"); \
                                continue; \
                            } \
                        }while(0)

void pri(int i,int limit)
{
     do 
        { 
            if (i++ < limit) 
            { 
                printf("GeeksQuiz\n"); 
                continue; 
            } 
        }while(0);
}
int main()
{

    int c = 5, no = 10;
      
     // no=0/0;
      fprintf(stderr, "%s\n","fdf");
       fprintf(stderr, "%s: error writing stdout\n", "dd");
           exit(2);
    printf ("%d\n", no);
    return 0;
}