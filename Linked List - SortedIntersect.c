//Given two lists sorted in increasing order, create and return a new list representing the
//intersection of the two lists.
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
void Push(struct node** headRef, int newData)
{
    struct node*newNode=NewNode();
    newNode->data=newData;
    newNode->next=*headRef;
    *headRef=newNode;
}
// This solution uses the temporary dummy to build up the result list
struct node* SortedIntersect(struct node* a, struct node* b)
{
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
    // Once one or the other list runs out -- we're done
    while (a!=NULL && b!=NULL)
    {
        if (a->data == b->data)
        {
            Push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data) { // advance the smaller list
            a = a->next;
        }
        else {
            b = b->next;
        }
    }
    return(dummy.next);
}
// This solution uses the local reference
struct node* SortedIntersect2(struct node* a, struct node* b)
{
    struct node* result = NULL;
    struct node** lastPtrRef = &result;
    // Advance comparing the first nodes in both lists.
    // When one or the other list runs out, we're done.
    while (a!=NULL && b!=NULL) {
        if (a->data == b->data) { // found a node for the intersection
            Push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a=a->next;
            b=b->next;
        }
        else if (a->data < b->data) { // advance the smaller list
            a=a->next;
        }
        else {
            b=b->next;
        }
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
    start=SortedIntersect(start1,start2);
    printf("\n\nMerged Linked list:\n");
	PrintList(start);

	return 0;
}
