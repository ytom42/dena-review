#include "connect_four.h"

void init_board()
{
	int i, j;
	for (i = 0; i < BOARD_COL; i++)
	{
		for (j = 0; j < BOARD_ROW; j++)
			board[i][j] = '.';
	}
}

void print_board()
{
	int i, j;

	system("clear");
	printf("1  2  3  4  5  6  7\n");
	printf("-------------------\n");
	for (i = 0; i < BOARD_COL; i++)
	{
		for (j = 0; j < BOARD_ROW; j++)
			printf("%c  ", board[i][j]);
		printf("\n");
	}
	printf("-------------------\n");
}

void player_turn()
{
	int input;
	char c;
	char buf[30];

	if (player == 1)
	{
		printf("Player 1, enter a column number: ");
		c = 'O';
	}
	else
	{
		printf("Player 2, enter a column number: ");
		c = 'X';
	}

	fgets(buf,30,stdin);
	input = atoi(buf);
	if (input == 1 && ROW_1 >= 0)
	{
		board[ROW_1][0] = c;
		ROW_1 -= 1;
	}
	else if (input == 2 && ROW_2 >= 0)
	{
		board[ROW_2][1] = c;
		ROW_2 -= 1;
	}
	else if (input == 3 && ROW_3 >= 0)
	{
		board[ROW_3][2] = c;
		ROW_3 -= 1;
	}
	else if (input == 4 && ROW_4 >= 0)
	{
		board[ROW_4][3] = c;
		ROW_4 -= 1;
	}
	else if (input == 5 && ROW_5 >= 0)
	{
		board[ROW_5][4] = c;
		ROW_5 -= 1;
	}
	else if (input == 6 && ROW_6 >= 0)
	{
		board[ROW_6][5] = c;
		ROW_6 -= 1;
	}
	else if (input == 7 && ROW_7 >= 0)
	{
		board[ROW_7][6] = c;
		ROW_7 -= 1;
	}
	else
	{
		printf("ERROR: Please enter a number from 1~7\n");
		player_turn();
	}
}

int check_board()
{
	int i, j;
	int count;

	for (i = 0; i < BOARD_COL; i++)
	{
		for (j = 0; j < BOARD_ROW; j++)
		{
			count = 1;
			if (board[i][j] == 'O')
			{
				if (i + 1 < BOARD_COL && board[i + 1][j] == 'O')
					count++;
				if (i + 2 < BOARD_COL && board[i + 2][j] == 'O')
					count++;
				if (i + 3 < BOARD_COL && board[i + 3][j] == 'O')
					count++;
				if (count == 4)
					return 1;
			}
			else if (board[i][j] == 'X')
			{
				if (i + 1 < BOARD_COL && board[i + 1][j] == 'X')
					count++;
				if (i + 2 < BOARD_COL && board[i + 2][j] == 'X')
					count++;
				if (i + 3 < BOARD_COL && board[i + 3][j] == 'X')
					count++;
				if (count == 4)
					return 2;
			}
		}
	}
	for (i = 0; i < BOARD_COL; i++)
	{
		for (j = 0; j < BOARD_ROW; j++)
		{
			count = 1;
			if (board[i][j] == 'O')
			{
				if (j + 1 < BOARD_ROW && board[i][j + 1] == 'O')
					count++;
				if (j + 2 < BOARD_ROW && board[i][j + 2] == 'O')
					count++;
				if (j + 3 < BOARD_ROW && board[i][j + 3] == 'O')
					count++;
				if (count == 4)
					return 1;
			}
			else if (board[i][j] == 'X')
			{
				if (j + 1 < BOARD_ROW && board[i][j + 1] == 'X')
					count++;
				if (j + 2 < BOARD_ROW && board[i][j + 2] == 'X')
					count++;
				if (j + 3 < BOARD_ROW && board[i][j + 3] == 'X')
					count++;
				if (count == 4)
					return 2;
			}
		}
	}
	for (i = 0; i < BOARD_COL; i++)
	{
		for (j = 0; j < BOARD_ROW; j++)
		{
			count = 1;
			if (board[i][j] == 'O')
			{
				if (i + 1 < BOARD_COL && j + 1 < BOARD_ROW && board[i + 1][j + 1] == 'O')
					count++;
				if (i + 2 < BOARD_COL && j + 2 < BOARD_ROW && board[i + 2][j + 2] == 'O')
					count++;
				if (i + 3 < BOARD_COL && j + 3 < BOARD_ROW && board[i + 3][j + 3] == 'O')
					count++;
				if (count == 4)
					return 1;
			}
			else if (board[i][j] == 'X')
			{
				if (i + 1 < BOARD_COL && j + 1 < BOARD_ROW && board[i + 1][j + 1] == 'X')
					count++;
				if (i + 2 < BOARD_COL && j + 2 < BOARD_ROW && board[i + 2][j + 2] == 'X')
					count++;
				if (i + 3 < BOARD_COL && j + 3 < BOARD_ROW && board[i + 3][j + 3] == 'X')
					count++;
				if (count == 4)
					return 2;
			}
		}
	}
	for (i = 0; i < BOARD_COL; i++)
	{
		for (j = 0; j < BOARD_ROW; j++)
		{
			count = 1;
			if (board[i][j] == 'O')
			{
				if (i + 1 < BOARD_COL && j - 1 >= 0 && board[i + 1][j - 1] == 'O')
					count++;
				if (i + 2 < BOARD_COL && j - 2 >= 0 && board[i + 2][j - 2] == 'O')
					count++;
				if (i + 3 < BOARD_COL && j - 3 >= 0 && board[i + 3][j - 3] == 'O')
					count++;
				if (count == 4)
					return 1;
			}
			else if (board[i][j] == 'X')
			{
				if (i + 1 < BOARD_COL && j - 1 >= 0 && board[i + 1][j - 1] == 'X')
					count++;
				if (i + 2 < BOARD_COL && j - 2 >= 0 && board[i + 2][j - 2] == 'X')
					count++;
				if (i + 3 < BOARD_COL && j - 3 >= 0 && board[i + 3][j - 3] == 'X')
					count++;
				if (count == 4)
					return 2;
			}
		}
	}
	if ((ROW_1 + ROW_2 + ROW_3 + ROW_4 + ROW_5 + ROW_6 + ROW_7) == -7)
		return (-1);
	return 0;
}

void change_player()
{
	if (player == 1)
		player = 2;
	else
		player = 1;
}

void print_result(int result)
{
	if (result == 1)
		printf("Player 1 Wins!\n");
	else if (result == 2)
		printf("Player 2 Wins!\n");
	else
		printf("Draw!\n");
}

int main()
{
	int result = 0;

	init_board();
	while (result == 0)
	{
		print_board();
		player_turn();
		result = check_board();
		change_player();
	}
	print_board();
	print_result(result);
	return (0);
}
