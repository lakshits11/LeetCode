// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = nums.size();
        int maxLeft = nums[0];
        int maxi = nums[0];
        int p = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < maxLeft)
            {
                maxLeft = maxi;
                p = i;
            }
            else if(nums[i] > maxi)
                maxi = nums[i];
        }
        return p+1;
    }
};