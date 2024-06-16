// Online C compiler to run C program online
// Online C compiler to run C program online
#include <stdio.h>

#define SIZE 10
#define EMPTY '.'
#define QUEEN 'Q'
#define INVALID 'x'

void	copy_board(char board_cp[][SIZE], char board[][SIZE])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			board_cp[i][j] = board[i][j];
			j++;
		}
		i++;
	}
}

void	mark_square_invalid(int row, int col, char board[][SIZE])
{
	int	i;
	int	j;

	j = col;
	i = row + 1;
	while (i < SIZE)
		board[i++][j] = INVALID;
	i = row + 1;
	j = col + 1;
	while (i < SIZE && j < SIZE)
	{
		board[i][j] = INVALID;
		i++;
		j++;
	}
	i = row + 1;
	j = col - 1;
	while (i < SIZE && j >= 0)
	{
		board[i][j] = INVALID;
		i++;
		j--;
	}
}

void	print(char board[][SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE)
	{
		j = 0;
		while (board[i][j] != 'Q')
			j++;
		printf("%d", j);
		i++;
	}
	printf("\n");
}

void	place_queen(char board[][SIZE], int row, int *t)
{
	int		i;
	char	board_cp[SIZE][SIZE];

	i = 0;
	copy_board(board_cp, board);
	while (i < SIZE)
	{
	    
		if (board_cp[row][i] == EMPTY && row != SIZE - 1)
		{
		  
			board_cp[row][i] = QUEEN;
			mark_square_invalid(row, i, board_cp);
			place_queen(board_cp, row + 1, t);
			copy_board(board_cp, board);
		}
		else if (board_cp[row][i] == EMPTY && row == SIZE - 1)
		{
		
			board_cp[row][i] = QUEEN;
			print(board_cp);
			*t = *t + 1;
			break;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[SIZE][SIZE];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			board[i][j++] = EMPTY;
		i++;
	}
	i = 0;
	j = 0;
	place_queen(board, 0, &j);
	return (j);
}

/*int	main(void)
{
	int	result;

	result = ft_ten_queens_puzzle();
	printf("Total solutions: %d\n", result);
	return (0);
}
*/
