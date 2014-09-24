#include<stdio.h>
#include<stdlib.h>  //for exit() function
#define MAX 2

struct stack
{
    int top;
    int arr[MAX];
}*pt;

int pop()
{
   int elem;
   if(pt->top==-1)
   {
       printf("UnderFlow\nProgram Terminated\n");
       exit(EXIT_FAILURE);
   }
   elem=pt->arr[pt->top];
   pt->arr[pt->top--]=NULL;
   return elem;
   //pointer to structure member have more precedence than any unary operator
}
void push(int x)
{
    if(pt->top==MAX-1)
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    pt->arr[++pt->top]=x;
}
int peek()
{
    if(pt->top<=MAX-1||pt->top>=0)
        return pt->arr[pt->top];
    else exit(EXIT_FAILURE);
}
void NewADT()
{
    pt=(struct stack*)malloc(sizeof(struct stack));
    pt->top=-1;
}
int size()
{
    return pt->top+1;
}
int IsEmpty()
{
    if(pt->top==-1)
        return 1;
    else return 0;
}
int main()
{
    NewADT();
   // printf("isempty=%d\n",IsEmpty());
    push(1);
    //printf("%d\n",size());
    printf("top=%d\n",pt->top);
    push(2);
    //printf("%d\n",peek());
    printf("top=%d\n",pt->top);
    //push(3);
    //printf("%d\n",peek());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("isempty=%d\n",IsEmpty());
    //printf("%d",pt->top);
    pop();
    // printf("%d\n",peek());

    return 0;
}
