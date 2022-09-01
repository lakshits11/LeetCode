// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> mat(3, vector<int>(3, -1));
        for (int i = 0; i < moves.size(); i++)
        {
            if (i % 2)
                mat[moves[i][0]][moves[i][1]] = 1;
            else
                mat[moves[i][0]][moves[i][1]] = 0;
        }
        for (int i = 0; i < 3; i++)
        {
            if (mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0]!=-1)
            {
                return (mat[i][0] == 1) ? "B" : "A";
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i] && mat[0][i]!=-1)
            {
                return (mat[0][i] == 1) ? "B" : "A";
            }
        }
        if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0]!=-1)
            return (mat[0][0] == 1) ? "B" : "A";
        if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[2][0]!=-1)
            return (mat[2][0] == 1) ? "B" : "A";

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};