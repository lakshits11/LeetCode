class Solution
{
public:
    int maxArea(vector<int> &ht)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int water = 0;
        int i = 0, j = ht.size() - 1, h;
        while (i < j)
        {
            h = min(ht[i], ht[j]);
            water = max(water, (j - i) * h);
            while (ht[i] <= h && i < j)
                i++;
            while (ht[j] <= h && i < j)
                j--;
        }

        return water;
    }
};
