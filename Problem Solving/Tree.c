#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
Tree start;
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
} ;
typedef struct tree *Tree;


Tree NewNode(int data)
{
  Tree temp=(Tree)malloc(sizeof(struct tree));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
Tree insert(int data)
{
   Tree n=NewNode(data);
   Tree node=start;
   if(node==NULL)
   	return n;
   while(node!=NULL)
   {
   	node->next;
   }
}
int main() {
     insert(); 
     printf("%d\n",a->data);  
    return 0;
}
