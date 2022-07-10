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
        int mxLeft = INT_MIN;
        int mnRight[n];
        mnRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mnRight[i] = min(nums[i], mnRight[i + 1]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            mxLeft = max(mxLeft, nums[i]);
            if (mxLeft <= mnRight[i + 1])
                return i + 1;
        }
        return -1;
    }
};