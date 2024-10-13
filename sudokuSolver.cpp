#include <iostream>
#define N 9
using namespace std;

bool isSafe(int board[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == num)
            return false;

        if (board[row][i] == num)
            return false;
    }
    int startingRow = (row / 3) * 3;
    int startingCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startingRow + i][startingCol + j] == num)
                return false;
        }
    }

    return true;
}

bool helper(int board[N][N], int row, int col)
{
    if (row == N)
        return true;

    int nrow = 0, ncol = 0;
    if (col != N - 1)
    {
        nrow = row;
        ncol = col + 1;
    }
    else
    {
        nrow = row + 1;
        ncol = 0;
    }

    if (board[row][col] != 0)
        return helper(board, nrow, ncol);

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i;
            if (helper(board, nrow, ncol))
            {
                return true;
            }
            else
            {
                board[row][col] = 0;
            }
        }
    }

    return false;
}

int main()
{
    int board[N][N] = {{0, 0, 0, 0, 4, 3, 5, 0, 0},
                       {0, 0, 7, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 1, 6, 0, 0, 3, 0},
                       {0, 0, 0, 8, 3, 2, 7, 0, 0},
                       {0, 8, 0, 0, 0, 0, 0, 0, 9},
                       {0, 2, 0, 0, 9, 0, 8, 0, 5},
                       {1, 0, 5, 0, 0, 0, 6, 0, 0},
                       {8, 0, 0, 9, 0, 0, 0, 0, 0},
                       {0, 6, 0, 3, 0, 1, 0, 8, 0}};

    if (helper(board, 0, 0))
    {
        // Print the solved Sudoku board
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j == 3 || j == 6)
                    cout << " | ";
                cout << board[i][j] << " ";
            }
            if (i == 2 || i == 5)
            {
                cout << endl;
                for (int k = 0; k < N - 1; k++)
                    cout << "---";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}
