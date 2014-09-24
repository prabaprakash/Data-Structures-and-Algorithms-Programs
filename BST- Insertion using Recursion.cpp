#include<stdio.h>
#include<stdlib.h>

struct tree{
    int info;
    struct tree*left;
    struct tree*right;
};

void insert(int x,struct tree* &p) //Using a reference parameter
{
    if(p==NULL)
    {
        p=(struct tree*)malloc(sizeof(struct tree));
        p->info=x;
        p->left=p->right=NULL;
    }
    else
       insert(x,(x<p->info)?p->left:p->right);
}

void show(const struct tree *p, int space)
{
    int i;
    if(p){
        show(p->right,space+=6);
        printf("\n");
        for(i=0;i<space;i++)
            printf(" ");
        printf("%d ",p->info);
        printf("\n");
        show(p->left,space);
     }
}

int main()
{
    struct tree* root=NULL;
    int item;
    printf("Enter The Keys to insert in Binary Tree :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        if(item)
           insert(item,root);
    }while(item!=0);

    printf("\nTree contents :\n\n");

    printf("\n\n");
    show(root,0);

    return 0;
}
