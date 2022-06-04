// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        pair<int, int> a[n+1];
        for(int i=0;i<n;i++)
        {
            a[i].first = end[i];
            a[i].second = i;
        }
        sort(a, a+n);
        int time_limit = a[0].first;
        int count = 1;
        
        for(int i=1;i<n;i++)
        {
            if(start[a[i].second]>time_limit)
            {
                count++;
                time_limit = a[i].first;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends