//https://leetcode.com/problems/count-palindromic-subsequences/solutions/2850667/simplify-to-classic-dp-2-d-recursive-solution-c

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int dp[10001][6]; // Increased size of second dimension to 6
    string digit;
    string s;
    int mod = 1e9+7;

    string getDigit(int x){
        string s = to_string(x);
        if(s.size()==1)s = '0'+s;
        string t = s;
        s+='.';
        reverse(t.begin(),t.end());
        s+=t;
        return s;
    }

    int countPalindromes(string t) {
        s = t;
        long long ans = 0;
        for(int i=0;i<100;i++){
            digit = getDigit(i);
            memset(dp, 0, sizeof(dp));

            for (int pos = 0; pos <= s.size(); ++pos) {
                dp[pos][5] = 1;
            }

            for (int pos = s.size() - 1; pos >= 0; --pos) {
                for (int id = 4; id >= 0; --id) {
                    dp[pos][id] = dp[pos + 1][id];
                    if (id == 2 || (id < digit.size() && pos < s.size() && s[pos] == digit[id])) {
                        dp[pos][id] = (dp[pos][id] + dp[pos + 1][id + 1]) % mod;
                    }
                }
            }
            ans = (ans + dp[0][0]) % mod;
        }
        return ans;
    }
};