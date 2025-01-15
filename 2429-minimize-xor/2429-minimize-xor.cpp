static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

// explanation in lee215 solution: https://leetcode.com/problems/minimize-xor/solutions/2648723/java-c-python-bit-count

// below code is more easy to understand than lee215's 

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int ans = 0;
        bitset<32> bit(num1);
        for (int i = 31; i >= 0; i--) {
            if ((bit[i] & 1) && n) {
                ans |= 1 << i;
                n--;
            }
        }

        if (n > 0) {
            for (int i = 0; i < 32; i++) {
                if (!(ans & (1 << i)) && n) {
                    ans |= 1 << i;
                    n--;
                }
            }
        }

        return ans;
    }
};