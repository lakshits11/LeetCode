class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        vector<int> res(2,-1);
        int n = A.size();
        if(n==0)    return res;
        int i=0, j=n-1;
        while(i<j)
        {
            int mid = i+(j-i)/2;
            if(A[mid]<target)   i=mid+1;
            else j = mid;
        }
        if(A[i]!=target)    return res;
        else res[0]=i;
        
        j=n-1;
        while(i<j)
        {
            int mid = i + (j-i)/2 + 1;
            if(A[mid]>target)   j=mid-1;
            else i = mid;
        }
        res[1]=j;
        return res;
    }
};