#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int m,n,r;
int *array[300];
int getMatrix()
{

    scanf("%d %d %d",&m,&n,&r);
    
    int i,j;
     
    if((2<=m)&&(n<=300)&&(1<=r)&&(r<=1000000000))
    {
        r=r%(m*n);
        for(i=0;i<m;i++)
            {
            array[i]=(int *)malloc(sizeof(int)*n);
            for(j=0;j<n;j++)
                {
                scanf("%d",&array[i][j]);
                if((1<=array[i][j])&&(array[i][j]<=100000000))
                    {
                }
                else
                    return 0;
            }
        }
    }
    else
        {
        return 0;
    }
    return 1;
}
void displayMatrix()
{
       int i,j;
        for(i=0;i<m;i++)
            {
           
            for(j=0;j<n;j++)
                {
               printf("%d ",array[i][j]);
            }
            printf("\n");
        }
}
int rotateMatrix()
{
      if(r==0)
       {
        return 1;
       }
       else
       {
        return 1;
       }

}
int main() {

    if(!getMatrix()){
     printf(" ");
     return 0;
    }
    if(rotateMatrix())
    {
        displayMatrix();
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
