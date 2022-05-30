class Solution {
public:
    string defangIPaddr(string addd) {
        string ans;
        for(int i=0;i<addd.length();i++)
        {
            if(addd[i]!='.')
                ans.push_back(addd[i]);
            else
                ans.append("[.]");
        }
        return ans;
    }
};