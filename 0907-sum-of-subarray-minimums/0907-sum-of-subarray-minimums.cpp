class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSL(n), NSR(n);

        stack<int> stnsl, stnsr;
        for (int i = 0; i < n; ++i)
        {
            while (!stnsl.empty() && arr[stnsl.top()] >= arr[i])
                stnsl.pop();
            NSL[i] = stnsl.empty() ? -1 : stnsl.top();
            stnsl.push(i);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            while (!stnsr.empty() && arr[stnsr.top()] > arr[i])
                stnsr.pop();
            NSR[i] = stnsr.empty() ? n : stnsr.top();
            stnsr.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i)
        {
            long long mul = (i - NSL[i]) * (NSR[i] - i);
            sum = (sum + mul * arr[i]) % mod;
        }
        return sum;
    }
};