#include<stdio.h>

//VAF=(d*0.001)+0.65
//Functionpoint=UAF+VAF
int uaf()
{
    char name[50][50]={"External Input","External Ouput","Internal Logical Files","External Interfaces","External Inquiry"};
    int a[5],i=0;
    int complexity[5][3]={{3,4,6},{4,5,7},{7,10,15},{5,7,10},{3,4,6}};
    int uaf=0;
    int j=0;
    for(i=0;i<5;i++)
    {
     printf("Enter Value for %s\n",name[i]);
     scanf("%d",&a[i]);
     printf("Enter the Complexity\n1.Simple or Low \n2.Average \n3.High\n");
     scanf("%d",&j);
     uaf=uaf+(a[i]*complexity[i][j-1]);
    }
    return uaf;
}
float vaf()
{
    int a[14],i=0;
    float count=0;
    for(i=1;i<=14;i++)
    {
     printf("Enter Value for Factor %d\n Between 1 - 5\n",i);
     scanf("%d",&a[i]);
     count=count+a[i];
    }
    
    return (count*0.01)+0.65;
}

int main()
{
    int uafactor=uaf();
    float vafactor=vaf();
    printf("\n UAF = %d \n",uafactor);
    printf("\n VAF = %f \n",vafactor);
    float fp=(float)uafactor*vafactor;
    printf("Function Pointer = %f\n",fp);
    printf("Enter the Fp/Month");
    float mo;
    scanf("%f",&mo);
    float month=fp/mo;
    printf("Total Month Need for Project = %f \n",month);
    printf("Enter the Labor rate /Month");
    float la;
    scanf("%f",&la);
    float cost=month*la;
    printf("Total Cost = %f \n",cost);
    
}
