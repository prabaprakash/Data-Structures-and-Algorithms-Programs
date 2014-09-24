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

struct list* IterativeReverse(int k)
{
    struct list*cur=NULL, *ptr1=NULL, *ptr2=NULL;
    cur=start;
    if(start->next)
        ptr1=cur->next;
    else    //if linked list contains only one node.
        return start;
    ptr2=ptr1->next;//can be NULL in the beginning itself.

    struct list*temp=cur;
    k=k-1;
    while(--k)
    {
        ptr1->next=cur;
        cur=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->next;
        if(!ptr2) break;    //if k exceeds its no of nodes.
    }
    ptr1->next=cur;
    temp->next=ptr2;
    start=ptr1;
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
	int k;
   	printf("Enter value for k :");
	scanf("%d",&k);
	start=IterativeReverse(k);
	printf("\nReverse Linked list :\n");
	PrintList(start);

	return 0;
}
