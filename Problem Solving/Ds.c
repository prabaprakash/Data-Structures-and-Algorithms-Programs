1. Tree : Level Order Traversal
struct node
{
    int data;
    node* left;
    node* right;
}
void printtree(node* root,int i);

int height(node* root)
    {
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
        return l+1;
    else
        return r+1;
   
}
void LevelOrder(node * root)
{
  if(root==NULL)
      return ;
  int i=1;
    for(i=1;i<=height(root);i++)
    {
        printtree(root,i);    
    }
}
void printtree(node* root,int i)
    {
    if(root==NULL)
        return;
    if(i==1)
        printf("%d ",root->data);
    else
        {
        printtree(root->left,i-1);
        printtree(root->right,i-1);
    }
}
2. Tree: Height of a binary tree
int height(node* root)
    {
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
        return l+1;
    else
        return r+1;
   
}
3. Binary Search Tree : Insertion
node * NewNode(int data)
    {
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node * insert(node * root, int value)
{
   if(root==NULL)
       return NewNode(value);
   if(value > root->data)
   {
       root->right=insert(root->right,value);
   }
    else if(value < root->data)
        root->left=insert(root->left,value);
    return root;
}
4. Tree: Top View
void left_view(node* root)
{
    if(root==NULL)
     return;

    left_view(root->left);
       printf("%d ",root->data); 
}
void right_view(node* root)
{
    if(root==NULL)
     return;
      printf("%d ",root->data); 
    right_view(root->right);
     
}
void top_view(node * root)
{
    if(root==NULL)
        return;
    left_view(root->left);
    printf("%d ",root->data);
    right_view(root->right);
}
5. Tree: Height of a Binary Tree
int height(node * root)
{
  if (root==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = height(root->left);
       int rDepth = height(root->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}
6. Tree: Inorder Traversal
  void Inorder(node *root) {
    if(root==NULL)
        return;
   Inorder(root->left);
   printf("%d ",root->data);
   Inorder(root->right);
}
7. Tree: Postorder Traversal
void Postorder(node *root) {
    if(root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}
8. Tree: PreOrder Traversal
void Preorder(node *root) {
    if(root==NULL)
        return;
  printf("%d ",root->data);
  Preorder(root->left);
  Preorder(root->right);
}
9.Reverse a doubly Linked List
Node* Reverse(Node* head)
{
   struct Node *prev=(struct Node*)malloc(sizeof(struct Node));
    
    struct Node *temp=NULL;
    struct Node *current=head;
    
    while(current!=NULL)
    {
     temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        
        if(current->prev==NULL)
            return current;
        else
            current=current->prev;
        
    }
    if(temp!=NULL)
        return temp->prev;
    return head;
}
10. Insert a node in sorted doubly linked List

struct Node* NewNode(int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
Node* SortedInsert(Node *head,int data)
{
 struct Node* current=head,*prev=NULL;
  struct Node* temp=NewNode(data);
  if(head==NULL)
      return temp;
  while(current!=NULL)
  {
     if(data <= current->data)
     {

      temp->next=current;
      if(current->prev == NULL)
      {
       
      temp->prev=current->prev;
      current->prev=temp;
      return temp;
      }
      else
      {
          current->prev->next=temp;
          temp->prev=current->prev;
           current->prev=temp;
          return head;
      }

     }
     prev=current;
     current=current->next;
  }
  prev->next=temp;
  temp->prev=prev;
  return head;
}
11. Find Merge Point of Two Losts

int FindMergeNode(Node *headA, Node *headB)
{
  struct Node *save=(struct Node*)malloc(sizeof(struct Node));
    save=headB;
  while(headA!=NULL)
  {
      headB=save;
      while(headB!=NULL)
      {
        if(headA->data==headB->data)    
        {
            return headA->data;
        }
        headB=headB->next;
      }
      headA=headA->next;
      
  }
    return 0;
}
12. Detect Cycle
int HasCycle(Node* head)
{
   int count=1;
    while(head!=NULL && count<=100)
        {
        head=head->next;
    count++;
    }
    if(count>100)
        {
     return 1;
    }
    else
        return 0;
        
    
}
13. Linked List remove Duplicates
Node* RemoveDuplicates(Node *he)
{
   struct Node* head=(struct Node*)malloc(sizeof(struct Node));
  head=he;

  while(head!=NULL)
      {
          while(head->next!=NULL && head->data == head->next->data)
          {
          	//printf("%d\n",next->data);
               head->next=head->next->next;;

          }  
          head=head->next;
      }
       return he;
}
14. Get a Node value
int GetNode(Node *head,int pos)
{
 struct Node* current=head;
 struct Node* next;
 struct Node* previous=NULL;
    while(current!=NULL)
      {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    int i=0,value=0;
    while(i<=pos && previous!=NULL)
        {
        value=previous->data;
        previous=previous->next;
        i++;
    }
    return value;
  
}
15.Merge two sorted Linked List
struct Node* NewNode()
    {
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=0;
    n->next=NULL;
    return n;
}
void swap(struct Node* a,struct Node* b)
    {
    int t;
    t=a->data;
    a->data=b->data;
    b->data=t;
}
Node* MergeLists(Node *headA, Node* headB)
{
 struct Node* fi=NULL;
  struct Node* temp=NULL;
    struct Node* fin=NewNode();
    if(headA!=NULL)
        {
    while(headA!=NULL && headB!=NULL)
    {
         if(headA->data <= headB->data)
         {
             if(fi==NULL)
                 {
                 fi=NewNode();
                 fi->data=headA->data;
                 fin=fi;
             }
             else
                 {
                 	temp=NewNode();
            temp->data=headA->data;
            fi->next=temp;
            fi=fi->next;
             }
             headA=headA->next;
             
             
         }
        else
            {
             if(fi==NULL)
                 {
                 	 fi=NewNode();
                 fi->data=headB->data;
                  fin=fi;
             }
             else
                 {
                 	temp=NewNode();
                 	 temp->data=headB->data;
            fi->next=temp;
            fi=fi->next;
             }
             headB=headB->next;
             
            
        }
       //temp=fi;
       // fi=NewNode();
    }
    while(headA!=NULL)
        {
          temp=NewNode();
          temp->data=headA->data;
            fi->next=temp;
            fi=fi->next;
             headA=headA->next;
    }
    while(headB!=NULL)
        {
          temp=NewNode();
          temp->data=headB->data;
            fi->next=temp;
            fi=fi->next;
             headB=headB->next;
    }
        
    return fin;
    }
    else
        {
        return headB;
    }
}
16. Compare two Linked List
int CompareLists(Node *headA, Node* headB)
{
  struct Node *ca;
  struct Node *cb;
    ca=headA;
    cb=headB;
    int i=1;
  while(ca!=NULL && cb!=NULL)
  {
       if(ca->data!=cb->data)
          {
          i=0;
          break;
      }
      ca=ca->next;
      cb=cb->next;
     
  }
  if(cb!=NULL)  
      {
      return 0;
  }
  if(i )
      {
      return 1;
  }
    else
        {
        return 0;
    }
}
17.Reverse a Linked List
Node* Reverse(Node *head)
{
  Node *current=head;
    Node *previous=NULL;
    Node *next;
    while(current!=NULL)
    {
    next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    return previous;
}
17. BST Path Check
#include<stdio.h>
#include<stdlib.h>
#define bool int
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 
/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum.
 
 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
*/
bool hasPathSum(struct node* node, int sum)
{
  /* return true if we run out of tree and sum==0 */
  if (node == NULL)
  {
     return (sum == 0);
  }
  
  else
  {
    bool ans = 0;  
  
    /* otherwise check both subtrees */
    int subSum = sum - node->data;
  
    /* If we reach a leaf node and sum becomes 0 then return true*/
    if ( subSum == 0 && node->left == NULL && node->right == NULL )
      return 1;
  
    if(node->left)
      ans = ans || hasPathSum(node->left, subSum);
    if(node->right)
      ans = ans || hasPathSum(node->right, subSum);
  
    return ans;
  }
}
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
  int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);
 
  getchar();
  return 0;
}