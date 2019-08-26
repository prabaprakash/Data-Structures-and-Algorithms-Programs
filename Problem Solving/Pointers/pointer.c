#include <stdio.h>

int main()
{
	int arri[] = {1, 2 ,3,4};
	int *ptri = arri;

	char arrc[] = {1, 2 ,3};
	char *ptrc = arrc;

	printf("sizeof arri[] = %d ", sizeof(arri));
	printf("sizeof ptri = %d ", sizeof(ptri));

	printf("sizeof arrc[] = %d ", sizeof(arrc));
	printf("sizeof ptrc = %d ", sizeof(ptrc));
    float a=1.2;
   printf("sizeof float %d\n", sizeof(a));
	return 0;
}
