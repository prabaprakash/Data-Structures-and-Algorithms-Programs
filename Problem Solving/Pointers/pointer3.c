#include<stdio.h> 
void swap(int *px, int *py) 
{ 
   *px = *px - *py; 
   *py = *px + *py; 
   *px = *py - *px; 
}
int main() 
{ 
	int bb=40,cc=20;
	swap(&bb,&cc);
	printf("%d\n",bb);
	

	
   int a; 
   char *x; 
   x = (char *) &a; 
  // printf("%s\n",x);

   a = 44; 
   x[0] = 1; 
   x[1] = 2; 
   printf("%d\n",a);   
   return 0; 
}