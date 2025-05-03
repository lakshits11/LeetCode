class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string ans;
        for (int i = 0, j = 1; j < d.size(); j++) 
        {
            if (d[j] == '.')
                continue;
            int len = j - i - 1;
            if (i > 0)
                ans.push_back(d[i]);
            if (d[i] == d[j])
                ans += string(len, d[i]);
            else if(d[i]=='L' && d[j]=='R')
                ans += string(len, '.');
            else
                ans += string(len/2, 'R') + string(len%2, '.') + string(len/2, 'L');
            i = j;
        }
        return ans;
    }
};