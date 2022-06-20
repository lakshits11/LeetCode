class Solution {
public:
    // int bs(vector<int> &arr)
    int peakIndexInMountainArray(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        int l = 0, r = arr.size()-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid]<arr[mid+1])
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};