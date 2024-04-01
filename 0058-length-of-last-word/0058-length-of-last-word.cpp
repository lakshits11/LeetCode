static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int l=0;
        int flag=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==' ' and flag==0)
                continue;
            else if(s[i]==' ' and flag==1)
                return l;
            else{
                flag=1;
                l++;
            }     
        }
        return l;
    }
};