class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        
        while(l < r)
        {
            // mid represents leftmost point of our window
            int mid = (l+r)/2;
            if(x - arr[mid] > arr[mid+k] - x)
                l = mid + 1;
            else
                r = mid;
        }
        vector<int> ans;
        for(int i=l;i<(l+k);i++)
            ans.push_back(arr[i]);
        return ans;
    }
};