class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int cm=arr[0], mx = arr[0], cmn=arr[0], mn=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            cm = max(arr[i], cm+arr[i]);
            cmn = min(arr[i], cmn+arr[i]);
            mx = max(mx, cm);
            mn = min(mn, cmn);
        }
        return max(abs(mn), abs(mx));
    }
};