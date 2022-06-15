class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        int n = arr.size();
        int maxi = 1;
        vector<int> dp(n, 1), count(n,1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[j] < arr[i] && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    // inherit
                    count[i] = count[j];
                }
                else if(arr[j]<arr[i] && dp[i]==dp[j]+1){
                    // increase the count
                    count[i] += count[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            if(dp[i]==maxi) ans+=count[i];
        }
        return ans;
        
    }
};