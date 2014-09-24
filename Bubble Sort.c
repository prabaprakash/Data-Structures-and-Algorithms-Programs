#include<stdio.h>

void Bubble_Sort(int *arr, int size)
{
    int i,j,t;
	for(i=0;i<=size-2;i++)
	{
		for(j=0;j<=size-2-i;j++)
		{
		    //largest element in the array will bubble to pos n-1-i
			if(arr[j]>arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
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

    Bubble_Sort(arr, size);

    printf("\nSorted Elements :\n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
