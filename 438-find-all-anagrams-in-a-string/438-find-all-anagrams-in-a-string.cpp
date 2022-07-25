class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = p.size(), len = s.size();
        if(len < n) return ans;
        vector<int> phash(26, 0);
        vector<int> hash(26, 0);
        int left = 0, right = 0;
        while(right < n)
        {
            phash[p[right]-'a']++;
            hash[s[right++]-'a']++;
        }
        right -= 1;
        while(right < len)
        {
            if(phash == hash)
                ans.push_back(left);
            right++;
            if(right != len)
                hash[s[right]-'a']++;
            hash[s[left]-'a']--;
            left++;
        }
        return ans;
    }
};