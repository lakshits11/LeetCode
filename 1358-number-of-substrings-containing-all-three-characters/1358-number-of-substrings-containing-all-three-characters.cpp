static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int numberOfSubstrings(string s) {
        int j = 0, res = 0;
        int freq[3] = {0, 0, 0};
        
        for(int i = 0; i < s.size(); ++i)
        {
            freq[s[i]-'a']++;
            
            // while(j<i && freq[s[j]-'a']>1)
            // {
            //     freq[s[j]-'a']--;
            //     j++;
            //     prefix++;
            // }
            
            // suppose ab a,b,c teeno aa gye. to ab iske aage jitne character honge, hum utni hi desired substring bana skte hai ending on those characters. isliye s.size()-i is added to ans
            // jse abcanything => s.size() = 11
            // i=2 (first time when all three chars are present)
            // then ans m 11-2=9 added
            while(freq[0] && freq[1] && freq[2])
            {
                res += (s.size()-i);
                freq[s[j]-'a']--;
                j++;
            }
        }
        return res;
    }
};