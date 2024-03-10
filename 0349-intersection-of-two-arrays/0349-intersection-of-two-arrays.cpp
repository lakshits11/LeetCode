class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1[1001] = {};
        int n2[1001] = {};
        for(int i=0;i<nums1.size();i++)
            n1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            n2[nums2[i]]++;
        vector<int> ans;
        for(int i=0;i<=1000;i++)
        {
            if(n1[i]!=0 && n2[i]!=0)
                ans.push_back(i);
        }
        return ans;
    }
};