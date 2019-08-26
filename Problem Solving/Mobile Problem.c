#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct node
{
    int value;
    char str[10];
};

void getdata(struct node *Node,int n)
{
int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",&Node[i].str);
    }
}
void printdata(struct node *Node,int n)
{
int i=0;
    for(i=0;i<n;i++)
    {
        printf("%s   %d\n",Node[i].str,Node[i].value);
    }

}
void processdata(struct node *Node,int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
     int sn=strlen(Node[i].str);
     char b[sn],num[10]="\0";
     
     strcpy(b,Node[i].str);
     int j;
     for(j=0;j<sn;j++)
     {
       // printf("%c\n",b[j]);
       if(b[j]=='0')
       {
           strcat(num,"0");
       }
       if((b[j]=='a') || (b[j] == 'b') || (b[j]== 'c'))
       {
        strcat(num,"2");
       }
        if((b[j]=='d') || (b[j] == 'e') || (b[j]== 'f'))
       {
           strcat(num,"3");
       }
        if((b[j]=='g') || (b[j] == 'h') || (b[j]== 'i'))
       {
           strcat(num,"4");
       }
        if((b[j]=='j') || (b[j] =='k') || (b[j]=='l'))
       {
           strcat(num,"5");
       }
        if((b[j]=='m') || (b[j] == 'n') || (b[j]== 'o'))
       {
           strcat(num,"6");
       }
        if((b[j]=='p') || (b[j] == 'q') || (b[j]== 'r') || (b[j]=='s'))
       {
           strcat(num,"7");
       }
        if((b[j]=='t') || (b[j] == 'u') || (b[j]== 'v'))
       {
           strcat(num,"8");
       }
        if((b[j]=='w') || (b[j] == 'x') || (b[j]=='y') || (b[j]=='z'))
       {
           strcat(num,"9");
       }
       if(b[j]=='1')
       {
           strcat(num,"1");
       }
     }

    // printf("%s\n",num);
     Node[i].value=atoi(num);
    }

     struct node temp;
     for (i = 0; i < n; ++i)
     {
     	for (j = 0; j < n; ++j)
     	{
     		if(strcmp(Node[i].str,Node[j].str)<0)
     		{
     			temp=Node[i];
     			Node[i]=Node[j];
     			Node[j]=temp;
     		}
     	}
     }

}
int main()
{
    int n=4;
    struct node *Node=(struct node *)malloc(sizeof(struct node)*n);
    getdata(Node,n);
    processdata(Node,n);
    printdata(Node,n);

return 0;
}
