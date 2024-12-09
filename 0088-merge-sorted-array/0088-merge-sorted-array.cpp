class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i=0,j=0,x=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
                ans[x++]=nums1[i++];
            else ans[x++]=nums2[j++];
        }
        while(i!=m)
            ans[x++]=nums1[i++];
        while(j!=n)
            ans[x++]=nums2[j++];
        for(i=0;i<m+n;++i)
            nums1[i]=ans[i];
    }
};