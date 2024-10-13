#include <iostream>
#define N 9
using namespace std;

bool isSafe(int board[N][N], int row, int col, int num)
{
    // Check the column and row
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == num)
            return false; // Check column
        if (board[row][i] == num)
            return false; // Check row
    }

    // Check the 3x3 sub-grid
    int startingRow = (row / 3) * 3;
    int startingCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++)
    { // Correctly iterate over 3 rows
        for (int j = 0; j < 3; j++)
        { // Correctly iterate over 3 columns
            if (board[startingRow + i][startingCol + j] == num)
            {
                return false; // Check the sub-grid
            }
        }
    }

    return true; // The number can be placed
}

bool helper(int board[N][N], int row, int col)
{
    // If we reach the last cell, we're done
    if (row == N)
        return true;

    // Move to the next column, if we reach the end, move to the next row
    int nrow = row, ncol = col + 1;
    if (ncol == N)
    {             // If we go past the last column, move to the next row
        ncol = 0; // Reset column
        nrow++;   // Move to next row
    }

    // If the cell is already filled, move to the next cell
    if (board[row][col] != 0)
    {
        return helper(board, nrow, ncol);
    }

    // Try placing numbers from 1 to 9
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i; // Place the number
            if (helper(board, nrow, ncol))
            { // Recur to see if it leads to a solution
                return true;
            }
            board[row][col] = 0; // Backtrack
        }
    }

    return false; // No valid number found
}

int main()
{
    int board[N][N] = {
        {6, 0, 5, 0, 0, 8, 0, 1, 9},
        {0, 9, 0, 6, 1, 7, 4, 3, 5},
        {0, 4, 0, 0, 0, 9, 0, 8, 7},
        {0, 3, 7, 0, 0, 5, 1, 0, 0},
        {9, 0, 0, 0, 4, 2, 0, 0, 0},
        {0, 2, 8, 3, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 0, 8},
        {0, 5, 0, 0, 2, 0, 9, 6, 0},
        {0, 0, 0, 0, 0, 6, 3, 0, 0}};

    if (helper(board, 0, 0))
    {
        // Print the solved Sudoku board
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
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
