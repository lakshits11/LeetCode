class Solution {
public:
    int numWays(int steps, int arrLen) {
    int sz = min(steps / 2 + 1, arrLen);
    vector<int> v1(sz + 2), v2(sz + 2);
    v1[1] = 1;
    while (steps-- > 0) {
        for (auto i = 1; i <= sz; ++i)
            v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007;
        swap(v1, v2);
    }
    return v1[1];
}
};