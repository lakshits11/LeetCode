// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    int nCr(int n, int r){
        if(r>n) return 0;
        if(r==n)    return 1;
        
        vector<vector<long>> dp(n+1, vector<long>(r+1, 0));
        for(int i=1;i<=n;++i){
            for(int j=0;j<=min(r, n);++j)
            {
                if(r>n) continue;
                if(i==j || j==0)
                    dp[i][j]=1;
                else {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                }
            }
        }
        
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends