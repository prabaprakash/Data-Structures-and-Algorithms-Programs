 #include <stdio.h>
int main()
{

 unsigned int x=-3;  // Two Compliment

    printf("%u\n",x);
   for (int i = 1; i < 10; ++i)
   {
   int aaa=~i;  // sign bit - Flap bit 
   printf("Tilde of %d of %d\n",i,aaa);
   
}
return 0;
}