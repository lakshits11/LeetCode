class Solution {
public:
    string reverseVowels(string s) {
        queue<char> ss;
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c=='a' || c =='e' || c=='i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c=='I' || c == 'O' || c == 'U')
            {
                ss.push(c);
            }
        }
        for(int i = s.size()-1; i >= 0; i--)
        {
            char c = s[i];
            if(c=='a' || c =='e' || c=='i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c=='I' || c == 'O' || c == 'U')
            {
                s[i] = ss.front();
                ss.pop();
            }
        }
        return s;
        
    }
};