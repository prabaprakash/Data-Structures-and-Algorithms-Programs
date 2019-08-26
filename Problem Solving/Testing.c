#include<stdio.h>
void fun(int *p)
{
 int q=10;
 p=&q;
}
int main()
{
  //Test 1
  char *s[] = { "knowledge","is","power"};
  char **p;
  p = s;
  printf("%s ", ++*p);
  printf("%s ", *p++);
  printf("%s ", ++*p);
  int a=~4;
  printf("%i",~4);
  //Test 2
  int b[]={1,2,3};
  printf("%d\n",b+3);
  //Test 3
  int aa[] = {1, 2, 3, 4, 5, 6}; 
  int *ptr = (int*)(&aa+1); 
  printf("%d ", *(ptr-1)); 

  //Test 4
    int r = 20;
  int *p = &r;
  fun(p);
  printf("%d", *p);
  return 0;
    return 0; 

}
