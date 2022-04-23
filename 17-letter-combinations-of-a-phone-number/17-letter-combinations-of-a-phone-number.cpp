class Solution
{
public:
    const vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> res;
        res.push_back("");

        for (char digit : digits)
        {
            vector<string> temp;
            for (auto candidate : pad[digit - '0'])
            {
                for (auto x : res)
                {
                    temp.push_back(x + candidate);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};