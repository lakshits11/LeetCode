class Solution {
public:
    int minFlipsMonoIncr(string S, int f0 = 0, int f1 = 0) {
    for (auto c : S) {
        f0 += c - '0';
        f1 = min(f0, f1 + 1 - (c - '0'));
    }
    return f1;
}
};