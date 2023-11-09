class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0, cs=0;
        int mod = 1e9+7;
        for(int i=0;i<s.size();++i)
        {
            if(i==0 || s[i]==s[i-1])
                cs++;
            else cs = 1;
            
            ans = (ans+cs)%mod;
        }
        return ans;
    }
};