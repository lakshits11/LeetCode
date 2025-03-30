static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int mp[26] = {};
        for(int i=0;i<s.size();i++)
            mp[s[i]-'a'] = i;

        vector<int> res;
        int prev = -1, maxi = 0;

        for(int i=0;i<s.size();i++)
        {
            maxi = max(maxi, mp[s[i]-'a']);
            if(maxi == i)
            {
                res.push_back(maxi-prev);
                prev = maxi;
            }
        }
        return res;
    }
};