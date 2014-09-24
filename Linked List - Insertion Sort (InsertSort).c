//Write an InsertSort() function which given a list, rearranges its nodes so they are sorted in
//increasing order. It should use SortedInsert().
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

// given a list that is sorted in increasing order, and a single node,
// inserts the node into the correct sorted position in the list.
void SortedInsert(struct list** headRef, struct list* newNode)
{
    // Special case for the head end
    if (*headRef == NULL || (*headRef)->data>=newNode->data){
        newNode->next = *headRef;
        *headRef = newNode;
    }else{
        // Locate the node before the point of insertion
        struct list* current = *headRef;
        while (current->next!=NULL)
        {
            if(current->next->data>=newNode->data)
                break;
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    //no need for return Head pointer
}

void InsertSort(struct list** headRef)
{
    struct list* result = NULL; // build the answer here
    struct list* current = *headRef; // iterate over the original list
    struct list* next;

    while (current!=NULL) {
        next = current->next; // tricky - note the next pointer before we change it
        //SortedInsert() takes an existing node, and just rearranges pointers to insert it into the list
        SortedInsert(&result, current);
        current = next;
    }
    *headRef = result;
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

	printf("\nComplete Linked list Before Sorting :\n");
	PrintList();

    InsertSort(&start);

	printf("\nLinked list after Sorting:\n");
	PrintList();

	return 0;
}
