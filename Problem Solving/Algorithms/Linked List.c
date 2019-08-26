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

struct list* Sorted(struct list *headA)
{
  struct list* nodeA ;
  int t,s=0;
   //struct node *lptr = NULL;

  do
  {
    s=0;
      nodeA=headA;
      while(nodeA->next != NULL)
      {
        if(nodeA->data > nodeA->next->data)
        {
             t=nodeA->data;

             nodeA->data=nodeA->next->data;

             nodeA->next->data=t;
             s=1;

        }
         nodeA=nodeA->next;
      }

  }
  while(s);
  return headA;
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

void swap(struct list* a,struct list* b)
    {
    int t;
    t=a->data;
    a->data=b->data;
    b->data=t;

}
struct list* Merge(struct list *headA,struct list* headB)
{
  struct list* fi=NewNode();
  struct list* temp=NULL;

    while(headA!=NULL && headB!=NULL)
    {
         if(headA->data <= headB->data)
         {
            fi->data=headA->data;
            fi->next=temp;
             headA=headA->next;
         }
        else
            {
             fi->data=headB->data;
            fi->next=temp;
             headB=headB->next;
        }
       temp=fi;
        fi=NewNode();
    }
    while(headA!=NULL)
        {
          fi->data=headA->data;
            fi->next=temp;
            temp=fi;
            fi=NewNode();
             headA=headA->next;
    }
    while(headB!=NULL)
        {
          fi->data=headB->data;
            fi->next=temp;
            temp=fi;
            fi=NewNode();
             headB=headB->next;
    }
    return temp;
}

struct list* MergeSort(struct list *headA,struct list* headB)
{
  struct list* fi=NULL;
  struct list* temp=NULL;
    struct list* fin=NewNode();
    while(headA!=NULL && headB!=NULL)
    {
         if(headA->data <= headB->data)
         {
             if(fi==NULL)
                 {
                 fi=NewNode();
                 fi->data=headA->data;
                 fin=fi;
             }
             else
                 {
                 	temp=NewNode();
            temp->data=headA->data;
            fi->next=temp;
            fi=fi->next;
             }
             headA=headA->next;
             
             
         }
        else
            {
             if(fi==NULL)
                 {
                 	 fi=NewNode();
                 fi->data=headB->data;
                  fin=fi;
             }
             else
                 {
                 	temp=NewNode();
                 	 temp->data=headB->data;
            fi->next=temp;
            fi=fi->next;
             }
             headB=headB->next;
             
            
        }
       //temp=fi;
       // fi=NewNode();
    }
    while(headA!=NULL)
        {
          temp=NewNode();
          temp->data=headA->data;
            fi->next=temp;
            fi=fi->next;
             headA=headA->next;
    }
    while(headB!=NULL)
        {
          temp=NewNode();
          temp->data=headB->data;
            fi->next=temp;
            fi=fi->next;
             headB=headB->next;
    }
    return fin;
}
struct list* RemoveDuplicates(struct list *he)
{
  struct list* head=(struct list*)malloc(sizeof(struct list));
  head=he;

  while(head!=NULL)
      {
          while(head->next!=NULL && head->data == head->next->data)
          {
          	//printf("%d\n",next->data);
               head->next=head->next->next;;

          }  
          head=head->next;
      }
       return he;
}

int main()
{
  struct list* Node1=NULL,*Node2=NULL, *ptr1=NULL,*ptr2=NULL;
	//Node=NewNode();
  int a[]={3,3,3,3,3};
  int b[]={7,4,2};
  int n=sizeof(a)/sizeof(a[0]);
  int o=sizeof(b)/sizeof(b[0]);

  int i,j;
  for (i = 0; i < n; ++i)
  {
  	ptr1=NewNode();
  	ptr1->data=a[i];
    ptr1->next=Node1;
    Node1=ptr1;
   }
   for (j = 0; j < o; ++j)
   {
    ptr2=NewNode();
  	ptr2->data=b[j];
    ptr2->next=Node2;
    Node2=ptr2;
   }
  //start=ptr;
   // printf("\nEnter the item you want insert node after :");
    //scanf("%d",&ch);

   // Insertion(ch);

    //printf("\n\n%d",CompareLists(ptr,ptr));
//  Sorted(start);

  //start=MergeSort(ptr1,ptr2);
   start=RemoveDuplicates(ptr1);
	PrintList();

	return 0;
}
