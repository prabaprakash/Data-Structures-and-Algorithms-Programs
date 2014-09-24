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
	Node->data=NULL;
	Node->next=NULL;
	Node->back=NULL;
	return Node;
}

struct list* insert(struct list* start, int position, int item)
{
      int count=1;
      struct list *node=NULL, *ptr=NULL, *save=NULL;
      node=NewNode();
      node->data=item;

      if(position < 1){
          printf("\n Invalid position");
          return start;
      }
      if(position == 1){
          node->next=start;
          if(start!=NULL)
               start->back=node;
          start=node;
          return start;
      }
      // if position > 1
      ptr=start;
      while(ptr!=NULL)
	  {
	      if(count>=position)
             break;
          save=ptr;
          ptr=ptr->next;
          count++;
      }
      if(ptr==NULL){    //insertion at the last
          save->next=node;
          node->back=save;
      }else{
          node->next=ptr;
          node->back=save;
          save->next=node;
          ptr->back=node;
      }
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
	struct list*start=NULL,*end=NULL;		//start is a pointer to struct list..
	struct list*Node=NULL,*ptr=NULL;
	char ch;
	int pos,item;
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

    printf("\n\nLinked List before Insetion :\n");
    PrintList(start);

    printf("\nEnter the position you want to insert :");
    scanf("%d",&pos);
    printf("\nEnter the item you want to insert :");
    scanf(" %d",&item);

    start=insert(start,pos,item);

    printf("\n\nLinked List after Deletion :\n");
    PrintList(start);

	return 0;
}
