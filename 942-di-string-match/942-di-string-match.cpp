class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> ans;
        int ic = 0, dc = n;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='I')
            {
                ans.push_back(ic);
                ic++;
            }
            else{
                ans.push_back(dc);
                dc--;
            }
        }
        if(s[n-1] == 'I')
            ans.push_back(ic);
        else
            ans.push_back(dc);
            
        return ans;
    }
};