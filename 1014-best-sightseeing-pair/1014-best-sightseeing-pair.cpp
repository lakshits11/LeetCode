class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &a)
    {
        ios_base::sync_with_stdio(false);
        int n = a.size();
        int maxEnd = a[n - 1] - (n - 1);
        int maxOverAllGain = INT_MIN;
        for (int i = n - 2; i >= 0; i--)
        {
            maxEnd = max(maxEnd, a[i + 1] - i - 1);
            maxOverAllGain = max(maxOverAllGain, a[i] + i + maxEnd);
        }
        return maxOverAllGain;
    }
};