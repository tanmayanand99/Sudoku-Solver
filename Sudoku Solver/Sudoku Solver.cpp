// Sudoku Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define N 9
using namespace std;
int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
bool isPresentInCol(int j, int num) 
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][j] == num)
        {
            return true;
        }
    }
    return false;
}
bool isPresentInRow(int i, int num) 
{
    for (int j = 0; j < N; j++)
    {
        if (grid[i][j] == num)
        {
            return true;
        }
    }
    return false;
}
bool isPresentInBox(int boxStarti, int boxStartj, int num) 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + boxStarti][j + boxStartj] == num)
            {
                return true;
            }
        }
    }
    return false;
}
void sudokuGrid()
{ 
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (j == 3 || j == 6)
            {
                cout << " | ";
            }
            cout << grid[i][j] << " ";
        }
        if (i == 2 || i == 5) 
        {
            cout << endl;
            for (int i = 0; i < N; i++)
            {
                cout << "---";
            }
        }
        cout << endl;
    }
}
bool findEmptyPlace(int& i, int& j)
{ 
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
bool isValidPlace(int i, int j, int num) 
{
    return !isPresentInRow(i, num) && !isPresentInCol(j, num) && !isPresentInBox(i - i % 3,j - j % 3, num);
}
bool solveSudoku() 
{
    int i, j;
    if (!findEmptyPlace(i, j))
    {
        return true;
    }
    for (int num = 1; num <= 9; num++) 
    { 
        if (isValidPlace(i, j, num)) 
        { 
            grid[i][j] = num;
            if (solveSudoku())
            {
                return true;
            }
            grid[i][j] = 0;
        }
    }
    return false;
}
int main() 
{
    if (solveSudoku() == true)
    {
        sudokuGrid();
    }
    else
    {
        cout << "No solution exists";
    }
}