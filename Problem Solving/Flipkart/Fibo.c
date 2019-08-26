#include<stdio.h>
unsigned long long one=0, zero=0;
unsigned  long long array[101];
unsigned  long long z[101];
unsigned  long long o[101];
int reco(int n)
{
    if (n<=0) zero++;
    if (n==1) one++;
    else
    {
        if(array[n-1])
        {
         zero+=z[n-1];
         one+=o[n-1];
        }
        else
        {
            if(reco(n-1))
            {
              array[n-1]=1;
              z[n-1]=zero;
              o[n-1]=one;
            }
            if(reco(n-2))
            {
              array[n-2]=1;
              z[n-2]=zero;
              o[n-2]=one;
            }
            if(reco(n-3))
            {
              array[n-3]=1;
              z[n-3]=zero;
              o[n-3]=one;
            }
        }
    }
    return 1;
}
int main()
{
    int i=0;
reco(10);
printf("%llu %llu",one,zero);

return 0;
}
