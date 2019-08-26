#include <stdio.h>
#include <malloc.h>
#include <limits.h>
char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;

int main()
{
    ///\S+@\S+\.\S+/


    int i;
    int *ptr = (int *) malloc(5 * sizeof(int));
 
    for (i=0; i<5; i++)
        *(ptr + i) = i;
 
    printf("%d ", *ptr++);
    printf("%d ", (*ptr)++);
    printf("%d ", *ptr);
    printf("%d ", *++ptr);
    printf("%d \n\n", ++*ptr);

    printf("\n1D array = %d\n",ptr);
    ptr++;
    printf("1d Array ++ =%d\n",ptr);
    printf("%d\n", *ptr);


    int a[][3] = {1, 2, 3, 4, 5, 6};
    printf("%d\n",a);
    int (*ptrr)[3] = a;
    printf("%d\n",ptrr);
     printf("%d %d %d\n",(*ptrr)[0], (*ptrr)[1], (*ptrr)[2]);

    ++ptrr;
    printf("Moved %d\n",ptrr);
    printf("%d %d %d\n",(*ptrr)[0], (*ptrr)[1], (*ptrr)[2]);
    int y = ~1;
     printf("Y is %d\n",y); 

      char c = 125;
    c = c+10;
    printf("%d", sizeof(int)>-1);
    return 0;

    return 0;
}
