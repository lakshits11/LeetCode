class Solution
{
public:
    int minNumberOfHours(int ien, int iexp, vector<int> &en, vector<int> &exp)
    {
        int count = 0, n = en.size();
        for (int i = 0; i < n; i++)
        {
            if (en[i] >= ien)
            {
                count += en[i] - ien + 1;
                ien += en[i] - ien + 1;
            }
            if (exp[i] >= iexp)
            {
                count += exp[i] - iexp + 1;
                iexp += exp[i] - iexp + 1;
            }
            ien -= en[i];
            iexp += exp[i];
        }
        return count;
    }
};
