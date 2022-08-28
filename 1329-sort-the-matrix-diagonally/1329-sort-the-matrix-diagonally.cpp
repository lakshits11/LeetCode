// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void sortAt(int x, int y, vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> counts(101, 0);
        for (int i = x, j = y; i < m && j < n; i++, j++)
            counts[mat[i][j]]++;
        for (int i = 0; i < 101; i++)
        {
            while (counts[i])
            {
                mat[x++][y++] = i;
                counts[i]--;
            }
        }
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || j == 0)
                    sortAt(i, j, mat);
        
        return mat;
    }
};