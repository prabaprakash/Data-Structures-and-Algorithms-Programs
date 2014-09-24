#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list*next;
}*start;

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

static void Reverse(struct list** headRef)
{
    struct list* result = NULL;
    struct list* current = *headRef;
    struct list* next;
    while (current != NULL) {
        next = current->next; // tricky: note the next node
        current->next = result; // move the node onto the result
        result = current;
        current = next;
    }
    *headRef = result;
}

struct list* IterativeReverse()
{
    struct list*cur=NULL, *ptr1=NULL, *ptr2=NULL;
    cur=start;
    if(start->next)
        ptr1=cur->next;
    else
        return start;
    ptr2=ptr1->next;
    start->next=NULL;
    while(ptr2)
    {
        ptr1->next=cur;
        cur=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->next;
    }
    ptr1->next=cur;
    return ptr1;
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
	//Reverse(&start);
	start=IterativeReverse();
	printf("\nReverse Linked list :\n");
	PrintList(start);
	return 0;
}
