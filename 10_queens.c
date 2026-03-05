#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int safe_col(char **chess, int row, int col)
{
    if (row == 0)
        return 0;
    int y = 1;
    for (int i=row-1; i >= 0; i--)
    {
        if (chess[i][col] == 'Q')
            return (1);
        else if (col + y < 10 && chess[i][col + y] == 'Q')
            return (1);
        else if (col - y >= 0 && chess[i][col - y] == 'Q')
            return (1);
        y++;
    }
    for (int i = 0; i < row; i++)
    {
        if (chess[i][col] == 'Q')
            return 1;
    }
    return (0);
}

int	ft_eight_queens_puzzle(char **chess, int row)
{
    int total = 0;
   
    if (row == 10)
    {
        // for (int i=0; i < 10; i++)
        // {
        //     printf("%s\n", chess[i]);
        // }
        // printf("\n");
        return 1;
    }
    for(int col = 0; col < 10; col++)
    {
        if (!safe_col(chess, row, col))
        {
            chess[row][col] = 'Q';
            total += ft_eight_queens_puzzle(chess, row + 1);
            chess[row][col] = '0';
        }
    }
    return total;
}

int main()
{
    int y;
    int i = 0;

    char *board[10];
    while (i < 10)
    {
        y = 0;
        board[i] = malloc(10 + 1);
        while (y < 10)
        {
            board[i][y] = '0';
            y++;
        }
        board[i][y] = '\0';
        i++;
    }
    printf("%d\n", ft_eight_queens_puzzle(board, 0));
    return 0;
}