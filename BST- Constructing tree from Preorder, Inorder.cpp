#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree{
    char key;
    struct tree*left;
    struct tree*right;
};

void insert(char x,struct tree* &p,int bit) //Using a reference parameter
{
    if(p==NULL)
    {
        p=(struct tree*)malloc(sizeof(struct tree));
        p->key=x;
        p->left=p->right=NULL;
    }
    else
       insert(x,bit?p->right:p->left,bit);
}

void show(const struct tree *p, int space)
{
    int i;
    if(p){
        show(p->right,space+=6);
        printf("\n");
        for(i=0;i<space;i++)
            printf(" ");
        printf("%c ",p->key);
        printf("\n");
        show(p->left,space);
     }
}

void Find(char* preorder,char* inorder,struct tree* ptr)
{
    char root=NULL;
    char preleft[10]={},preright[10]={},inleft[10]={},inright[10]={};
    if(strlen(preorder)==0){return;}
    root=preorder[0];
    int pos=strchr(inorder,root)-inorder;
    for(int i=0;i<pos;i++)
        inleft[i]=inorder[i];
    for(int i=pos+1;inorder[i]!='\0';i++)
        inright[i-pos-1]=inorder[i];
    for(int i=0;i<pos;i++)
        preleft[i]=preorder[i+1];
    for(int i=pos+1;preorder[i]!='\0';i++)
        preright[i-pos-1]=preorder[i];
    char child1,child2;
    child1=preleft[0];
    child2=preright[0];
    insert(child1,ptr,0);
    insert(child2,ptr,1);
    printf("%10s %10s %c %10s %10s %10s %10s\n",preorder,inorder,root,preleft,preright,inleft,inright);
    Find(preleft,inleft,ptr->left);
    Find(preright,inright,ptr->right);
}

int main()
{
    struct tree* root=NULL;
    int item;
    char inorder[10]={};
    char preorder[10]={};
    printf("Enter Preorder Traversal :");
    scanf("%s",preorder);
    printf("Enter Inorder Traversal :");
    scanf("%s",inorder);
    insert(preorder[0],root,1);
    Find(preorder,inorder,root);
    show(root,0);
    return 0;
}
