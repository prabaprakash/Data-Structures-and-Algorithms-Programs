#include<stdio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list*next;
	struct list*back;
};
struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=NULL;
	Node->back=NULL;
	return Node;
}
void PrintList(struct list* ptr)
{
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
void PrintBackwards(struct list* ptr)
{
	printf("\nReverse Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->back;
	}
}
int main()
{
	struct list*start=NULL,*end=NULL;		//start is a pointer to struct list..
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
		else{
            ptr->next=Node;
			Node->back=ptr;
        }
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');
    end=Node;

	PrintList(start);
    PrintBackwards(end);

	return 0;
}
