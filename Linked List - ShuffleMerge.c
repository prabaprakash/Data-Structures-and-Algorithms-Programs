#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
}*start;

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
//SuffleMerge() — Dummy Node Not Using MoveNode()
void ShuffleMerge(struct node* a, struct node* b)
{
    struct node *ptr=NULL, *Node=NULL, *temp=NULL;
    int flag=0;
    while(1)
    {
        ptr=Node;
		Node=NewNode();

        if (a==NULL)
        {
            if(start==NULL)
                start=b;
            else
                ptr->next=b;
            break;
        }
        else if(b==NULL)
        {
             if(start==NULL)
                start=a;
            else
                ptr->next=a;
             break;
        }
        else
        {
            if(flag%2==0)
            {
                Node->data=a->data;
                temp=a;
                a=a->next;
                free(temp);
            }else{
                Node->data=b->data;
                temp=b;
                b=b->next;
                free(temp);
            }
            flag++;
            if(start==NULL)
                start=Node;
            else
                ptr->next=Node;
        }
    }
}
int main()
{
	struct node *Node=NULL, *ptr=NULL;
    struct node *start1=NULL,*start2=NULL;
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
    ShuffleMerge(start1,start2);
    printf("\n\nMerged Linked list:\n");
	PrintList(start);

	return 0;
}
