class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        for(int i=0;i<word.size();i++){
            string a="";
            if(isdigit(word[i])){
                while(word[i]=='0') i++;
                while(isdigit(word[i])) a+=word[i++];
                s.insert(a);
            }
        }
        return s.size();
    }
};