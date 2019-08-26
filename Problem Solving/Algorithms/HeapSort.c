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
void Heapify(int *heap, int index)
{
    if(heap[left(index)]==0)
       return;
    int temp;
    if(heap[left(index)]<heap[index]&&heap[right(index)]==0)//note
    {
        swap(&heap[left(index)],&heap[index]);
        return;
    }else if(heap[right(index)]==0)return;

    if(heap[left(index)]<heap[right(index)]&&heap[left(index)]<heap[index]){
        swap(&heap[left(index)],&heap[index]);
        Heapify(heap,left(index));
        return;
    }
    if(heap[left(index)]>=heap[right(index)]&&heap[right(index)]<heap[index]){
        swap(&heap[right(index)],&heap[index]);
        Heapify(heap,right(index));
        return;
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
        Heapify(heap,i);
}
int del_min()
{
    int min=heap[1];
    swap(&heap[1],&heap[n]);
    heap[n--]=0;
    Heapify(heap,1);
    return min;
}
int main()
{
    int i;
    int a[]={12,11,13,5,6,7};
    printf("Enter no. of elements to be Sorted :");
   // scanf("%d",&n);
    n=sizeof(a)/sizeof(a[0]);
    printf("Enter the Elements :\n");
    for(i=0;i<n;i++)
        heap[i+1]=a[i];
       // scanf("%d",&heap[i+1]);
    //printf("size of heap %d\n",sizeof(heap));
    Build_Heap(heap,n);
    int size=n;
    int arr[size];
    for(i=0;i<size;i++)
        arr[i]=del_min();
    printf("\nSorted Elements :\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
