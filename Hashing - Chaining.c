//hashing technique for storing student name and id
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char* name;
    char* id;
    struct node*next;
}*start[5]={NULL};

struct node* NewNode()
{
	struct node* Node=NULL;
	Node=(struct node*)malloc(sizeof(struct node));
	Node->name=(char*)malloc(20);
	Node->id=(char*)malloc(10);
	Node->next=NULL;
	return Node;
}

void PrintList(struct node* ptr)
{
    if(ptr!=NULL)
        printf("\n\nComplete Linked list :\n");
    while(ptr!=NULL)
	{
		printf("%s\n",ptr->name);
		printf("%s\n",ptr->id);
		ptr=ptr->next;
	}
}

int CalculateHash(char *id)
{
    return (id[7]+id[8]+id[9]-144)%5;
}

struct node* Insert(struct node *start, char *key)
{
    char name[20];
    printf("Enter Student name :",name);
    scanf(" %[^\n]",name);
    struct node*Node=NewNode();
    Node->id=key;
    strcpy(Node->name,name);
    Node->next=start;
    start=Node;
    return start;
}

int main()
{
	struct node *Node=NULL, *ptr[5]={NULL};
    char ch;
	int i, index=0;
	printf("Enter data :");
	do
	{
		Node=NewNode();

		printf("\n\nEnter Student's name :");
		scanf(" %[^\n]",Node->name);
		//Notice the blank space preceding %[^\n] ,
		//to ignore any unwanted characters that may have been entered previously.
		printf("Enter Student's ID :");
		scanf(" %[^\n]",Node->id);
        index=CalculateHash(Node->id);// 0<=index<=4

		if(start[index]==NULL)
			start[index]=Node;
		else
			ptr[index]->next=Node;
        ptr[index]=Node;
		printf("Do you want to continue(Y/N)");

	}while(toupper((ch=getch()))!='N');

    for(i=0;i<5;i++)
        PrintList(start[i]);

    char key[10],name[20];
    printf("Enter the key You want to search for :");
    scanf("%s",key);
    index=CalculateHash(key);
    struct node* pt=start[index];
    //printf("\n%s",pt->name);
    while(pt){
        if(strcmp(pt->id,key)==0)
        {
            printf("Name :%s\n",pt->name);
            break;
        }
        pt=pt->next;
    }
    if(pt==NULL)
        printf("\nRecord Not found");

    printf("\nEnter the key You want to insert :");
    scanf(" %[^\n]",key);

    printf("Enter Student name :",name);
    scanf(" %[^\n]",name);
    index=CalculateHash(key);
    Node=NewNode();
    strcpy(Node->id,key);
    strcpy(Node->name,name);
    ptr[index]->next=Node;

//    start[index]=Insert(start[index],key);  //Insert at the Beginning

    for(i=0;i<5;i++)
        PrintList(start[i]);
	return 0;
}
