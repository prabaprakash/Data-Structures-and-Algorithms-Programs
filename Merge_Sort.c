#include<stdio.h>
void Merge(int arr[], int p, int q, int r)
{
    int A[r-p+1];
    int low1=p, low2=q+1, high1=q, high2=r;
    int i=-1,j;
    while(1)
    {
        if(arr[low1]<arr[low2]){
            A[++i]=arr[low1];
            low1++;
        }else{
            A[++i]=arr[low2];
            low2++;
        }
        if(low1>high1)
        {
            for(j=low2;j<=high2;j++)
                A[++i]=arr[j];
            break;
        }
        else if(low2>high2)
        {
            for(j=low1;j<=high1;j++)
                A[++i]=arr[j];
            break;
        }
    }
    A[++i]='\0';

    for(i=0;i<r-p+1;i++)
        arr[p+i]=A[i];
}
void Merge_Sort(int arr[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        Merge_Sort(arr,p,q);
        Merge_Sort(arr,q+1,r);
        Merge(arr,p,q,r);
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

    Merge_Sort(arr,0,size-1);
    //How many Merge Sort calls are made...?
    //2n-1 Merge Sort calls. Why??
    printf("\nSorted Elements :\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
