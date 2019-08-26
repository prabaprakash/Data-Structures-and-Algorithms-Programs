int cmpfunc(const void * a)
{
   int *i=&(*(int*)a); 
   return i[0];
}

int values[] = { 5, 20, 29, 32, 63 };

int main ()
{
     //void (*foo)(int);
    //foo = &my_int_func;
   int j= cmpfunc(values);
   printf("\n%d\n",j);
   //int * i, j, k; // is pointer
 // int *i, j, k; // is pointer other not
   printf("Hello, World!\n");
     int *i=(int *)malloc(2*sizeof(int));
     i[0]=454554;
     i[1]=435;
     i[2]=4886;
     i[4]=46777778;
     int *j=(int *)realloc(i,5*sizeof(int));
    printf("\n%d\n",j[4]);

}
