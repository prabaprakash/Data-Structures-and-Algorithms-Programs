//SortedInsert() function - Given a list that is sorted in increasing order, and a
//single node, inserts the node into the correct sorted position in the list.
#include<stdio.h>
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

// Uses special case code for the head end
void SortedInsert1(struct list** headRef, int item)
{
    struct list* newNode=NewNode();
    newNode->data=item;
    // Special case for the head end
    if (*headRef == NULL || (*headRef)->data>=item){
        newNode->next = *headRef;
        *headRef = newNode;
    }else{
        // Locate the node before the point of insertion
        struct list* current = *headRef;
        while (current->next!=NULL)
        {
            if(current->next->data>=item)
                break;
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    //no need for returning Head pointer
}

// Local references strategy for the head end
void SortedInsert2(struct list** headRef, int item)
{
    struct list* newNode=NewNode();
    newNode->data=item;

    struct list** currentRef = headRef;
    while (*currentRef!=NULL && (*currentRef)->data<item)
        currentRef = &((*currentRef)->next);

    newNode->next = *currentRef; // Bug: this line used to have an incorrect (*currRef)->next
    *currentRef = newNode;
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

		if(start==NULL)
			start=Node;
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

    printf("\nEnter the item you want insert :");
    scanf("%d",&ch);

	printf("\nComplete Linked list :\n");
	PrintList();

    //SortedInsert1(&start,ch);
    SortedInsert2(&start,ch);
	printf("\nLinked list after Insertion:\n");
	PrintList();

	return 0;
}
