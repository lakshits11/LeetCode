/*
What we can do is we create a binary string which differs from first binary at 1st position, second binary at 2nd position, third binary at 3rd position,...and so on.

This will make sure that the binary we have made is unique (as it differs from all others at atleast one position).
*/


static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        return ans;
    }
};