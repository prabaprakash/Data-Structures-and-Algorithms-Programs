#include<stdio.h>

int Binary_Search(int arr[], int low, int high, int item)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
            return mid;
        if(item<arr[mid])
            return Binary_Search(arr,low,mid-1,item);
        else return Binary_Search(arr,mid+1,high,item);
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
    loc=Binary_Search(arr, 0, size-1, item);
    if(loc!=-1)
        printf("\nItem found at location %d\n",loc);
    else printf("\nItem not found\n");

    return 0;
}
