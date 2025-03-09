class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col, int k) {
        int n = col.size();
        int ans = 0, l = 0;
        for (int r = 0; r < col.size() + k - 1; r++) 
        {
            if (r > 0 && col[r % n] == col[(r - 1) % n])
                l = r;
            if (r - l + 1 >= k)
                ans++;
        }

        return ans;
    }
};