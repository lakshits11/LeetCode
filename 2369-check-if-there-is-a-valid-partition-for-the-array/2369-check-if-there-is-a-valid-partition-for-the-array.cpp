class Solution {
    public:
    int fun(int i, vector<int> &arr, vector<int> &dp){
        if(i>=arr.size()) return true;

        if(dp[i] != -1) return dp[i];

        if(i+1<arr.size() && arr[i] == arr[i+1])
        {
            if(fun(i+2, arr, dp)) return dp[i] = true;
            if(i+2<arr.size() && arr[i] == arr[i+2])
            {
                if(fun(i+3, arr, dp)) return dp[i] = true;
            }
        }

        if(i+2<arr.size() && arr[i+2] - arr[i+1] == 1 && arr[i+1] - arr[i] == 1){
            if(fun(i+3, arr, dp)) return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool validPartition(vector<int>& arr) {

        vector<int> dp(arr.size(), -1);
        return fun(0, arr, dp);
    }
};