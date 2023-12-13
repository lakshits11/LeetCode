class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int ans = -1;
        int end=0,start=0,maxCount=INT_MIN;
        for(end=0;end<s.size();++end)
        {
            maxCount = max(maxCount, ++counts[s[end]-'A']);
            while(end-start+1 - maxCount > k)
            {
                --counts[s[start++]-'A'];
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};