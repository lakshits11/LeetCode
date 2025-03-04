// OJ: https://leetcode.com/contest/weekly-contest-264/problems/next-greater-numerically-balanced-number/
// Author: github.com/lzl124631x
// Time: O(C * logC) where `C` is the maximum possible input number.
// Space: O(1)
class Solution {
    bool balance(int n) {
        int cnt[10] = {};
        while (n) {
            if (n % 10 == 0) return false; // no 0 allowed
            cnt[n % 10]++;
            n /= 10;
        }
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] && cnt[i] != i) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        while (true) {
            ++n;
            if (balance(n)) return n;
        }
    }
};