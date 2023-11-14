class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < s.size(); ++i)
        {
            int curr = s[i]-'a';
            if(first[curr] == -1) first[curr] = i;
            last[curr] = i;
        }
        
        int ans = 0;
        for(int i = 0; i < 26; ++i)
        {
            // element does not exist
            if(first[i] == -1) continue;
            
            // else ...
            unordered_set<char> bw;
            for(int j = first[i]+1; j < last[i]; ++j)
            {
                bw.insert(s[j]);
            }
            ans += bw.size();
        }
        
        return ans;
    }
};