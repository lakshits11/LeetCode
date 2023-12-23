// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/discuss/1650613/Intuition-Explained-oror-Balanced-Parentheses-Greedy-Approach-oror-C++-Clean-Code

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    // locked => lk
    bool canBeValid(string s, string lk) {
        int b = 0; // balance
        int n = s.size();
        if(n&1) return false;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='(' || lk[i]=='0') b++;
            else b--;
            if(b<0) return false;
        }
        b=0;
        for(int i = n-1; i >= 0; --i)
        {
            if(s[i]==')' || lk[i]=='0') b++;
            else b--;
            if(b<0) return false;
        }
        return true;
    }
};