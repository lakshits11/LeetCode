/*
This is essentially the same as Longest substring with at most K distinct characters, but it is subarrays with at most 2 distinct numbers.
*/

class Solution
{
public:
    int totalFruit(vector<int> &f)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int r = 0, l = 0;
        int len = -1;
        unordered_map<int, int> u;
        for (r = 0; r < f.size(); r++)
        {
            u[f[r]]++;
            while (u.size() > 2)
            {
                u[f[l]]--;
                if (u[f[l]] == 0) u.erase(f[l]);
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};