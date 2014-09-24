//hashing technique for storing student name and id
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n;
struct node
{
    int vertex;
    struct edges*next;
};
struct edges
{
    int vertex;
    int weight;
    struct edges*next;
};
struct edges* NewNode()
{
        struct edges* Node=NULL;
        Node=(struct edges*)malloc(sizeof(struct edges));
        Node->next=NULL;
        return Node;
}

void PrintList(struct edges* ptr)
{
    while(ptr!=NULL)
        {
                printf("%d(%d)->",ptr->vertex,ptr->weight);
                ptr=ptr->next;
        }
        printf("NULL\n");
}

int main()
{
        struct edges *Node=NULL;
        char ch;
        int i,j,weight;
        scanf("%d %d",&n,&m);
        if(n<=0||n>=200000)
            exit(EXIT_FAILURE);
        if(m<=0||m>=200000)
            exit(EXIT_FAILURE);
        struct node *start[n];
        struct edges *ptr[n];
        for(i=0;i<n;i++)
        {
            start[i]=NULL;
            ptr[i]=NULL;
        }
        int k;
        for(k=0;k<m;k++)
        {
                scanf("%d %d %d",&i,&j,&weight);
                if(i<=0||i>=200000)
                    exit(EXIT_FAILURE);
                if(j<=0||j>=200000)
                    exit(EXIT_FAILURE);
                Node=NewNode();
                if(start[i]==NULL)
                        start[i]=(struct node*)Node;
                else
                        ptr[i]->next=Node;

                Node->vertex=j;
                Node->weight=weight;
                ptr[i]=Node;

                Node=NewNode();
                if(start[j]==NULL)
                        start[j]=(struct node*)Node;
                else
                        ptr[j]->next=Node;

               Node->vertex=i;
               Node->weight=weight;
               ptr[j]=Node;
        }

    for(i=0;i<n;i++)
    {
        printf("%d ->",i);
        PrintList((struct edges*)start[i]);
    }
    return 0;
}
