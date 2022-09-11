class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int n = s.size();
        int l = 0, r  = 0, ans = 0;
        while(r < n)
        {
            if(mpp[s[r]] != -1)
                l = max(l, mpp[s[r]]+1);
            mpp[s[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};