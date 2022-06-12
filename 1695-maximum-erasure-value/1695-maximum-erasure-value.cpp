// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = nums.size(), l=0, ans = 0;
        int pref[n+1];
        pref[0]=0;
        for(int i=0;i<n;++i)
        {
            pref[i+1] =nums[i]+pref[i];
        }
        vector<int> u(10001, -1);
        for(int i=0;i<n;i++)
        {
            l = max(l, u[nums[i]]+1);
            ans = max(ans, pref[i+1]-pref[l]);
            u[nums[i]] = i;
        }
        return ans;
    }
};