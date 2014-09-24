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

//SortedMerge() Using Recursion
//Merge() is one of those nice recursive problems where the recursive solution code is
//much cleaner than the iterative code. You probably wouldn't want to use the recursive
//version for production code however, because it will use stack space which is
//proportional to the length of the lists.
struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node* result = NULL;
    // Base cases
    if (a==NULL) return(b);
    else if (b==NULL) return(a);
    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        a->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        b->next = SortedMerge(a, b->next);
    }
    return(result);
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
