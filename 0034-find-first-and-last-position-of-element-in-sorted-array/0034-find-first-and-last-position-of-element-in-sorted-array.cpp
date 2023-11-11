class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        if (lb == arr.size() || arr[lb] != target) return {-1, -1};
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        return {lb, ub-1};
    }
};