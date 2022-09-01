class Solution {
public:
    int maxArea(vector<int>& ht)
    {
        ios_base::sync_with_stdio(false);
        int i = 0, j = ht.size()-1, h;
        int water = 0;
        while(i < j)
        {
            h = min(ht[i], ht[j]);
            water = max(water, (j-i) * h);
            while(i<j && ht[i]<=h)
                i++;
            while(j>i && ht[j]<=h)
                j--;
        }
        return water;
    }
};