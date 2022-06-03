// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int m, int n, vector<vector<int>> M)
    {
        int ans = 0;
        int gt[m][n];
        memset(gt, 0, sizeof(gt));
        
        for(int col = n-1; col>=0; col--)
        {
            for(int row=0; row<m;row++)
            {
                int right = (col==n-1) ? 0 : gt[row][col+1];
                int rightUpDiag = (row==0 || col==n-1) ? 0 : gt[row-1][col+1];
                int rightDownDiag = (row==m-1 || col==n-1) ? 0 : gt[row+1][col+1];
                
                gt[row][col] = M[row][col] + max({right, rightUpDiag, rightDownDiag});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            ans = max(ans, gt[i][0]);
        }
        return ans;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends