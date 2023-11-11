class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int n = arr.size();
        int lo = 0, hi = arr.size() - 1;
        int first = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (arr[mid] == target)
            {
                first = mid;
                hi = mid - 1;
            }
            else if (arr[mid] < target)
            {
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        lo = 0, hi = n - 1;
        int last = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (arr[mid] == target)
            {
                last = mid;
                lo = mid + 1;
            }
            else if (arr[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return {first, last};
    }
};