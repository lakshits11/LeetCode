class Solution {
public:
    // int numDifferentIntegers(string word) {
    //     set<string> s;
    //     string temp;
    //     int n = word.length();
    //     for(int i=0;i<n;i++)
    //     {
    //         if(isdigit(word[i]))
    //         {
    //             if(temp.empty() && word[i]!='0')
    //                 temp.push_back(word[i]);
    //             else if(!temp.empty() && word[i]=='0')
    //                 temp.push_back(word[i]);
    //         }
    //         else
    //         {
    //             if(!temp.empty()){
    //                 s.insert(temp);
    //                 temp.clear();
    //             }
    //         }
    //     }
    //     if(!temp.empty()){
    //         s.insert(temp);
    //         temp.clear();
    //     }
    //     return s.size();
    // }
    int numDifferentIntegers(string word) {
        string t="";
        unordered_set<string>s;
        for(int i=0;i<word.size();i++)
            if(isdigit(word[i])){
                t+=word[i];
                if(t=="0")t="";
            if(isalpha(word[i+1]) || i==word.size()-1) s.insert(t),t="";
        }
        return s.size();
    }
};