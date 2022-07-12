// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution
{
public:
    bool allocationPossible(int barrier, int M, int A[], int N)
    {
        // Initially number of students who are allocated the book: 1
        int allocatedStudent = 1;
        int pages = 0;
        for (int i = 0; i < N; i++)
        {
            if (barrier < A[i])
                return false;
            if (pages + A[i] > barrier)
            {
                // As soon barrier is passed, then new student will come in.
                allocatedStudent++;
                if(allocatedStudent > M)
                    return false;
                pages = A[i];
            }
            else
                pages += A[i];
        }
        if (allocatedStudent > M)
            return false;
        return true;
    }

    int findPages(int A[], int N, int M)
    {
        int lo = INT_MAX, hi = 0, res = -1;
        for (int i = 0; i < N; i++)
        {
            lo = min(lo, A[i]);
            hi += A[i];
        }
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (allocationPossible(mid, M, A, N))
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends