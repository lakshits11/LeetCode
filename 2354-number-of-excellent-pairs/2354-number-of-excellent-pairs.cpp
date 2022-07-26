class Solution {
private:
    int f(int n, long long &ans, int &k)
    {
        int count = 0;
        while(n)
        {
            count++;
            n = n&(n-1);
        }
        if(2*count >= k)
            ans++;
        return count;
    }
public:
    long long countExcellentPairs(vector<int>& nums, int k)
    {
        long long ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        nums.clear();
        for(int x : s)
        {
            nums.push_back(f(x, ans, k));
        }
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]>=k)
            {
                // if i and j satisfy the condition, then all the numbers in between i and j will also satisfy the condition
                ans += (j-i)*2;
                j--;
            }
            else i++;
        }
        return ans;
    }
};