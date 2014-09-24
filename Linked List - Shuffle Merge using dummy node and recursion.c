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
//SuffleMerge() —By Using Dummy Node
struct node* ShuffleMerge1(struct node* a, struct node* b) {
    struct node dummy;
    struct node*tail=&dummy;
    dummy.next=NULL;
    while(1){
        if (a==NULL) { // empty list cases
            tail->next = b;
            break;
        }
        else if(b==NULL){
            tail->next = a;
            break;
        }
        else{ // common case: move two nodes to tail
            tail->next = a;
            tail = a;
            a = a->next;
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    return(dummy.next);
}

//SuffleMerge() — Recursive
//The recursive solution is the most compact of all, but is probably not appropriate for
//production code since it uses stack space proportionate to the lengths of the lists.
struct node* ShuffleMerge2(struct node* a, struct node* b)
{
    struct node* result;
    struct node* recur;

    if (a==NULL) return(b); // see if either list is empty
    else if (b==NULL) return(a);
    else {
        // it turns out to be convenient to do the recursive call first --
        // otherwise a->next and b->next need temporary storage.
        recur = ShuffleMerge2(a->next, b->next);
        result = a; // one node from a
        a->next = b; // one from b
        b->next = recur; // then the rest
        return(result);
    }
}

int main()
{
	struct node *Node=NULL, *ptr=NULL;
    struct node *start=NULL,*start1=NULL,*start2=NULL;
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
    start=ShuffleMerge2(start1,start2);
    printf("\n\nMerged Linked list:\n");
	PrintList(start);

	return 0;
}
