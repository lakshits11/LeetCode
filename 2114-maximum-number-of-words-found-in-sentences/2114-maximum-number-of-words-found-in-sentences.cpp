class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        
        // count spaces in each sentence :)
        
        int maxi = -1;
        for(int i = 0; i < s.size(); i++)
        {
            int countOfSpace = 0;
            for(int j = 0; j < s[i].size(); j++)
            {
                if(s[i][j] == ' ')
                    countOfSpace++;
            }
            // we did +1 since if we have 4 space then we will have 5 words
            maxi = max(maxi, countOfSpace+1);
        }
        return maxi;
    }
};