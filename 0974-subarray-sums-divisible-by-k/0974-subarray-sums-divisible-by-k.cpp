class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        long long sum = 0, count = 0;
        vector<int> v(k, 0);
        v[0]=1;
        for (auto &n : nums)
        {
            sum += n;
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            count += v[rem];
            v[rem]++;
        }
        // count += v[0];
        return count;
    }
};