class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        for(int i=0;i<arr.size();++i)
        {
            int mx=INT_MIN;
            while(!s.empty() && s.top()>arr[i])
            {
                mx = max(mx, s.top());
                s.pop();
            }
            if(mx != INT_MIN)
                s.push(mx);
            else s.push(arr[i]);
        }
        int ans=0;
        while(!s.empty()) s.pop(),ans++;
        return ans;
    }
};