#include<stdio.h>

int Binary_Search(int arr[], int size, int item)
{
    int low, mid, high;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
            return mid;
        if(item<arr[mid])
            high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main()
{
    int i,size,item,loc;

    printf("Enter no. of elements in the array :");
    scanf("%d",&size);

    int arr[size];

    printf("Enter the Elements in Ascending Order:\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

    printf("Enter the item you want to search :");
    scanf("%d",&item);
    loc=Binary_Search(arr, size, item);
    if(loc!=-1)
        printf("\nItem found at location %d\n",loc);
    else printf("\nItem not found\n");

    return 0;
}
