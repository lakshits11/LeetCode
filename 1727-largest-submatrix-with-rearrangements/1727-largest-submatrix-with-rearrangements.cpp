class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mx) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = mx.size();
        int n = mx[0].size();
        int ans = 0;
        
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(mx[r][c]!=0 && r>0)
                    mx[r][c] += mx[r-1][c];
            }
            vector<int> currRow = mx[r];
            sort(currRow.begin(), currRow.end(), greater());
            for(int i = 0; i < n; i++)
                ans = max(ans, currRow[i]*(i+1));
        }
        
        return ans;
    }
};