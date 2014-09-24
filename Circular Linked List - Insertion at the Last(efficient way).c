#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list*next;
}*start=NULL;

struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=start;
	return Node;
}

void Insert_last(int item)
{
    struct list*node=NULL;
    if(start==NULL){
        start=NewNode();
        start->data=item;
        start->next=start;
        return ;
    }
    node=NewNode();
    node->data=start->data;
    node->next=start->next;
    start->next=node;
    start->data=item;
    start=node;
    return;
}

void PrintList()
{
    struct list*ptr;
	if(start!=NULL)
        printf("%d ",start->data);
    else return;
	ptr=start->next;
    while(ptr!=start)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	struct list*Node=NULL,*ptr=NULL;
	char ch;
	int item;
	do
	{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%d",&Node->data);

		if(start==NULL){
            start=Node;
            start->next=start;
		}
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');
    printf("\nOriginal Linked List :");
    PrintList();
    printf("\n\nEnter the item to be Inserted :");
    scanf("%d",&item);
    Insert_last(item);
    printf("\n\nLinked List After Inserting :");
	PrintList();

	return 0;
}
