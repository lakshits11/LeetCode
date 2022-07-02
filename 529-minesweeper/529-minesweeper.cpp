// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int row = click[0], col = click[1];
        int m = board.size(), n = board[0].size();
        if (board[row][col] == 'M' || board[row][col] == 'X')
        {
            board[row][col] = 'X';
            return board;
        }
        int num = 0;
        for (vector<int> dir : dirs)
        {
            int newRow = dir[0] + row;
            int newCol = dir[1] + col;

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 'M')
                num++;
        }
        if (num > 0)
        {
            board[row][col] = (char)(num + '0');
            return board;
        }
        board[row][col] = 'B';

        for (vector<int> dir : dirs)
        {
            int newRow = dir[0] + row;
            int newCol = dir[1] + col;

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 'E')
            {
                vector<int> neww = {newRow, newCol};
                updateBoard(board, neww);
            }
        }
        return board;
    }
};