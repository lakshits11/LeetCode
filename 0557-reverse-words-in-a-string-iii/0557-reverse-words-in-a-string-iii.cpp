class Solution {
public:
    string reverseWords(string s) {
        string temp, ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                temp.append(1,s[i]);
            }
            if(s[i]==' ' || i==s.length()-1)
            {
                cout << "Temp: " << temp << "\n";
                reverse(temp.begin(), temp.end());
                ans.append(temp);
                if(i!=s.length()-1)
                    ans.append(1, ' ');
                temp.clear();
            }
        }
        return ans;
    }
};