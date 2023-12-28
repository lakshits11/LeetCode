class Solution {
public:
    vector<string>v= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector<string> ans;
    
    void f(int index, string &digits, string temp)
    {
        if(index == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        string s = v[digits[index]-'0'];
        for(int i = 0; i < s.size(); i++)
        {
            f(index+1, digits, temp+s[i]);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        f(0, digits, "");
        return ans;
    }
};