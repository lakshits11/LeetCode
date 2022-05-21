#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, mod);
        dp[0]=0;
        int n = coins.size();
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j]>i)
                    continue;
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        
        return ((dp[amount] == mod) ? -1 : dp[amount]);
    }
};