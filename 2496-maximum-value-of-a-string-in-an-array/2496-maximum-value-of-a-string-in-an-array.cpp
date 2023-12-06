class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = -1;
        for(string &s : strs)
        {
            if(all_of(s.begin(), s.end(), ::isdigit))
                ans = max(ans, stoi(s));
            else ans = max(ans, (int)s.size());
        }
        return ans;
    }
};