class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        const int l = (int)s.length();
        string *str = new string[numRows];
        int row = 0, step = 0;

        for (int i = 0; i < l; i++)
        {
            str[row].push_back(s[i]);

            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;

            row += step;
        }

        s.clear();
        for (int j = 0; j < numRows; j++)
        {
            s.append(str[j]);
        }
        return s;
    }
};