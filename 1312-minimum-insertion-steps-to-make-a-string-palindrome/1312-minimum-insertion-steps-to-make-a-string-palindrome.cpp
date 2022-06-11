class Solution {
public:
    // int f(int i, int j, string &s, vector<vector<int>> &mem)
    // {
    //     if(i==j || i>j)    return 0;
    //     if(mem[i][j]!=-1)
    //         return mem[i][j];
    //     if(s[i]==s[j])
    //         return mem[i][j] = f(i+1, j-1, s, mem);
    //     else
    //         return mem[i][j] = 1 + min(f(i+1, j, s, mem), f(i, j-1, s, mem));
    // }
    
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};