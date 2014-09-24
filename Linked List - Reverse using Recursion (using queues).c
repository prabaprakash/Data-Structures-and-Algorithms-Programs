#include<stdio.h>
#include<stdlib.h>  //for exit() function
#define MAX 10

struct queue
{
    int front;
    int rear;
    int arr[MAX];
}*pt;

struct list{
	int data;
	struct list*next;
};

int dequeue()   //dequeue will return the item in this case
{
   if(IsEmpty())
   {
       printf("UnderFlow\nProgram Terminated\n");
       exit(EXIT_FAILURE);
   }
   int item;
   item=pt->arr[pt->front];
   pt->arr[pt->front]=NULL;
   pt->front=(pt->front+1)%MAX;
   return item;
}

void enqueue(int x)
{
    if(size()==MAX-1)
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    pt->arr[pt->rear]=x;
    pt->rear=(pt->rear+1)% MAX;
}

int front()
{
    if(IsEmpty()){
       printf("UnderFlow\nProgram Terminated\n");
       exit(EXIT_FAILURE);
    }
    return pt->arr[pt->front];
}

void NewADT()
{
    pt=(struct queue*)malloc(sizeof(struct queue));
    pt->front=0;
    pt->rear=0;
}

int size()
{
    return (MAX-pt->front+pt->rear)%MAX;
}

int IsEmpty()
{
    return pt->front==pt->rear;
}

struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=NULL;
	return Node;
}

void PrintList(struct list* ptr)
{
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void ReverseLinkedList(struct list* node)
{
    if(node==NULL)
        return ;
    enqueue(node->data);
    ReverseLinkedList(node->next);
    node->data=dequeue();
}

int main()
{
    NewADT();
    struct list*start=NULL;		//start is a pointer to struct list..
	struct list*Node=NULL,*ptr=NULL;
	char ch;
	do
	{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%d",&Node->data);

		if(start==NULL)
			start=Node;
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

	printf("\nComplete Linked list :\n");
	PrintList(start);
	ReverseLinkedList(start);
	printf("\nReverse Linked list :\n");
	PrintList(start);
    return 0;
}
