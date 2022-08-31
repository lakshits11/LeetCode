/*
My analysis:

// floor starts from 0
if floor = 0, then ans is 0 (base case)
if(floor = 1) then ans is 1 (drop it from 1st floor, if it breaks, then 0 is pivotal floor)

also if totalEggs == 1:
    then we have to actually check from below to up for each floor at which floor the egg breaks

SO finally 2 base cases:
if(givenfloors == 0 || givenfloors == 1)
    retuen givenfloors;
if(totalEggs == 1)
    return totalFloors;

*/




class Solution {
private:
    vector<vector<int>> dp;
    int solve(int e, int f)
    {
        if(f == 0 || f == 1 || e == 1)
            return f;
        if(dp[e][f] != -1)
            return dp[e][f];
        int mini = INT_MAX;
        int lo = 1, hi = f, temp = 0;
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            int t1 = solve(e-1, mid-1);
            int t2 = solve(e, f-mid);
            
            temp = 1 + max(t1, t2);
            
            if(t1 < t2)
                lo = mid + 1;
            else
                hi = mid - 1;
            
            mini = min(mini, temp);
        }
        
        return dp[e][f] = mini;
    }
public:
    int superEggDrop(int e, int f)
    {
        dp = vector<vector<int>>(e+1, vector<int>(f+1, -1));
        return solve(e, f);
    }
};