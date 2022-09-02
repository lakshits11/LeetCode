class Solution {
public:
    int longestOnes(vector<int>& arr, int k)
    {
        int n = arr.size(), l=0, r=0, ans=-1;
        while(r < n)
        {
            if(arr[r]==0)
                k--;
            while(k<0)
            {
                if(arr[l]==0)
                    k++;
                l++;
            }
            ans = max(r-l+1, ans);
            r++;
        }
        return ans;
        
    }
};