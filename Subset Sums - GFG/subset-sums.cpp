// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void f(int ind, vector<int> &arr, int &n, vector<int> &ans, int sum)
    {
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        f(ind+1, arr, n, ans, sum+arr[ind]);
        f(ind+1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> &arr, int N)
    {
        vector<int> ans;
        f(0, arr, N, ans, 0);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends