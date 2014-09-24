#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list*next;
	struct list*back;
}*start=NULL,*end=NULL;

struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=NULL;
	Node->back=NULL;
	return Node;
}
struct list* deletion()
{
    struct list *node;
    if(start->next==NULL)
    {
        free(start);
        start=NULL;
        end=NULL;
        printf("\nLinked List after Deletion :\nNULL\n");
        return;
    }
    node=start->next;
    start->next->back=NULL;
    free(start);
    start=node;
    printf("\nLinked List after Deletion :\n");
    PrintList(start);
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
		else{
            ptr->next=Node;
			Node->back=ptr;
        }
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');
    end=Node;
    printf("\n\nLinked List before Deletion :\n");
    PrintList(start);
    start=deletion(start);

	return 0;
}
