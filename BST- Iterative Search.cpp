#include<stdio.h>
#include<stdlib.h>

struct tree{
    int key;
    struct tree*left;
    struct tree*right;
};

void insert(int x,struct tree* &p) //Using a reference parameter
{
    if(p==NULL)
    {
        p=(struct tree*)malloc(sizeof(struct tree));
        p->key=x;
        p->left=p->right=NULL;
    }
    else
       insert(x,(x<p->key)?p->left:p->right);
}

void Search(int item, struct tree* ptr)
{
    struct tree *PrevLoc=NULL;
    if(item==ptr->key){
        printf("Key %d is Root",item);
        return;
    }
    while(ptr!=NULL && item!=ptr->key)
    {
        PrevLoc=ptr;
        if(item<ptr->key)
            ptr=ptr->left;
        else ptr=ptr->right;
    }
    if(ptr==NULL){
        printf("Key Not found ");
        return;
    }
    if(item<PrevLoc->key)
        printf("The node with key %d is left node of node with key %d",item,PrevLoc->key);
    else printf("The node with key %d is right node of node with key %d",item,PrevLoc->key);
}

void show(const struct tree *p, int space)
{
    int i;
    if(p)
    {
        show(p->right,space+=6);
        printf("\n");
        for(i=0;i<space;i++)
            printf(" ");
        printf("%d ",p->key);
        printf("\n");
        show(p->left,space);
     }
}

int main()
{
    struct tree* root=NULL;
    int item;
    printf("Enter The Keys to insert in Binary Tree :");
    printf("\nTo STOP, enter 0\n");
    do{
        scanf("%d",&item);
        if(item)
           insert(item,root);
    }while(item!=0);

    printf("\nTree contents :\n\n");

    printf("\n\n");
    show(root,0);

    printf("\nEnter the element you want to search :");
    scanf("%d",&item);
    Search(item,root);

    return 0;
}
