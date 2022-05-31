class Solution {
public:
    bool hasAllCodes(string s, int k) {
        ios_base::sync_with_stdio(0);
        unordered_set<string> st;
        int n = (1<<k);
        for(int i=k;i<=s.length();i++)
        {
            string temp = s.substr(i-k,k);
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                n--;
                if(n==0)
                    return true;
            }
        }
        return false;
    }
};