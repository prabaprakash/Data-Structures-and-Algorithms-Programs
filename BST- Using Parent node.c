#include<stdio.h>
#include<stdlib.h>

struct tree{
    char*id;
    char*name;
    struct tree*parent;
    struct tree*left;
    struct tree*right;
}*root=NULL;

struct tree* NewNode(const char* id,const char*name)
{
    struct tree*node=NULL;
    node=(struct tree*)malloc(sizeof(struct tree));
    node->id=(char*)malloc(10*sizeof(char));
    strcpy(node->id,id);
    node->name=(char*)malloc(20*sizeof(char));
    strcpy(node->name,name);
    node->parent=NULL;
    node->left=NULL;
    node->right=NULL;
}

void insert(char*id,char *name)
{
    struct tree*ptr=root,*PrevLoc=NULL;
    if(root==NULL){
        root=NewNode(id,name);
        return;
    }
    while(1)
    {
       PrevLoc=ptr;
       if(strcmp(id,ptr->id)<0)
          ptr=ptr->left;
       else
          ptr=ptr->right;
       if(ptr==NULL)break;
    }
    if(strcmp(id,PrevLoc->id)<0){
        PrevLoc->left=NewNode(id,name);
        PrevLoc->left->parent=PrevLoc;
    }else{
        PrevLoc->right=NewNode(id,name);
        PrevLoc->right->parent=PrevLoc;
    }
}

void show(const struct tree *p, int space)
{
    int i;
    if(p){
        show(p->right,space+=6);
        printf("\n");
        for(i=0;i<space;i++)
            printf(" ");
        printf("%s\n",p->id);
        for(i=0;i<space;i++)
            printf(" ");
        if(p->parent)
            printf("%s %s",p->name,p->parent->id);
        else printf("%s %s",p->name,"NULL");

        printf("\n");
        show(p->left,space);
     }
}

int main()
{
    char id[10];
    char name[20];
    printf("Enter The ID and Name to insert in Binary Tree :");
    printf("\nTo STOP, Type \"END\" and NULL\n\n");
    do{
        scanf("%s %[^\n]",id,name);
        if(strcmp(id,"END"))
            insert(id,name);
        else break;
    }while(1);

    printf("\nTree contents :\n\n");

    printf("\n\n");
    show(root,0);

    return 0;
}
