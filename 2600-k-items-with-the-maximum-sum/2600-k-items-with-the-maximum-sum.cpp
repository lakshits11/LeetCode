class Solution {
public:
    int kItemsWithMaximumSum(int n1, int n0, int nn1, int k) {
        int ans=0;
        k -= n1;
        if(k<=0) return (k+n1);
        else {
            ans += n1;
            k -= n0;
            if(k<=0) return ans;
            else {
                ans -= k;
                return ans;
            }
        }
        return ans;
    }
};