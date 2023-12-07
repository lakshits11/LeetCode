static const auto speedup = [](){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int arr[256];
        memset(arr, -1, sizeof(arr));
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        for(right = 0; right < n; right++)
        {
            // duplicate char
            if(arr[s[right]] != -1)
            {
                // left must be ahead of last seen index of right
                left = max(left, arr[s[right]]+1);
            }
            arr[s[right]] = right;
            len = max(len, right-left+1);
        }
        return len;
    }
};