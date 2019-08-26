#include <stdio.h>
int fun(char *str1)
{
  char *str2 = str1;
  while(*++str1);
  return (str1-str2);
}
 
int main()
{
  char *str = "GeeksQuiz";
  printf("%d\n", fun(str));
  char c[] = "GATE2011"; 
char *p =c; 
printf("%s", p + p[3] - p[1]) ;
  return 0;
}