#include<stdio.h>
#include<stdlib.h>

struct tree{
    int key;
    struct tree*left;
    struct tree*right;
}*root=NULL;

struct tree* NewNode(int item)
{
    struct tree*node=NULL;
    node=(struct tree*)malloc(sizeof(struct tree));
    node->key=item;
    node->left=NULL;
    node->right=NULL;
}

void insert(int x)
{
    struct tree*ptr=root,*PrevLoc=NULL;
    if(root==NULL){
        root=NewNode(x);
        return;
    }
    while(1)
    {
       PrevLoc=ptr;
       if(x<ptr->key)
          ptr=ptr->left;
       else
          ptr=ptr->right;
       if(ptr==NULL)break;
    }
    if(x<PrevLoc->key)
         PrevLoc->left=NewNode(x);
    else
         PrevLoc->right=NewNode(x);
}
int MinimumKey()
{
   struct tree* ptr=root;
   while(ptr->left!=NULL)
      ptr=ptr->left;
   return ptr->key;
}
int MaximumKey()
{
   struct tree* ptr=root;
   while(ptr->right!=NULL)
      ptr=ptr->right;
   return ptr->key;
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
    int item;
    printf("Enter The Keys to insert in Binary Tree :");
    printf("\nTo STOP, enter 0\n");
    do{
        scanf("%d",&item);
        if(item)
           insert(item);
    }while(item!=0);

    printf("\nTree contents :\n\n");

    printf("\n\n");
    show(root,0);

    printf("The Minimum key is %d\n",MinimumKey());
    printf("The Maximum key is %d\n",MaximumKey());

    return 0;
}
