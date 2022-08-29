class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        set<int> stb(b.begin(), b.end());
        int sa = accumulate(a.begin(), a.end(), 0);
        int sb = accumulate(b.begin(), b.end(), 0);
        
        for(int x : a)
        {
            int y = x + (sb-sa)/2;
            if(stb.find(y) != stb.end())
                return {x, y};
        }
        return {};
    }
};