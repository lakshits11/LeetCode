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
        
        vector<long> prev(r+1, 0);
        vector<long> temp(r+1, 0);
        for(int i=1;i<=n;++i){
            for(int j=0;j<=r;++j)
            {
                if(i==j || j==0)
                    temp[j]=1;
                else {
                    temp[j] = (prev[j-1] + prev[j])%mod;
                }
            }
            prev = temp;
        }
        
        return prev[r];
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