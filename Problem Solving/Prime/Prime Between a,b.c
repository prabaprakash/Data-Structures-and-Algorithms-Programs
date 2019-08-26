#include <stdio.h>
#include <math.h>
int main()
{
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int a,b,i,flag=1,j,count=0;
        scanf("%d%d",&a,&b);
        if(a==1)
            a++;
        for (i = a; i <=b; ++i)
        {
            flag=1;
            int s=sqrt(i);
            for (j = 2; j<=s; ++j)
            {
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
            	printf("%d\n",i);
                count=count+i;
            }
        }
        //printf("%d",count);
    }
}