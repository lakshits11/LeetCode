class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        vector<int> mpp(256, -1);
        int n = s.length();
        int l= 0, r=0, len=0;
        while(r < n)
        {
            if(mpp[s[r]] != -1)
                l = max(mpp[s[r]]+1, l);
            mpp[s[r]]=r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};