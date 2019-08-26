#include<stdio.h>
#include<string.h>
#include<math.h>
int* rank(int table[],int tableLength){
    int result[tableLength];
    int i,z;
	for(i=0;i<tableLength;i++){
		int rnk=0;
		for(z=0;z<tableLength;z++){
			if(table[z]<table[i])
				rnk++;
		}
    result[i]=rnk;
	}
    return result;
}

void Spearman(int* a,int* b,int n)
{
  int* ra=rank(a,n);
  int* rb=rank(b,n);
  int d=0;
  int i=0;
  for ( i = 0; i < n; ++i)
  {
    d+=pow(ra[i]-rb[i],2);
  }
  int r=1-6*d/(pow(n,3)-n);
  printf("d^2 = %d rank = %d\n",d,r);

}
void Pearson(int* a,int* b,int n)
{
 int ex=0;
 int ey=0;
 int exy=0;
 int exs=0;
 int eys=0;
 int i=0;
 for(i=1; i<=n; i++)
 {
     ex+=a[i];
     ey+=b[i];
     exy+=a[i]*b[i];
     exs+=pow(a[i],2);
     eys+=pow(b[i],2);
 }
 int v1=exy-((ex*ey)/n);
 int v2=exs-(pow(ex,2)/n);
 int v3=eys-(pow(ey,2)/n);
 int v4=v2*v3;
 float rank=v1/sqrt(v4);
 printf("ex=%d  ey=%d exy=%d exs=%d eys=%d v1=%d v2=%d v3=%d v4=%d rank=%f \n",ex,ey,exy,exs,eys,v1,v2,v3,v4,rank);
}
int main()
{
    int n;
    printf("enter n \n");
    scanf("%d",&n);
    int a[n];
    int b[n];
    int i=0;
    for(i=1; i<=n; i++)
    {
        printf("a[%d] and b[%d]\n",i,i);
        scanf("%d%d",&a[i],&b[i]);
    }
    printf("Spearman Coefficient\n");
    Spearman(a,b,n);
    printf("Pearson Coefficient\n");
    Pearson(a,b,n);
}
