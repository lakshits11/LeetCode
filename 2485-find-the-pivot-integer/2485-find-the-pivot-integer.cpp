static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int pivotInteger(int n) {
        double x = sqrt(n * (n + 1) / 2.0);
        
        if (fmod(x, 1.0) != 0) {
            return -1;
        } else {
            return static_cast<int>(x);
        }
    }
};