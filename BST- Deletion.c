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

struct tree* MaximumKey(struct tree*ptr)
{
   while(ptr->right!=NULL)
      ptr=ptr->right;
   return ptr;
}

void Deletion(int item)
{
    struct tree*PrevLoc=NULL;
    struct tree*ptr=root;
    //search for the item
    while(ptr!=NULL)
    {
        if(item==ptr->key)
            break;
        PrevLoc=ptr;
        if(item<ptr->key)
            ptr=ptr->left;
        else ptr=ptr->right;
    }
    if(ptr==NULL){
        printf("Key Not found ");
        return;
    }
    //tree has one node i.e. root node
    if(PrevLoc==NULL && ptr==root)
    {
        if(root->left==NULL && root->right==NULL){
            root=NULL;
            free(ptr);
            return;
        }
    }
    //has no children
    if(ptr->left==NULL&&ptr->right==NULL)
    {
        if(ptr==PrevLoc->left){
            PrevLoc->left=NULL;
        }else{
            PrevLoc->right=NULL;
        }
        free(ptr);
        return;
    }
    if(ptr->left==NULL&&ptr->right!=NULL)
    {
        if(ptr!=root)
        {
            if(ptr==PrevLoc->left){
                PrevLoc->left=ptr->right;
            }else{
                PrevLoc->right=ptr->right;
            }
            free(ptr);
            return;
        }
        else
        {
            root=ptr->right;
            free(ptr);
            return;
        }
    }
    if(ptr->left!=NULL&&ptr->right==NULL)
    {
        if(ptr!=root)
        {
            if(ptr==PrevLoc->left){
                PrevLoc->left=ptr->left;
            }else{
                PrevLoc->right=ptr->left;
            }
            free(ptr);
            return;
        }
        else
        {
            root=ptr->left;
            free(ptr);
            return;
        }
    }
    //node has two children
    struct tree*Predecessor=MaximumKey(ptr->left);//largest element in the left subtree(case: 1)
    int temp=Predecessor->key;
    Deletion(Predecessor->key);//predecessor can have atmost one child(left)
    ptr->key=temp;
    return;
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
    while(1)
    {
        printf("Enter item :");
        scanf("%d",&item);
        Deletion(item);
        if(root) show(root,0);
        else break;
    }
    return 0;
}
