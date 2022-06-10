class Solution {
public:
    int findWays(vector<int> &arr, int k)
    {
        int mod = 1e9+7;
        int n = arr.size();
        int dp[k+1];
        memset(dp, 0, sizeof(dp));
        
        if(arr[0]==0)
            dp[0]=2;
        else
            dp[0]=1;

        if(arr[0]!=0 && arr[0]<=k)
            dp[arr[0]] = 1;

        for(int i=1;i<n;i++)
        {
            for(int j=k;j>=0;j--)
            {
                if(j>=arr[i])
                    dp[j] = dp[j] + dp[j-arr[i]];
            }
        }

        return dp[k];
    }
    
    int findTargetSumWays(vector<int>& arr, int d) {
        ios_base::sync_with_stdio(0);
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total - d < 0 || (total - d) % 2)
            return 0;
        return findWays(arr, (total - d) / 2);
    }
};