static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    bool isPal(string &s)
    {
        int i=0, j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string &s : words)
        {
            if(isPal(s)) return s;
        }
        return "";
    }
};