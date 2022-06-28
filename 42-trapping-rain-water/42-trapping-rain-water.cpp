class Solution {
public:
    int trap(vector<int>& arr)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = arr.size();
        vector<int> left(n,0), right(n,0);   
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        int ans = 0;
        for(int i=1;i<n;i++)
            left[i] = max(left[i-1], arr[i]);
        for(int i=n-2;i>=0;i--)
            right[i] = max(right[i+1], arr[i]);
        for(int i=0;i<n;i++)
            ans += max(0, min(left[i], right[i]) - arr[i] );
        return ans;
    }
};
