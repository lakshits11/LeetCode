class Solution {
public:
    int res = 0;
    void solve(int i, int temp, vector<int> &uniq)
    {
        res = max(res, __builtin_popcount(temp));
        for(int j = i; j < uniq.size(); j++)
        {
            // means they have unique chars only
            if((temp & uniq[j]) == 0)
            {
                solve(j+1, temp|uniq[j], uniq);
            }
        }
        
        
    }
    int maxLength(vector<string>& arr) {
        vector<int> uniq;
        for(string &s : arr)
        {
            bitset<26> a;
            for(char c : s)
                a.set(c-'a');
            int n = a.count();
            if(n!=s.size()) continue;
            
            int val=0;
            for(char &ch : s)
            {
                val = (val | (1 << (ch - 'a')));
            }
            uniq.push_back(val);
        }
        int temp = 0;
        solve(0, temp, uniq);
        
        return res;
    }
};