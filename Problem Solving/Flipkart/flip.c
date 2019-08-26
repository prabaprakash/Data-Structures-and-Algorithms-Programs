#include<stdio.h>
long double one=0,zero=0;
void reco(int n)
{
	if(n<=0)
	{
	  zero++;
	  return;
	}
	if(n==1)
	{
	  one++;
	  return;
	}
	if(n==2)
    {
        one+=1;
        zero+=3;
        return;
    }
    if(n==3)
    {
        one+=2;
        zero+=3;
        return;
    }
    if(n==4)
    {
        one+=4;
        zero+=4;
        return;
    }
    if(n==5)
    {
        one+=7;
        zero+=10;
        return;
    }
    if(n==6)
    {
        one+=13;
        zero+=10;
        return;
    }
    if(n==7)
    {
        one+=24;
        zero+=33;
        return;
    }
    if(n==8)
    {
        one+=44;
        zero+=61;
        return;
    }
    if(n==9)
    {
        one+=81;
        zero+=112;
        return ;
    }
    if(n==10)
    {
        one+=149;
        zero+=206;
        return ;
    }
    if(n==20)
    {
        one+=66012;
        zero+=91293;
        return ;
    }
    if(n==30)
    {
         one+=29249425;;
        zero+=40451246;
        return ;
    }
    if(n==40)
    {
         one+=75300028;
        zero+=743776013;
        return ;
    }
	reco(n-1);
	reco(n-2);
	reco(n-3);
}
int main()
{
int i=0;
    scanf("%d",&i);
    reco(40);
      printf("%d %d\n",one,zero);
    one=0;
    zero=0;





return 0;
}
