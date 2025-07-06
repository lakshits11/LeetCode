class Solution {
public:
    string reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int i = 0, j = 0, n = s.size(), lastIndex = 0, startIndex;

        while(j < n)
        {
            while(j<n && s[j]==' ') j++;

            startIndex = i;

            while(j<n && s[j] != ' ')
            {
                s[i++] = s[j++];
                lastIndex = i;
            }

            reverse(s.begin()+startIndex, s.begin()+lastIndex);
            s[i++] = ' ';
        }

        s.resize(lastIndex);
        return s;
    }
};