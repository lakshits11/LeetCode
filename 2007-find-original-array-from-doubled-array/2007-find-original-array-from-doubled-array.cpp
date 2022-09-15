class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A)
    {
        if(A.size()%2==1) return {};
        multiset<int> s(A.begin(), A.end());
        vector<int> ans;
        while(s.size())
        {
            int n = *s.begin();
            s.erase(s.begin());
            auto it = s.find(2*n);
            if(it == s.end()) return {};
            s.erase(it);
            ans.push_back(n);
        }
        return ans;
    }
};