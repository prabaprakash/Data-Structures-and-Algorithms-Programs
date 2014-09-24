//hashing technique for storing student name and id
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int i;
    struct node*next;
}*start[5]={NULL};

struct node* NewNode()
{
        struct node* Node=NULL;
        Node=(struct node*)malloc(sizeof(struct node));
        Node->next=NULL;
        return Node;
}

void PrintList(struct node* ptr)
{
    while(ptr!=NULL)
        {
                printf("%d->",ptr->i);
                ptr=ptr->next;
        }
        printf("NULL\n");
}

int main()
{
        struct node *Node=NULL, *ptr[5]={NULL};
    char ch;
        int i,j;
        do
        {
                Node=NewNode();

                scanf("%d,%d",&i,&j);
                if(i==-1&&j==-1)
                break;
                if(start[i]==NULL)
                        start[i]=Node;
                else
                        ptr[i]->next=Node;

               Node->i=j;
               ptr[i]=Node;

        }while(1);

    for(i=0;i<5;i++)
    {
        printf("%d ->",i);
        PrintList(start[i]);
    }
}
