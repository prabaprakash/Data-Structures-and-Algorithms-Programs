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
void del_min()
{
    //swap first and last element
    swap(&heap[1],&heap[n]);
    //delete last node
    heap[n--]=0;
    //call heapify procedure on first node
    Heapify(heap,1);
}
int main()
{
    int i;
    printf("Enter no. of elements to build in a heap :");
    scanf("%d",&n);
    printf("Enter Elements to build a heap :\n");
    for(i=0;i<n;i++)
        scanf("%d",&heap[i+1]);
    Build_Heap(heap,n);//note why not Build_Heap(heap+1,n);
    show(1,0);
    Insert(heap,1);
    printf("\nAfter Inserting 1\n\n");
    show(1,0);
    printf("After Deleting Minimum.");
    del_min();
    show(1,0);
    return 0;
}
