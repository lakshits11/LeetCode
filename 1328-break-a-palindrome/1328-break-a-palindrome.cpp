class Solution {
public:
    string breakPalindrome(string s) {
        /*
        It only needs to track half of S because it's a palindrome.
If there is a character which is not a in S except the middle position, it will certainly be in the first half.
        */
        int n = s.size();
        for(int i = 0; i < n/2; i++)
        {
            if(s[i]!='a')
            {
                s[i]='a';
                return s;
            }
        }
        s[n-1] = 'b';
        return n<2 ? "" : s;
    }
};