#include<stdio.h>

void Selection_Sort(int *arr,int size)
{
	int i,j,t,key;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
		    //key=arr[i];
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
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

    Selection_Sort(arr, size);

    printf("\nSorted Elements :\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
