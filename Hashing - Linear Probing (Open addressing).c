#include<stdio.h>
#include<stdlib.h>
#define SIZE 13

int arr[SIZE]={};
int count;

int CalculateHash(int key)
{
    return key%SIZE;
}

void Insert(int element)
{
    if(count==SIZE){
        printf("Error.\nTable if FULL\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(arr[probe]!=NULL && arr[probe]!=-1)
    {
        probe=(probe+1)%SIZE;
    }
    arr[probe]=element;
    count++;
}

void Delete(int element)
{
    if(count==0){
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int loc=Search(element);
    if(loc!=-1)
    {
        arr[loc]=-1;
        count--;
    }
}

int Search(int element)
{
    if(count==0){
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(arr[probe]!=0)
    {
        if(arr[probe]==element)
            return probe;
        probe=(probe+1)%SIZE;
    }
    printf("\nElement %d not found.\n",element);
    return -1;
}

void PrintList()
{
    int i;
    for(i=0;i<SIZE;i++)
        printf("%d%c",arr[i],' ');
}

int main()
{
    int ch,item;
    printf("Enter Elements to insert in hash table :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        Insert(item);
    }while(item!=0);

    PrintList();

    printf("\nEnter the elements you want to delete :");
    printf("\nTo STOP, enter 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item)
            Delete(item);
    }while(item);

    PrintList();

    printf("\nEnter the elements you want to search :");
    printf("\nTo STOP, enter 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item){
            int loc;
            loc=Search((item));
            if(loc!=-1)
                printf("\nElement %d Found at location %d",item,loc);
        }
    }while(item);

    printf("\nEnter Elements to insert in hash table :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        Insert(item);
    }while(item!=0);

    PrintList();
    return 0;
}
