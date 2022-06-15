class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int maxi = 1, count=1, n = arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
                {count++;maxi = max(maxi, count);}
            else
                count=1;
        }
        return maxi;
    }
};