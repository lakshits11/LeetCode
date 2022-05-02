class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        int count=0;
        vector<int> pref(n);
        vector<int> suff(n);
        unordered_set<char> st;
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
            pref[i]=st.size();
        }
        st.clear();
        for(int i=n-1;i>=0;i--)
        {
            st.insert(s[i]);
            suff[i] = st.size();
        }
        for(int i=1;i<n;i++)
        {
            if(pref[i-1]==suff[i])
                count++;
        }
        return count;
    }
};