#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list*next;
}*start;
struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=start;   //Note
	return Node;
}
void PrintList()
{
    struct list* ptr;
	printf("\nComplete Linked list :\n");
	printf("%d ",start->data);
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
	do{
		ptr=Node;
		Node=NewNode();

		printf("\nEnter data :");
		scanf("%d",&Node->data);

		if(start==NULL){
            start=Node;
         //   start->next=start;
		}
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');
   // Node->next=start;
	PrintList();
	return 0;
}
