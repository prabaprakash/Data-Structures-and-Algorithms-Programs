#include<stdio.h>
struct dic
{
    char s[10];
    int d;
}ss[10];
int main()
{
    char a[10][10]={"fun"};
    int len=3;
    int i=0,j,count=0,check=0;
    for(i=0;i<len;i++)
    {
       // printf("%s",a[i]);
        for(j=0;j<count;j++)
        {
            if(strcmp(a[i],ss[j].s)==0)
            {

               ss[j].d=len-i-1;
               check=1;
            }
        }
        if(check==0)
        {
           strcpy(ss[count].s,a[i]);
           printf("%c\n",a[i]);
            ss[count].d=len-i-1;
            count++;
        }
        check=0;
    }
     for(j=0;j<count;j++)
     {
      printf("%s == %d\n",ss[j].s,ss[j].d);
     }
    return 0;
}
