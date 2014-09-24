#include<stdio.h>
#include<stdlib.h>

struct tree{
    int key;
    struct tree*parent;
    struct tree*left;
    struct tree*right;
}*root=NULL;

struct tree* NewNode(int item)
{
    struct tree*node=NULL;
    node=(struct tree*)malloc(sizeof(struct tree));
    node->key=item;
    node->parent=NULL;
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
    if(x<PrevLoc->key){
        PrevLoc->left=NewNode(x);
        PrevLoc->left->parent=PrevLoc;
    }else{
        PrevLoc->right=NewNode(x);
        PrevLoc->right->parent=PrevLoc;
    }
}

struct tree* MinimumKey(struct tree*ptr)
{
   while(ptr->left!=NULL)
      ptr=ptr->left;
   return ptr;
}
struct tree* MaximumKey(struct tree*ptr)
{
   while(ptr->right!=NULL)
      ptr=ptr->right;
   return ptr;
}
struct tree* Successor(struct tree*ptr)//given pointer to the node
{
    if(ptr->right)
        return MinimumKey(ptr->right);
    struct tree*pt=ptr->parent;
    while(pt!=NULL)
    {
        if(ptr==pt->left)
            break;
        ptr=pt;
        pt=pt->parent;
    }
    if(pt==NULL)//for maximum key
        return NULL;
    return pt;
}
struct tree* Predecessor(struct tree*ptr)
{
    if(ptr->left)
        return MaximumKey(ptr->left);
    struct tree*pt=ptr->parent;
    while(pt!=NULL)
    {
        if(ptr==pt->right)
            break;
        ptr=pt;
        pt=pt->parent;
    }
    if(pt==NULL)//for maximum key
        return NULL;
    return pt;
}

struct tree* Search(int item, struct tree* ptr)
{
    struct tree*PrevLoc=NULL;
    if(item==ptr->key){
        return Predecessor(ptr);
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
        return NULL;
    }
    return Predecessor(ptr);
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
    struct tree *loc=NULL;
    while(1)
    {
        printf("Enter item :");
        scanf("%d",&item);
        loc=Search(item,root);
        if(loc)
            printf("Predecessor %d\n",loc->key);
        else printf("Predecessor %s\n","NULL");
    }
    return 0;
}
