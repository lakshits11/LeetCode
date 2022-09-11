class Solution {
private:
    bool isVowel(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    
    int countAtMostKVowels(string &s, int k)
    {
        int count = 0;
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> vowelMap;
        for(j = 0; j < n; j++)
        {
            if(!isVowel(s[j]))
            {
                vowelMap.clear();
                i = j+1;
                continue;
            }
            
            vowelMap[s[j]]++;
            
            while(vowelMap.size() > k){
                vowelMap[s[i]]--;
                if(vowelMap[s[i]]==0)
                    vowelMap.erase(s[i]);
                i++;
            }
            
            count += (j - i + 1);
        }
        return count;
    }
    
public:
    int countVowelSubstrings(string w)
    {
        return countAtMostKVowels(w, 5) - countAtMostKVowels(w, 4);
    }
};