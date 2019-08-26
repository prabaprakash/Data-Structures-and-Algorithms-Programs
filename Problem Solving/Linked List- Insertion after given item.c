#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
struct list
{
	int data;
	struct list*next;
}*start=NULL;

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
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void Insertion(int item)
{
    struct list*ptr=NULL,*temp=NULL;
    int i;
    if(start==NULL){
        printf("list is empty");
        return;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data!=item)
            ptr=ptr->next;
        else break;
    }
    if(ptr==NULL){
        printf("Item Not found\n");
        return;
    }
    printf("\nEnter the item you want to Insert :");
    scanf("%d",&i);

    temp=NewNode();
    temp->data=i;
    temp->next=ptr->next;
    ptr->next=temp;
}
struct list* MergeList(struct list *headA,struct list *headB)
{
    struct list* current=headA;
    struct list* ne;

    while(current!=NULL){
        if(current->next == NULL)
        {
            ne=current;
        }
        current=current->next;
    }
    ne->next=headB;
    return headA;
};

int CompareLists(struct list *headA,struct list *headB)
{
  struct list *ca;
  struct list *cb;
    ca=headA;
    cb=headB;
    int i=0;
  while(ca!=NULL && cb!=NULL)
  {
      ca=ca->next;
      cb=cb->next;
      if(ca->data!=cb->data)
          {
          i=0;
          break;
      }
  }
  if(cb!=NULL)
  {
    return 0;
  }
  if(i)
      {
      return 1;
  }
    else
        {
        return 0;
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
		else
			ptr->next=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

    printf("\nEnter the item you want insert node after :");
    scanf("%d",&ch);

    Insertion(ch);

    //printf("\n\n%d",CompareLists(ptr,ptr));
    start=MergeList(start,start);
	PrintList();

	return 0;
}
