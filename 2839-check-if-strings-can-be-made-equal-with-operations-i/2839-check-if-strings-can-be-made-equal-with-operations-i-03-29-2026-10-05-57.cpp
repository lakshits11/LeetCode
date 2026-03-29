class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        for (int i = 0; i < n; i++) 
        {
            if (s1[i] == s2[i])
                continue;
            else 
            {
                if (i < n - 2) 
                {
                    swap(s1[i], s1[i + 2]);
                    if (s1[i] != s2[i])
                        return false;
                }
                else return false;
            }
        }
        return true;
    }
};