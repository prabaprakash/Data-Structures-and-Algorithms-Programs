#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list*next;
}*start,*revHead;

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

struct list* RecursiveReverse(struct list *ptr)
{
    if(ptr==NULL)
        return NULL;

    if(ptr->next==NULL)
        revHead=ptr;
    else
        RecursiveReverse(ptr->next)->next=ptr;

    if(ptr==start)      //reached end of the list
    {
        ptr->next=NULL;
        return revHead;
    }
    else
        return ptr; //returning the same node
}

int main()
{
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

	printf("\n\nComplete Linked list :\n");
	PrintList(start);
	start=RecursiveReverse(start);
	printf("\nReverse Linked list :\n");
	PrintList(start);
	return 0;
}
