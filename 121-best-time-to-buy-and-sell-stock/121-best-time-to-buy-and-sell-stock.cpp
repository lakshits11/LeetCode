class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        ios::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int maxProfit = 0;
        int minElement = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < minElement)
            {
                minElement = arr[i];
            }
            if (maxProfit < (arr[i] - minElement))
            {
                maxProfit = arr[i] - minElement;
            }
        }
        return maxProfit;
    }
};