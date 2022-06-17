class Solution {
public:
    int maxProduct(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        int res = arr[0];
        int maxi=res, mini=res;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]<0)
                swap(mini, maxi);
            maxi = max(arr[i], maxi*arr[i]);
            mini = min(arr[i], mini*arr[i]);
            
            res = max(res, maxi);
        }
        return res;
    }
};