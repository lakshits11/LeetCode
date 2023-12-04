class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums) {
        pref.resize(nums.size(), 0);
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pref[i] = (nums[i]+pref[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pref[right];
        return pref[right]-pref[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */