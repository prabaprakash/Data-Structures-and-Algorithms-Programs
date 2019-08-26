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
	Node->data=(int)NULL;
	Node->next=NULL;
	Node->back=NULL;
	return Node;
}
void PrintList(struct list* ptr)
{
	printf("\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
void PrintBackwards(struct list* ptr)
{
	printf("\nReverse Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->back;
	}
}
struct list* NewNod(int data)
{
    struct list* temp=(struct list*)malloc(sizeof(struct list));
    temp->data=data;
    temp->back=NULL;
    temp->next=NULL;
    return temp;
}
struct list* SortedInsert(struct list *head,int data)
{
  struct list* current=head,*prev=NULL;
  struct list* temp=NewNod(data);
  if(head==NULL)
      return temp;
  while(current!=NULL)
  {
     if(data <= current->data)
     {

      temp->next=current;
      if(current->back == NULL)
      {
       
      temp->back=current->back;
      current->back=temp;
      return temp;
      }
      else
      {
          current->back->next=temp;
          temp->back=current->back;
           current->back=temp;
          return head;
      }

     }
     prev=current;
     current=current->next;
  }
  prev->next=temp;
  temp->back=prev;
  return head;
}

int main()
{
	struct list*start=NULL,*end=NULL;		//start is a pointer to struct list..
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
 
	PrintList(SortedInsert(start,2));
   // PrintBackwards(start);

	return 0;
}
