#include<stdio.h>
void Insertion_Sort(int arr[], int size)
{
    int i,j;
    int key;
    //at any point array is sorted from index [0...j-1].
    //at jth position lies the element which we have to insert in sorted sequence.
    for(j=1;j<size;j++)
    {
        key=arr[j];
        i=j-1;
        //Insert Key into sorted sequence arr[0...j-1]
        while(i>=0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}
int main()
{
    int i,size;

    printf("Enter no. of elements to be Sorted :");
    scanf("%d",&size);

    int arr[size];

    printf("Enter the Elements :\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

    Insertion_Sort(arr, size);

    printf("\nSorted Elements :\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
