#include<stdio.h>
#include<stdbool.h>
bool FindSolution(bool board[][8],int num_positioned)
{
	int row,col;
	if(num_positioned=8)
		{
			for (row = 0; row < 8; ++row)
	{
		for ( col = 0; col < 8; ++col)
		{
			if(board[row][col])
			{
				printf("1\t");
			}
			else
				printf("0\t");
		}
		printf("\n");
	}
	return true;
		}
	
	for ( row= 0; row < 8; ++row)
	{
		for (col = 0; col < 8; ++col)
		{
			if(!board[row][col])
			{
				board[row][col]=true;
				if(FindSolution(board,num_positioned+1))
					return true;
				board[row][col]=false;
			}
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	bool board[8][8];
	FindSolution(board,8);
	int row,col;
	
	return 0;
}