class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        for(int i=0; i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                string temp = "";
                while(i < s.size() && s[i] != ' ') {
                    temp += s[i++];
                }
                if(stoi(temp) > prev)
                    prev = stoi(temp);
                else return false;
            }
        }
        return true;
    }
};