class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        if(k<=1)    return 0;
        int ans = 0, prod=1, left = 0, n = arr.size();
        for(int right = 0; right < n; right++)
        {
            prod *= arr[right];
            while(prod >= k)
                prod /= arr[left++];
            ans += (right-left+1);
        }
        return ans;
    }
};