// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(string &a, string &b)
    {
        if (a.size() != b.size())
            return false;
        int i, n = a.size();
        for (i = 0; i < n; i++)
            if (a[i] != b[i] && a[i] != ' ')
                break;
        if (i == n)
            return true;
        reverse(a.begin(), a.end());
        for (i = 0; i < n; i++)
            if (a[i] != b[i] && a[i] != ' ')
                break;
        if (i == n)
            return true;
        return false;
    }

public:
    bool placeWordInCrossword(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();

        // Horizontally Checking
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                while (j < n && board[i][j] == '#')
                    j++;
                string cs = "";
                while (j < n && board[i][j] != '#')
                    cs += board[i][j++];
                if (check(cs, word))
                    return true;
            }
        }

        // Vertically Checking
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                while (j < m && board[j][i] == '#')
                    j++;
                string cs = "";
                while (j < m && board[j][i] != '#')
                    cs += board[j++][i];
                if (check(cs, word))
                    return true;
            }
        }
        return false;
    }
};