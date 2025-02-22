static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    string removeOccurrences(string &s, string &p) {
        string x = s;
        int n = s.size(), m = p.size();
        int i, j;
        for(i=0,j=0;i<n;i++)
        {
            x[j++] = s[i];
            if(j >= m && x.substr(j-m, m) == p)
                j -= m;
        }
        return x.substr(0,j);
    }
};