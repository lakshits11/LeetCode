static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n&1) return false;
        int bal = 0;
        for(int i = 0; i < n; ++i)
        {
            if(locked[i]=='0' || s[i]=='(') bal++;
            else bal--;

            if(bal < 0) return false;
        }
        bal = 0;
        for(int i = n-1; i >= 0; --i)
        {
            if(locked[i]=='0' || s[i]==')') bal++;
            else bal--;

            if(bal < 0) return false;
        }
        return true;
    }
};