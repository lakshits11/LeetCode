class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans = arr[0];
        int maxi = ans, mini = ans;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<0)
                swap(mini, maxi);
            mini = min(arr[i], arr[i]*mini);
            maxi = max(arr[i], arr[i]*maxi);
            ans = max({ans, maxi, mini});
        }
        return ans;
    }
};