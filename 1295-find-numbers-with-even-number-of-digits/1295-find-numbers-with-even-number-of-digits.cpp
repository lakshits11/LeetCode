class Solution {
public:
    int nd(int n)
    {
        int ans = 0;
        while(n){
            n /= 10;
            ans++;
        }
        return ans;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int &i : nums)
        {
            if(nd(i)%2==0) count++;
        }
        return count;
    }
};