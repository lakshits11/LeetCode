// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int first[26] = {[0 ... 25] = 221}, last[26] = {}, res = 0;
//     for(int i=0;i<26;i++)
//     {
//         cout << first[i] << "\n";
//     }

//     return 0;
// }

// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // const int mod = 1e9+7;
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] <= i)
                    dp[i] += (long long)dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};