#include <stdio.h>

void qs(int *a,int start,int end)
{
	if(start<end)
	{
		int pindex=partition(a,start,end);
		qs(a,start,pindex-1);
		qs(a,pindex+1,end);
	}
}
int partition(int *a,int start,int end)
{
	int pivot=a[end];
	int pindex=start;
	int i=0;
	for (i = start; i <end; ++i)
	{
		if(a[i]<=pivot)
		{
			swap(&a[pindex],&a[i]);
			pindex++;
		}
	}
	swap(&a[pindex],&a[end]);
	return pindex;

}
void swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int main()
{
    int a[10]={3,4,345,2,34,55,23,44,5,6};
   // printf("%d\n",a[9]);
    qs(a,0,9);
    int i;
    for (i = 0; i < 10; ++i)
    {
    	printf("%d\n",a[i]);
    }
	return 0;
}