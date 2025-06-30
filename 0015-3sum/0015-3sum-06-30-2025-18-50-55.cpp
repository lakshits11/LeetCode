class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void twos(int x, int i, vector<int> nums)
    {
        int lo=i+1,hi=nums.size()-1;
        while(lo<hi)
        {
            if(nums[lo]+nums[hi]<x) lo++;
            else if(nums[lo]+nums[hi]>x) hi--;
            else {
                temp[0] = nums[i];
                temp[1] = nums[lo];
                temp[2] = nums[hi];
                ans.push_back(temp);
                while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                while(lo<hi && nums[hi]==nums[hi-1]) hi--;

                ++lo;--hi;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        temp.resize(3);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]>0) break;
            twos(-nums[i], i, nums);
        }
        return ans;
    }
};