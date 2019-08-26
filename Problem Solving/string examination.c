#include <stdio.h>

#include <string.h>
#include <malloc.h>
int main()
{
/*
	strlen returns the length of a given string
    strcmp compares two strings
    strncmp compares a certain amount of characters of two strings
    strchr finds the first occurrence of a character
    strrchr finds the last occurrence of a character
    strspn returns the length of the maximum initial segment that consists
of only the characters found in another byte string
    strcspn First matched character is at
   strpbrk finds the first location of any character in one string, in another string
   strstr finds the first occurrence of a substring of characters
   strtok finds the next token in a byte string
*/
   char a[100]="qwertyuiopasdfghjkelzxcvbnm";
   printf("%d\n",strlen(a));

   printf("%d\n",strcmp(a,"z"));

   printf("%d\n",strncmp(a,"qwa",3));

   printf("first occurrence of a character --> %s\n",strchr(a,'q'));

   printf("last occurrence of a character --> %s\n",strrchr(a,'e'));



  // strspn(find str, const str)
    char string_find[50] = "friend";
    char low_alpha[50]= "is where we love each other friend";
    printf("Length of initial segment matching  %d\n", strspn(string_find, low_alpha));

   const char str1[] = "Wonderful Life";
   const char str2[] = "Life";
   int len = strcspn(str1, str2);
   printf("First matched character is at %d\n", len );


   char *ret;
   ret = strpbrk(str1, str2);
   if(ret)
   {
      printf("First matching character: %c\n", *ret);
   }

   char s1 [] = "My House is small";
   printf ("Returned String 1: %s\n", strstr (s1, "is"));

   char *tok;
   tok= strtok(s1, " ");
    while (tok) {
        printf("Token: %s\n", tok);
        tok = strtok(NULL, " ");
    }

     // Carriage Return
     strcpy(s1,"MyHouseis small");
     s1[5]='\0';
    printf("%s\n",s1);

    // Substring  Substring

     strcpy(s1,"c programming");
     char *buf=(char *)calloc(1,50);
     strncpy(buf,&s1[2],14);
     printf("%s\n",buf);


   return 0;
}
