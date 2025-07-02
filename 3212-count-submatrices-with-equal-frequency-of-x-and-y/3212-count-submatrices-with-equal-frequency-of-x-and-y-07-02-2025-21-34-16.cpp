#include <bits/stdc++.h>
using namespace std;

static const int speedup = []() -> int {
   std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        // dp_diff[j] will store the prefix sum of (X-Y) for the rectangle
        // ending at the row ABOVE the current one, at column j.
        vector<int> dp_diff(m, 0);

        // dp_x[j] will store the prefix count of 'X's for the rectangle
        // ending at the row ABOVE the current one, at column j.
        vector<int> dp_x(m, 0);

        for (int i = 0; i < n; ++i)
        {
            // These are the running sums for the CURRENT ROW ONLY.
            int current_row_diff = 0;
            int current_row_x_count = 0;

            for (int j = 0; j < m; ++j)
            {
                // 1. Update the running sums for the current row.
                if (grid[i][j] == 'X')
                {
                    current_row_diff++;
                    current_row_x_count++;
                }
                else if (grid[i][j] == 'Y')
                {
                    current_row_diff--;
                }

                // 2. Calculate the total prefix sum for the submatrix (0..i, 0..j).
                // It's the sum from the rectangle above (dp[j]) plus the sum of the current row so far.
                int total_diff = dp_diff[j] + current_row_diff;
                int total_x_count = dp_x[j] + current_row_x_count;

                // 3. Check the conditions for a valid submatrix.
                if (total_diff == 0 && total_x_count > 0)
                {
                    ans++;
                }

                // 4. Update the dp arrays with the new total sums for the current row,
                // so they can be used by the next row (i+1).
                dp_diff[j] = total_diff;
                dp_x[j] = total_x_count;
            }
        }

        return ans;
    }
};