#include <stdio.h>
#include <malloc.h>
int** matrix(int s,int row,int col)
{
	int **matrix=(int **)malloc(row*col*sizeof(int *));
	int i,j;
	int count=4;
	//int p[4][4];
	for (i = 0; i < row; ++i)
	{
        matrix[i]=(int *)malloc(row*sizeof(int));
		for (j = 0; j< col; ++j)
		{
			matrix[i][j]=s++;
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}


	int **multiplication=(int **)malloc(col*row*sizeof(int *));
    int k;
	for (i = 0; i < row; ++i)
	{
		 multiplication[i]=(int*)malloc(row*col*sizeof(int));
         for(j=0;j<col;j++)
         {
         	   multiplication[i][j]=0;
	         	for(k=0;k<row;k++)
	         	{
	         	   multiplication[i][j]+=matrix[i][k]*matrix[k][j];
	         	}
	         	//printf("%d ", multiplication[i][j]);
         }
        // printf("\n");
    }
	
	for(i = 0; i < row; ++i)
	{
		for (j = 0; j< col; ++j)
		{
         printf("%d ",multiplication[i][j]);
		}
		printf("\n");
	}
	return matrix;
}
int main()
{
	int a;
	matrix(1,3,3);
	return 1;
}