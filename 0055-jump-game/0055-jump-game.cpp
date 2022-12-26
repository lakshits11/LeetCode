class Solution {
public:
    bool canJump(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        int n = A.size();
        int last=n-1,i,j;
        for(i=n-2;i>=0;i--) {
            if(i+A[i]>=last) last=i;
        }
        return last<=0;
    }
};