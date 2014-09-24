#include<stdio.h>
#include<math.h>

void tower(int n,char beg,char aux,char end)
{
    if(n==1)
        printf("Move Disk From %c to %c\n",beg,end);
    else
    {
        tower(n-1,beg,end,aux);
        printf("Move Disk From %c to %c\n",beg,end);
        tower(n-1,aux,beg,end);
    }
}

int main()
{
    int disk;
    printf("Enter the number of disks you want top lay with:");
    scanf("%d",&disk);

    printf("\nThe No of moves required is =%d\n",(int)pow(2,disk)-1);
    tower(disk,'A','B','C');

    return 0;
}
