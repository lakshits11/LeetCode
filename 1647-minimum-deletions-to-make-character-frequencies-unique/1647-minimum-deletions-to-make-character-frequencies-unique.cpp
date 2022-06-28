class Solution {
public:
    int minDeletions(string s) {
        vector<int> mp(26,0);
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
        }
        vector<int> cnt(s.size()+1);
        for(int i=0;i<26;i++)
        {
            cnt[mp[i]]++;
        }
        int removals = 0;
        for(int i=s.size();i>0;i--)
        {
            if(cnt[i] > 1){
                removals += cnt[i]-1;
                cnt[i-1] += cnt[i]-1;
            }
        }
        return removals;
    }
};