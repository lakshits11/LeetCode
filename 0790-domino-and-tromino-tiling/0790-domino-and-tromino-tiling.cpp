class Solution {
public:

    // state - which column now, previous column row1, previous column row 2
    const int mod = 1e9+7;

    int dp[1005][2][2];
    int n;

    int rec(int level,int prev1,int prev2){
        if(level>n) return 0;
        if(level == n){
            return (prev1 && prev2);
        }
        if(dp[level][prev1][prev2] != -1) return dp[level][prev1][prev2];
        int ans = 0;
        if(prev1&&prev2){
            ans+=rec(level+1,1,1);
            ans%=mod;
            ans+=rec(level+2,1,0);
            ans%=mod;
            ans+=rec(level+2,0,1);
            ans%=mod;
            ans+=rec(level+2,1,1);
            ans%=mod;
        }
        else if(prev1){
            ans+=rec(level+1,1,1);
            ans%=mod;
            ans+=rec(level+1,0,1);
            ans%=mod;
        }
        else if(prev2){
             ans+=rec(level+1,1,1);
            ans%=mod;
            ans+=rec(level+1,1,0);
            ans%=mod;
        }
        return dp[level][prev1][prev2] = ans;
    }

    int numTilings(int _n) {
        n=_n;
        memset(dp,-1,sizeof(dp));
        return rec(0,1,1);
    }
};