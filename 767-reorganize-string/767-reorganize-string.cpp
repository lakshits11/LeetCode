class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        int mostFreq = 0, i = 0;
        for(char c : s)
        {
            if(++cnt[c-'a']>cnt[mostFreq])
                mostFreq = c-'a';
        }
        
        if(2 * cnt[mostFreq] - 1 > s.size())
            return "";
        
        while(cnt[mostFreq])
        {
            s[i] = mostFreq + 'a';
            i+=2;
            cnt[mostFreq]--;
        }
        
        for(int j = 0; j < 26; j++)
        {
            while(cnt[j])
            {
                if(i >= s.size()) i = 1;
                s[i] = j + 'a';
                cnt[j]--;
                i += 2;
            }
        }
        
        return s;
    }
};