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
	Node->next=NULL;
	return Node;
}

void PrintList()
{
    struct list* ptr=start;
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void Deletion()
{
    struct list*save=NULL,*ptr=NULL;
    if(start==NULL){
        printf("List is empty.\n");
        return;
    }
    if(start->next==NULL){
        ptr=start;
        start=NULL;
        free(start);
        return;
    }
    ptr=start;
    while(1)
    {
        if(ptr->next==NULL)
            break;
        save=ptr;
        ptr=ptr->next;
    }
    save->next=NULL;
    free(ptr);
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

    printf("\n\nLinked List Before Deleting :");
    PrintList();
    Deletion();
    printf("\nLinked List After Deleting :");
	PrintList();
	return 0;
}
