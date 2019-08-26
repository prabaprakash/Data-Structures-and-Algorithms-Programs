#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void print(int n,int val)
{
 int i=0;
    for(i=0;i<n;i++)
    {
     printf("%d",val);   
    }
}
int main() {
    int testcase,input;
    scanf("%d",&testcase);
    while(testcase--)
    {
     scanf("%d",&input);
     int remaining=input;
        int threes,fives;
        while(remaining>2)
        {
            if(remaining%3==0)
            {
             fives=remaining;   
                break;
            }
            remaining-=5;
        }
        threes=input-fives;
        if ( (remaining < 0) || threes % 5)
          printf("-1");
       else
       {
        print(fives,5);
        print(threes,3);
       }
        printf("\n");
    }
    
    return 0;
}
