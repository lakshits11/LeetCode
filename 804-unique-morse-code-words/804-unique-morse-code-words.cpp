class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> seen;

        for(string word : words)
        {
            string temp;
            for(char c : word)
            {
                temp.append(morse[c-'a']);
            }
            seen.insert(temp);
        }
        
        return seen.size();
        
    }
};