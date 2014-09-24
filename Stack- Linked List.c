#include<stdio.h>
#include<stdlib.h>

struct list{
    int info;
    struct list*next;
}*top=NULL,*ptr=NULL;

struct list* newnode()
{
    struct list* node;
    node=(struct list*)malloc(sizeof(struct list));
    return node;
}

int pop()   //remove at the beginning
{
    int item;
    if(top==NULL)
    {
       printf("\nStack Underflow");
       exit(1);
    }
    item=top->info;
    top=top->next;
    return item;
}

void push(int item) //insert at the beginning
{
    struct list* node=newnode();
    if(!node){
        printf("\nHeap Overflow");
        exit(1);
    }
    node->info=item;
    node->next=top;
    top=node;
}

void print()
{
    printf("\n");
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    ptr=top;
    while(ptr->next!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d",ptr->info);
    return;
}

int main()
{
    int data;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter ur choice:");
        switch(getch())
        {
        case '1':
             printf("\nEnter a item you want to insert :");
             scanf("%d",&data);
             push(data);
             break;
        case '2':
             printf("\nThe popped element is %d",pop());
             break;
        case '3':
             print();
             break;
        case '4':
             exit(0);
             break;
        default:
             printf("\nEnter a valid choice");
        }
    }
    return 0;
}
