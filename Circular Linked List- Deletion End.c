#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list*next;
}*start=NULL;

struct list* NewNode()
{
	struct list *Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=start;
	return Node;
}

void del_last()
{
    struct list *ptr=NULL, *save=NULL;
    if(start==NULL){
        printf("list is empty");
        return ;
    }
    if(start->next==start)
    {
       free(start);
       start=NULL;
       return;
    }
    save=start;
    ptr=start->next;

    while(ptr->next!=start)
    {
        save=ptr;
        ptr=ptr->next;
    }
    save->next=start;
    free(ptr);
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
	struct list *Node=NULL, *ptr=NULL;
	char ch;
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

    printf("\nLinked List Before Deleting :");
    PrintList();

    del_last();

    printf("\nLinked List After Deleting :");
	PrintList();
	return 0;
}
