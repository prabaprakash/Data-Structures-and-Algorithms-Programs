#include<stdio.h>
#include<string.h>
//Time Complexity=O(m.n)//inefficient
//Space Comlexity=O(m+n)
int search(char* str1, char* str2, int m, int n)
{
    static int count=0,flag=0;
    int i;
    for(i=0;str2[i];i++)
        if(str1[i]!=str2[i]){
            break;
        }
    count++;
    if(str2[i]=='\0'){
        printf("Match Found at index %d\n",count-1);
        flag++;
        if(m>n)
            search(str1+1,str2,m-1,n);
    }
    else if(m>n)
        search(str1+1,str2,m-1,n);
    else if (!flag)
        printf("\nMatch does not found.\n");
}
int main()
{
    char str1[20],str2[10];
    printf("Enter String 1 :");
    gets(str1);
    printf("Enter String 2 :");
    gets(str2);
    search(str1,str2,strlen(str1),strlen(str2));
}
