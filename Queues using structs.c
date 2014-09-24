#include<stdio.h>
#include<stdlib.h>  //for exit() function
#define MAX 4

struct queue
{
    int front;
    int rear;
    int arr[MAX];
}*pt;

void DeQueue()
{
   if(IsEmpty())    //front==rear
   {
       printf("UnderFlow\nProgram Terminated\n");
       exit(EXIT_FAILURE);
   }
   pt->arr[pt->front]=NULL;
   pt->front=(pt->front+1)%MAX;
}

void EnQueue(int x)
{
    if(size()==MAX-1)
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    pt->arr[pt->rear]=x;
    pt->rear=(pt->rear+1)% MAX;
}

int front()
{
    if(IsEmpty()){
       printf("UnderFlow\nProgram Terminated\n");
       exit(EXIT_FAILURE);
    }
    return pt->arr[pt->front];
}

void NewADT()
{
    pt=(struct queue*)malloc(sizeof(struct queue));
    pt->front=0;
    pt->rear=0;
}

int size()
{
    return (MAX+(pt->rear-pt->front))%MAX;
}

int IsEmpty()
{
    return pt->front==pt->rear;
}

int main()
{
    NewADT();
    EnQueue(1);
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    EnQueue(2);
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    EnQueue(3);
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    DeQueue();
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    EnQueue(4);
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
//    EnQueue(5);
//    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    printf("size=%d\n",size());
    DeQueue();
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    DeQueue();
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    DeQueue();
    printf("front=%d, rear=%d\n",pt->front,pt->rear);
    printf("IsEmpty=%d\n",IsEmpty());

    return 0;
}
