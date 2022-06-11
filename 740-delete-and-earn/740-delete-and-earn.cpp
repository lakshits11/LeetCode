class Solution{
public:
    int deleteAndEarn (vector<int> &nums){
        vector<int> points(10001, 0);
        int n = nums.size(), maxn = -1;
        for (int i=0;i<n;i++){
            points[nums[i]]+=nums[i];
            maxn = max(maxn, nums[i]);
        }
        int twoBack = 0, oneBack = points[1], temp;
        for (int i = 2; i <= maxn; i++) {
            temp = oneBack;
            oneBack = max(twoBack+points[i], oneBack);
            twoBack = temp;
        }
        
        return oneBack;
        
    }
};