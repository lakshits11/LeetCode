class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for(int i:nums) freq[i]++;
        for(int i : nums)
        {
            if(freq.count(i-1)>0) ans=max(ans,freq[i]+freq[i-1]);
            if(freq.count(i+1)>0) ans=max(ans, freq[i]+freq[i+1]);
        }
        return ans;
    }
};