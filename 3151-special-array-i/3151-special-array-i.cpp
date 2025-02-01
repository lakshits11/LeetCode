static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            if (!((arr[i] ^ arr[i + 1]) & 1)) {
                return false;
            }
        }
        return true;
    }
};