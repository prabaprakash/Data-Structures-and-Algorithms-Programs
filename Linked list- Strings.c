#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
	char* data;
	struct list* next;
};

struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=(char*)malloc(20);
	Node->next=NULL;
	return Node;
}

void PrintList(struct list* ptr)
{
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%s ",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	struct list *start=NULL;		//start is a pointer to struct list..
	struct list *Node=NULL, *ptr=NULL;
	char ch;
	do
	{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%s",Node->data);

		if(start==NULL)
			start=Node;
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

	PrintList(start);
	return 0;
}
