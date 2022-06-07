class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i=0, j=0, k=0;
        while(i<m && j<n)
        {
            if(nums1[i]>nums2[j]){
                ans[k] = nums2[j];
                k++;
                j++;
            }
            else{
                ans[k]=nums1[i];
                i++;
                k++;
            }
        }
        if(i<m){
            while(i<m){
                ans[k]=nums1[i];
                i++;
                k++;
            }
        }
        else if(j<n){
            while(j<n){
                ans[k]=nums2[j];
                j++;k++;
            }
        }
        nums1.resize(m+n);
        for(int i=0;i<(m+n);i++){
            nums1[i] = ans[i];
        }
    }
};