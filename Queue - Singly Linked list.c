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
	if(front==NULL)
        rear=NULL;
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
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("\nEnter ur choice:");
		switch(getch())
		{
            case '1':
                printf("\nEnter a item you want to Enqueue :");
                scanf("%d",&data);
                Enqueue(data);
                break;
            case '2':
                Dequeue();
                break;
            case '3':
                print();
                break;
            case '4':
                exit(0);
            default:
                printf("\nEnter a valid choice");
                break;
		}
	}
	return 0;
}
