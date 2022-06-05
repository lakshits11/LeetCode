// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    int solve(vector<int> &left, vector<int> &upd, vector<int> &lwd, int col)
    {
        int n = size(left), count = 0;
        if (col == n)
            return 1;

        for (int row = 0; row < n; row++)
        {
            if (!left[row] && !upd[n - 1 + row - col] && !lwd[row + col])
            {
                left[row] = upd[n - 1 + row - col] = lwd[row + col] = 1;
                count += solve(left, upd, lwd, col + 1);
                left[row] = upd[n - 1 + row - col] = lwd[row + col] = 0;
            }
        }

        return count;
    }

    int totalNQueens(int n)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        vector<int> left(n, 0), upd(2 * n - 1, 0), lwd(2 * n - 1, 0);
        return solve(left, upd, lwd, 0);
    }
};