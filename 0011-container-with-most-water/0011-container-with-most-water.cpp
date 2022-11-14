class Solution {
public:
    int maxArea(vector<int>& ht) {
        int water = 0;
        int i = 0, j = ht.size() - 1;
        while(i < j)
        {
            int h = min(ht[i], ht[j]);
            water = max(water, (j-i)*h);
            while(ht[i]<=h && i<j) i++;
            while(ht[j]<=h && i<j) j--;
        }
        return water;
    }
};