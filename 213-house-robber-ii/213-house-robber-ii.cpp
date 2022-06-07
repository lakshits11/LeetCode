class Solution {
public:
    int houseRobber1(vector<int>& nums) {
        int n = nums.size(), prev2, prev1, curr;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0], nums[1]);
        prev2 = nums[0];
        prev1 = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
        {
            curr = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int rob(vector<int> &arr)
    {
        ios_base::sync_with_stdio(false);
        vector<int> temp1, temp2;
        int n = arr.size();
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0], arr[1]);
        for(int i=0; i<n; i++){
            if(i!=0)
                temp2.push_back(arr[i]);
            if(i!=n-1)
                temp1.push_back(arr[i]);
        }
        return max(houseRobber1(temp1), houseRobber1(temp2));
    }
    
    
};