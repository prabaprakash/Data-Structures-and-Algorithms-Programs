#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list*next;
}*start=NULL;

struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=NULL;
	return Node;
}

void PrintList()
{
    struct list* ptr=start;
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void Insertion(int item)
{
    struct list*ptr=NULL,*temp=NULL;
    int i;
    if(start==NULL){
        printf("list is empty");
        return;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data!=item)
            ptr=ptr->next;
        else break;
    }
    if(ptr==NULL){
        printf("Item Not found\n");
        return;
    }
    printf("\nEnter the item you want to Insert :");
    scanf("%d",&i);

    temp=NewNode();
    temp->data=i;
    temp->next=ptr->next;
    ptr->next=temp;
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

    printf("\nEnter the item you want insert node after :");
    scanf("%d",&ch);

    Insertion(ch);

	PrintList();

	return 0;
}
