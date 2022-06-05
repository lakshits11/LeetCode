class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int count=1, counter=0;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]-nums[counter]) <= k)
                continue;
            else{
                count++;
                counter=i;
            }
        }
        return count;
    }
};