#include<stdio.h>
#include<stdlib.h>
void swap(char *a,char *b)
{
char *t;
t=*a;
*a=*b;
*b=t;
}
int count=0;
void permutation(int k,int n,char *a)
{
if(k==n)
{
  count=count+1;

}
else
{
 int i=0;
 for(i=k;i<n;i++)
 {
  swap(&a[k],&a[i]);
  permutation(k+1,n,a);
  swap(&a[k],&a[i]);
 }
}
}
int main()
{
 char a[10]="aaaaa";
 permutation(0,strlen(a),a);
printf("\n%d\n",count);
return 0;
}
