class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> fe1(26, 0);
        vector<int> fo1(26, 0);
        vector<int> fe2(26, 0);
        vector<int> fo2(26, 0);
        for (int i = 0; i < n; i++) 
        {
            if(i%2) 
            {
                fo1[s1[i]-'a']++;
                fo2[s2[i]-'a']++;
            }
            else {
                fe1[s1[i]-'a']++;
                fe2[s2[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(fe1[i]==fe2[i] && fo1[i] == fo2[i]) continue;
            return false;
        }
        return true;        
    }
};
