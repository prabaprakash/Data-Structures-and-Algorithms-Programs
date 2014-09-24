#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list*next;
};

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
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}

void DeleteList(struct list** headRef)//a reference to the head pointer
{
    struct list* current = *headRef; // deref headRef to get the real head
    struct list* next;
    while(current!=NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL; // Again, deref headRef to affect the real head back in the caller.
}

int main()
{
	struct list*start=NULL;		//start is declared locally..
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

	PrintList(start);
	DeleteList(&start);
	PrintList(start);
	return 0;
}
