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
        p->left=NULL;
        p->right=NULL;
    }
    else
       insert(x,(x<p->key)?p->left:p->right);
}

struct tree* Search(int item, struct tree* &ptr)
{
    static struct tree *parent=NULL;
    if(ptr==NULL)
    {
        printf("\nKey not found");
        return NULL;
    }
    if(item==ptr->key)
    {
        if(parent==NULL)
            printf("\nKey Found at root of the tree.");
        return parent;
    }
    printf("%d ",ptr->key);
    parent=ptr;
    if(item<ptr->key)
        return Search(item,ptr->left);
    else return Search(item,ptr->right);
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
    struct tree *loc=Search(item,root);
    if(loc)
        printf("\nKey Found. Parent %d",loc->key);

    return 0;
}
