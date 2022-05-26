class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> temp;
        int len=1, n=arr.size();
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]>temp.back())
            {
                temp.push_back(arr[i]);
                len++;
            }
            else
            {
                auto x = lower_bound(temp.begin(), temp.end(), arr[i]);
                *x = arr[i];
            }
        }
        return len;
    }
};