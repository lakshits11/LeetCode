#define mod 1000000007

class Solution {
private:
    vector<vector<int>> path = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
    vector<vector<int>> dp;
public:
    int f(int digit, int n)
    {
        if(digit == 5)  return 0;
        if(n==1)
        {
            if(digit == 4 || digit == 6)
                return 3;
            else return 2;
        }
        if(dp[digit][n] != -1)
            return dp[digit][n];
        long ans = (f(path[digit][0], n-1) + f(path[digit][1], n-1))%mod;
        if(digit == 4 || digit==6)
            ans = (ans + f(path[digit][2], n-1))%mod;
        return dp[digit][n] = ans;
    }
    int knightDialer(int n) {
        ios_base::sync_with_stdio(false);
        int x = 0;
        dp.resize(10, vector<int>(n+1, -1));
        if(n==1) return 10;
        for(int i=0;i<10;i++)
        {
            x = (x + f(i,n-1))%mod;
        }
        return x;
    }
};