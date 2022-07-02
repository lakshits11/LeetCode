class Solution
{
public:
    int getMax(int x, vector<int> &xx)
    {
        sort(xx.begin(), xx.end());
        int xLength = xx.size();
        int maxi = max(xx[0], x - xx[xLength - 1]);
        for (int i = 1; i < xLength; i++)
            maxi = max(maxi, xx[i] - xx[i - 1]);
        return maxi;
    }
    int maxArea(int h, int v, vector<int> &hcuts, vector<int> &vcuts)
    {
        ios_base::sync_with_stdio(false);
        return (int)((long)getMax(h, hcuts) * getMax(v, vcuts) % 1000000007);
    }
};