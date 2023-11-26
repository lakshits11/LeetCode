class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mx) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = mx.size();
        int n = mx[0].size();
        int ans = 0;
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int r = 0; r < m; r++)
        {
            curr = mx[r];
            for(int c = 0; c < n; c++)
            {
                if(curr[c] != 0){
                    curr[c] += prev[c];
                }
            }
            vector<int> sortedRow = curr;
            sort(sortedRow.begin(), sortedRow.end(), greater());
            for(int i = 0; i < n; i++)
                ans = max(ans, sortedRow[i]*(i+1));
            prev = curr;
        }
        
        return ans;
    }
};