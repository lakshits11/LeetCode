static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char c : s)
            m[c]++;
        map<int, string> u;
        for(auto v : m)
        {
            int freq = v.second;
            int ch = v.first;
            u[freq] += string(freq, ch);
        }
        string res;
        for(auto it = u.rbegin(); it != u.rend(); it++)
        {
            res += it->second;
        }
        return res;
    }
};