#include<stdio.h>
#include<stdlib.h>

struct tree{
    int info;
    struct tree*left;
    struct tree*right;
};

void insert(struct tree** p, int x) //Manually create a call-by-reference using a pointer.
{
    if(*p==NULL)
    {
        (*p)=(struct tree*)malloc(sizeof(struct tree));
        (*p)->info=x;
        (*p)->left=(*p)->right=NULL;
    }
    else
       insert((x<(*p)->info)? &(*p)->left : &(*p)->right, x);
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
int max(int i,int j)
{
    return (i>j)?i:j;
}

/*  The function Compute the "height" of a tree. Height is the number f nodes
    along the longest path from the root node down to the farthest leaf node.*/

int height(struct tree * t)
{
    if (t == 0)
    {
       return 0;
    }
    else
    {
       return 1 + max(height(t->left),height(t->right));
    }
}

int diameter(struct tree * tree)
{
//    The diameter of a tree T is the largest of the following quantities:
//
//    1. The diameter of T’s left subtree
//    2. The diameter of T’s right subtree
//    3. The longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
//
    if (tree == 0) return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1, max(ldiameter,rdiameter));
}

int main()
{
    struct tree *root=NULL;
    int item;
    printf("Enter The Keys to insert in Binary Tree :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        if(item)
            insert(&root,item);
    }while(item!=0);

    printf("\nTree contents :\n\n");

    printf("\n\n");
    show(root,0);
    printf("height=%d\n",height(root));
    printf("diameter=%d",diameter(root));
    return 0;
}
