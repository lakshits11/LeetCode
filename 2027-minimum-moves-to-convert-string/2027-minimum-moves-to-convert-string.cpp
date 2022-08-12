class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0, i;
        for(i=0;i<s.size()-2;i++)
        {
            if(s[i]=='X')
            {
                s[i] = 'O';
                s[i+1] = 'O';
                s[i+2] = 'O';
                ans++;
            }
        }
        if(s[i]=='X' || s[i+1]=='X')
            ans++;
        return ans;
    }
};