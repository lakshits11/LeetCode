// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    
    long long maxSubarraySum(int arr[], int n) {
        int currMax = arr[0];
        int maxTillNow = arr[0];
        
        for(int i=1;i<n;i++)
        {
            currMax = max(arr[i], arr[i]+currMax);
            maxTillNow = max(currMax, maxTillNow);
        }
        return maxTillNow;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends