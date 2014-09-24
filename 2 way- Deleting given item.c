#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list*next;
	struct list*back;
};
struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=NULL;
	Node->back=NULL;
	return Node;
}
struct list * deletion(struct list*start,int item)
{
    struct list*ptr=NULL;
	if(start->data==item)
	{
		ptr=start->next;
		if(start->next)
            start->next->back=NULL;
		free(start);
		start=ptr;
		return start;
	}
	ptr=start;
	while(ptr!=NULL)
	{
		if (ptr->data==item)
		{
			if(ptr->next!=NULL)
			ptr->next->back=ptr->back;

			if(ptr->back!=NULL)
			ptr->back->next=ptr->next;

			free(ptr);
			return start;
		}
		ptr=ptr->next;
	}
	printf("\nItem not found\n");
	return start;
}
void PrintList(struct list* ptr)
{
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
int main()
{
	struct list*start=NULL,*end=NULL;		//start is a pointer to struct list..
	struct list*Node=NULL,*ptr=NULL;
	char ch;int item;
	do
	{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%d",&Node->data);

		if(start==NULL)
			start=Node;
		else{
            ptr->next=Node;
			Node->back=ptr;
        }
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');
    end=Node;

    printf("\n\nLinked List before Deletion :\n");
    PrintList(start);

    printf("\nEnter the item you want to delete ");
    scanf("%d",&item);

    start=deletion(start,item);

    printf("\n\nLinked List after Deletion :\n");
    PrintList(start);

	return 0;
}
