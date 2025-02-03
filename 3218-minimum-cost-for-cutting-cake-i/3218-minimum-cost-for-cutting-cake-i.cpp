// https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/solutions/5473400/greedy-algorithm-for-minimizing-grid-cut-costs-sorting-and-two-pointers-approach
static const auto speedup = []() -> int {
   std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
class Solution
{
public:
    int minimumCost(int m, int n, vector<int> &hz, vector<int> &vr)
    {
        sort(hz.begin(), hz.end());
        sort(vr.begin(), vr.end());
        int i = m - 2, j = n - 2;
        int rows = 1, cols = 1, res = 0;

        while (i >= 0 && j >= 0)
        {
            if (hz[i] > vr[j])
            {
                res += hz[i] * cols;
                rows++;
                i--;
            }
            else
            {
                res += vr[j] * rows;
                cols++;
                j--;
            }
        }

        while (i >= 0)
        {
            res += hz[i] * cols;
            rows++;
            i--;
        }
        while (j >= 0)
        {
            res += vr[j] * rows;
            cols++;
            j--;
        }

        return res;
    }
};