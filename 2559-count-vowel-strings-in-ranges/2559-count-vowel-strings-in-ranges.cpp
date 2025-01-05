class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n = w.size();
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        vector<int> pref(n+1, 0);
        for(int i=1;i<n+1;i++)
        {
            pref[i] += pref[i-1];
            if(s.find(w[i-1][0]) != s.end() && s.find(w[i-1].back())!=s.end())
            {
                pref[i]++;
            }
        }
        // for(auto d : pref)
        // {
        //     cout << d << " ";
        // }
        // cout << endl;
        vector<int> ans;
        for(vector<int> &x : q)
        {
            int temp = pref[x[1]+1]-pref[x[0]];
            ans.push_back(temp);
        }
        return ans;
    }
};