#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
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
struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node* result = NULL;
    // Base cases
    if (a==NULL) return(b);
    else if (b==NULL) return(a);
    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
    struct node* fast;
    struct node* slow;
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

void MergeSort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a;
    struct node* b;

    // Base case -- length 0 or 1
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplit(head, &a, &b); // Split head into 'a' and 'b' sublists
    // We could just as well use AlternatingSplit()
    MergeSort(&a); // Recursively sort the sublists
    MergeSort(&b);
    *headRef = SortedMerge(a, b); // answer = merge the two sorted lists together
}
int main()
{
	struct node *Node=NULL, *ptr=NULL;
    struct node *start=NULL;
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
    MergeSort(&start);
    printf("\n\nSorted Linked list:\n");
	PrintList(start);

	return 0;
}
