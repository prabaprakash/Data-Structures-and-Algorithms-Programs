#include<stdio.h>
#include<math.h>
int heap[100];
int n;      //heap size
int parent(int index)
{
    return floor(index/2);
}
int left(int index)
{
    return 2*index;
}
int right(int index)
{
    return 2*index+1;
}
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void MaxHeapify(int *heap, int index)
{
	int left=2*index;
	int right=2*index+1;
	int largest=index;
    if(left<n && heap[left]>heap[largest])
       largest=left;
   
    if(right<n && heap[right]>heap[largest])//note
       largest=right;

    if(largest!=index)
    {
    	swap(&heap[largest],&heap[index]);
    	MaxHeapify(heap,largest);
    }
}
void show(int index, int space)
{
    int i;
    if(heap[index])
    {
        show(right(index),space+=6);
        printf("\n");
        for(i=0;i<space;i++)
            printf(" ");
        printf("%d ",heap[index]);
        printf("\n");
        show(left(index),space);
     }
}
void Insert(int heap[], int item)
{
    heap[++n]=item;
    int index=n;
    while(heap[parent(index)]>item)
    {
        swap(&heap[parent(index)], &heap[index]);
        index=parent(index);
    }
}
void Build_Heap(int heap[],int n)
{
    int i;
    for(i=floor(n/2);i>=1;i--)  //start from parent(n)=floor(n/2)
        MaxHeapify(heap,i);

    
}
int del_max()
{
    int max=heap[1];
    swap(&heap[1],&heap[n]);
    heap[n--]=0;
    MaxHeapify(heap,1);
    return max;
}
int main()
{
    int i;
    int a[]={12,11,13,5,6,7,543,545,345,3,3,545,4646,45454,5434343,434343};
    printf("Enter no. of elements to be Sorted :");
   // scanf("%d",&n);
    n=sizeof(a)/sizeof(a[0]);
    printf("Enter the Elements :\n");
    for(i=0;i<n;i++)
        heap[i+1]=a[i];
       // scanf("%d",&heap[i+1]);
    Build_Heap(heap,n);
    int size=n;
    int arr[size];
    for(i=size-1;i>=0;i--)
    {
    	//printf("MaxHeapify %d\n",heap[1]);
        arr[i]=del_max();

    }
    printf("\nSorted Elements :\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
