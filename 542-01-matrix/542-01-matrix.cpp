class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &m)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int r = m.size();
        if (r == 0)
            return m;
        int c = m[0].size();
        vector<vector<int>> ans(r, vector<int>(c, INT_MAX-100000));

        // First Pass: Check for left and top
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (m[i][j] == 0)
                    ans[i][j] = 0;
                else
                {
                    if (i > 0)
                        ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                    if (j > 0)
                        ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                }
            }
        }

        // Second Pass : Check for right and bottom
        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (i < r - 1)
                    ans[i][j] = min(ans[i][j],1+ ans[i + 1][j]);
                if (j < c - 1)
                    ans[i][j] = min(ans[i][j],1+ ans[i][j + 1]);
            }
        }

        return ans;
    }
};