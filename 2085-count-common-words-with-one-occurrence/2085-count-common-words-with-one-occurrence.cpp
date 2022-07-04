class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> u1;
        unordered_map<string, int> u2;
        for(string s : words1)
            u1[s]++;
        for(string s : words2)
            u2[s]++;
        
        int count = 0;
        for(string s : words1)
            if(u1[s]==1 && u2[s]==1)
                count++;
        return count;
    }
};