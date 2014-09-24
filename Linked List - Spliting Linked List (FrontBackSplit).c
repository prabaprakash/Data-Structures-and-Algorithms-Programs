//Given a list, split it into two sublists — one for the front half, and one for the back half. If
//the number of elements is odd, the extra element should go in the front list.
#include<stdio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list*next;
};

struct list* NewNode()
{
	struct list* Node=NULL;
	Node=(struct list*)malloc(sizeof(struct list));
	Node->data=NULL;
	Node->next=NULL;
	return Node;
}

void PrintList(struct list *ptr)
{
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
int Length(struct list *ptr)
{
    int count=0;
    while(ptr!=NULL)
	{
		ptr=ptr->next;
		count++;
	}
	return count;
}
// Uses the "count the nodes" strategy
void FrontBackSplit(struct list* source, struct list** frontRef, struct list** backRef)
{
    int len=Length(source);
    int i;
    struct list* current = source;
    if(len<2){
        *frontRef = source;
        *backRef = NULL;
    }else{
        int hopCount = (len-1)/2; //(figured these with a few drawings)
        for(i=0;i<hopCount;i++)
            current = current->next;
        // Now cut at current
        *frontRef = source;
        *backRef = current->next;
        current->next = NULL;
    }
}

// Uses the fast/slow pointer strategy
void FrontBackSplit2(struct list* source, struct list** frontRef, struct list** backRef)
{
    struct list* fast;
    struct list* slow;
    if (source==NULL || source->next==NULL){ // length < 2 cases
        *frontRef = source;
        *backRef = NULL;
    }else{
        slow = source;
        fast = source->next;
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL){
            fast = fast->next;
            if (fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        // 'slow' is before the midpoint in the list, so split it in two at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

int main()
{
	struct list *Node=NULL, *ptr=NULL;
    struct list*start=NULL,*Front=NULL,*Rear=NULL;
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

	printf("\nComplete Linked list:\n");
	PrintList(start);

    FrontBackSplit(start,&Front,&Rear);

	printf("\nFront :");
	PrintList(Front);
	printf("\nRear :");
	PrintList(Rear);

	return 0;
}
