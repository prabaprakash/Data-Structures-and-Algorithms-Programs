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
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void Deletion(int item)
{
    struct list*save=NULL,*ptr=NULL;
    if(start==NULL){
        printf("list is empty");
        return;
    }
    if (start->data==item){
            ptr=start;
            start=start->next;
            free(ptr);
            return;
    }
    save=start;
    ptr=start->next;
    while(ptr!=NULL)
    {
        if (ptr->data==item)
        {
            save->next=ptr->next;
            free(ptr);
            return;
        }
        save=ptr;
        ptr=ptr->next;
    }
    printf("\nItem not found\n");
    return;
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

    printf("\n\nEnter the item you want to delete :");
    scanf("%d",&ch);

    Deletion(ch);

	PrintList();

	return 0;
}
