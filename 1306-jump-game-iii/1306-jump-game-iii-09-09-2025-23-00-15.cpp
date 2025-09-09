class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        queue<int> q;
        q.push(start);
        vector<bool> dp(arr.size(), false);
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            if(arr[index] == 0) return true;

            dp[index] = true;
            if(index + arr[index] < arr.size() && !dp[index+arr[index]])
            {
                q.push(index+arr[index]);
            }
            if(index - arr[index] < arr.size() && !dp[index-arr[index]])
            {
                q.push(index-arr[index]);
            }
        }
        return false;
    }
};