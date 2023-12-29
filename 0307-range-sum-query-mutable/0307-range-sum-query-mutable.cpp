static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

#define ll long long
class NumArray {
public:
    
    vector<int> seg;
    int n;
    
    void build(ll index, int lo, int hi, vector<int> &nums)
    {
        if(lo == hi)
        {
            seg[index] = nums[lo];
            return;
        }
        
        int mid = lo + (hi-lo)/2;
        build(2*index+1, lo, mid, nums);
        build(2*index+2, mid+1, hi, nums);
        
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    
    void pointUpdate(ll index, int ss, int se, int ai, int val)
    {
        if(ss == se)
        {
            seg[index] = val;
        }
        else {
            int mid = ss + (se-ss)/2;
            if(ai <= mid)
                pointUpdate(2*index+1, ss, mid, ai, val);
            else pointUpdate(2*index+2, mid+1, se, ai, val);
            
            seg[index] = seg[2*index+1] + seg[2*index+2];
        }
    }
    
    int querySum(ll index, int ss, int se, int al, int ar)
    {
        if(al<=ss && se<=ar) return seg[index];
        
        if(se<al || ar<ss) return 0;
        
        int mid = ss + (se-ss)/2;
        return querySum(2*index+1, ss, mid, al, ar) + querySum(2*index+2, mid+1, se, al, ar);
    }
        
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg = vector<int>(4*n,0);
        build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        pointUpdate(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return querySum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */