class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        vector<int> final;
        int index=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                index++;
            }
            if(nums[i]==target){
                count++;
            }
        }
        while(count>0){
            final.push_back(index);
            index++;
            count--;
        }
        return final;
    }
};