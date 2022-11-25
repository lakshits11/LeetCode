class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        ios_base::sync_with_stdio(false);
        int n = arr.size();

        // stack for prev less element, next less element
        stack<pair<int, int>> prevs, nexts;

        // left is for distance to prev less element
        // right is for distance to next less element
        vector<int> left(n), right(n);

        // Initialize
        for (int i = 0; i < n; i++)
        {
            left[i] = i + 1;
            right[i] = n - i;
        }

        /*
        LOGIC:

        Suppose elements are 1 2 3 0
        then for 0, it will pop all elements out of stack to find PLE, but still it will not find PLE.
        In that case, actually it means, 0 is the smallest element.
        So number of subarrays containing 0 as smallest element = i+1 where i is index of 0.
        Here => 4 is no of subarray as ans. (since 3+1 = 4)
        also we can see:

        -> 1 2 3 0
        -> 2 3 0
        -> 3 0
        -> 0

        Total 4

        For NLE, n-i

        Ex: 2 4 6 5 7 0 1 2 3
        Here also for finding NLE, it (i.e 0 ) will pop all elements out of stack.
        But will not find so it means actually this is the min element. So number of subarrays:
        n-i where i is index of 0
        Here i is 5 and n is 9
        so number of subarrays will 0 as min element: 4 (n-i)

        */

        for (int i = 0; i < n; i++)
        {
            // For previous less
            while (!prevs.empty() && prevs.top().first > arr[i])
                prevs.pop();
            left[i] = prevs.empty() ? i + 1 : i - prevs.top().second;
            prevs.push({arr[i], i});

            // For next less
            while (!nexts.empty() && nexts.top().first > arr[i])
            {
                pair<int, int> x = nexts.top();
                nexts.pop();
                right[x.second] = i - x.second;
            }
            nexts.push({arr[i], i});
        }

        long long ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
            ans = (ans + (arr[i] * left[i])%mod * right[i]) % mod;

        return ans;
    }
};