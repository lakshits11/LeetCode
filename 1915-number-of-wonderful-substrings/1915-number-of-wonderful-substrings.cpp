static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    long long wonderfulSubstrings(string word) {
    long cnt[1024] = { 1 }, mask = 0, res = 0;
    for (auto ch : word) {
        mask ^= 1 << (ch - 'a');
        res += cnt[mask];
        for (auto n = 0; n < 10; ++n)
            res += cnt[mask ^ (1 << n)];
        ++cnt[mask];
    }
    return res;
    }
};