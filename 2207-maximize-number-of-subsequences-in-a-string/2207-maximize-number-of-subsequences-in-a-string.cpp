static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    long long maximumSubsequenceCount(string t, string pat) 
    {
        long long cnt0 = 1, cnt1 = 1, res0 = 0, res1 = 0;
        for (int i = 0, j = t.size() - 1; j >= 0; ++i, --j) 
        {
            if (t[i] == pat[1])
                res0 += cnt0;
            if (t[j] == pat[0])
                res1 += cnt1;
            cnt0 += t[i] == pat[0];
            cnt1 += t[j] == pat[1];
        }
        return max(res0, res1);
    }
};