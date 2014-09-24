#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};

struct node* NewNode()
{
	struct node* Node=NULL;
	Node=(struct node*)malloc(sizeof(struct node));
	Node->data=NULL;
	Node->next=NULL;
	return Node;
}

void PrintList(struct node *ptr)
{
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

//SortedMerge() Using Dummy Node
struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node dummy;
    struct node* result = &dummy;
    dummy.next=NULL;
    while(1)
    {
        if (a==NULL)
        {
            result->next=b;
            break;
        }
        else if (b==NULL)
        {
            result->next=a;
            break;
        }
        if (a->data <= b->data) {
            result->next = a;
            result=result->next;
            a=a->next;
        }
        else {
            result->next = b;
            result=result->next;
            b=b->next;
        }
    }
    return dummy.next;
}

int main()
{
	struct node *Node=NULL, *ptr=NULL;
    struct node *start=NULL,*start1=NULL,*start2=NULL;
	char ch;
	do
	{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%d",&Node->data);

		if(start1==NULL)
			start1=Node;
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

	printf("\nComplete Linked list:\n");
	PrintList(start1);

    do
	{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%d",&Node->data);

		if(start2==NULL)
			start2=Node;
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

	printf("\nComplete Linked list:\n");
	PrintList(start2);
    start=SortedMerge(start1,start2);
    printf("\n\nMerged Linked list:\n");
	PrintList(start);

	return 0;
}
