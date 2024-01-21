class Solution {
public:
    int rob(vector<int>& arr)
    {
        int n = arr.size();
        if(n==1)
            return arr[0];
        vector<int> dp(n, 0);
        
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
        }
        return max(dp[n-1], dp[n-2]);
    }
};