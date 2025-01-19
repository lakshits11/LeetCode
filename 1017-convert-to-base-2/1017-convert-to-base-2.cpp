static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    string baseNeg2(int N, string res = "") 
    {
        while (N != 0) 
        {
            int rem = N % -2;
            N /= -2;
            if (rem < 0) rem += 2, N += 1;
            res = to_string(rem) + res;
        }
        return max(string("0"), res);
    }
};