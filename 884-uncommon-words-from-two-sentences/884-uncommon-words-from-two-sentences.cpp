class Solution {
public:
    vector<string> uncommonFromSentences(string p, string q) {
        string s1 = p + " " + q + " ";
        vector<string> ans;
        unordered_map<string, int> mp;
        string a = "";
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==' ')
            {
                cout << a << "\n";
                mp[a]++;
                a.clear();
            }
            else
                a += s1[i];
        }
        for(auto x : mp)
            if(x.second == 1)
                ans.push_back(x.first);
        return ans;
    }
};