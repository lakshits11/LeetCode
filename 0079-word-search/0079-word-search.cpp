// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string req;
    int dir[5] = {-1, 0, 1, 0, -1};
    int cdir[5] = {-1, 1, 1, -1, -1};
    bool dfs(int i, int j, vector<vector<char>> &board, int idx)
    {
        if (idx == req.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != req[idx] || board[i][j] == '!')
            return false;
        char temp = board[i][j];
        board[i][j] = '!';
        for (int k = 0; k < 4; ++k)
        {
            if (dfs(i + dir[k], j + dir[k + 1], board, idx + 1)) return true;
            // if (dfs(i + cdir[k], j + cdir[k + 1], board, idx + 1)) return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        req = word;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0] && dfs(i, j, board, 0))
                    return true;
            }
        }
        return false;
    }
};