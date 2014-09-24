#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct list{
	int info;
	struct list*next;
}*ptr=NULL,*temp=NULL,*rear=NULL,*front=NULL;

struct list* NewNode()
{
	struct list* node;
	node=(struct list*)malloc(sizeof(struct list));
    node->info=NULL;
	node->next=NULL;
	if(node!=NULL)
		return node;
	else{
		printf("\nStack Overflow");
		exit(1);
	}
}

int Dequeue()   //delete at the beginning
{
	int item;
	if(front==NULL)
	{
		printf("\nQueue Underflow");
		exit(1);
	}
	temp=front;
	item=temp->info;
	front=front->next;
	free(temp);
	return item;
}

void Enqueue(int item)  //insertion at the end
{
	struct list* node=NewNode();
	node->info=item;
	if(front==NULL){
		front=node;
		rear=node;
	}else{
		rear->next=node;
		rear=node;
	}
	return;
}

int DeleteLast()        //inefficient
{
    struct list*temp;
    ptr=front;
    if(front==rear)
    {
        free(front);
        front=NULL;
        rear=NULL;
        return;
    }
    while(ptr->next!=rear)
    {
        ptr=ptr->next;
    }
    temp=rear;
    rear=ptr;
    ptr->next=NULL;
    free(temp);
}

void InsertFirst(int item)
{
    struct list*node=NewNode();
    node->info=item;
    if(front==NULL)
    {
		front=node;
		rear=node;
		return;
	}
    node->next=front;
    front=node;
}

void print()
{
	if(front==NULL)
	{
		printf("\nQueue is empty\n");
		return;
	}
	ptr=front;
	printf("\n\nThe linked list implementation of queue :\n\n");
	while(ptr)
	{
		printf("%d->",ptr->info);
		ptr=ptr->next;
	}
	printf("NULL\n");
	return;
}

int main()
{
	int data,choice;
	while(1)
	{
		printf("\n1.Enqueue(InsertLast)\n2.Dequeue(DeleteFirst)\n3.Insert First\n4.Delete Last\n5.Display\n6.Exit\n");
		printf("\nEnter ur choice:");
		switch(getch())
		{
		case '1':
			printf("\nEnter a item you want to Insert :");
			scanf("%d",&data);
			Enqueue(data);
			break;
		case '2':
			Dequeue();
			break;
        case '3':
			printf("\nEnter a item you want to Insert :");
			scanf("%d",&data);
			InsertFirst(data);
			break;
		case '4':
			DeleteLast();
			break;
		case '5':
			print();
			break;
		case '6':
			exit(0);
		default:
			printf("\nEnter a valid choice");
			break;
		}
	}
	return 0;
}
