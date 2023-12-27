// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    // intuition: 
    // ---------------
    // if there are consecutive balloons with the same color, 
    // we want to keep the one with maximum neededTime and remove others 
    
    // if there are 2 balloons with different colors, ans = 0 as it is colorful
    // if there are 2 balloons with same color, ans = min(neededTime[0], neededTime[1])
    // if there are 3 consecutive balloons with same color, ans = sum(neededTime[0 .. 2]) - max(neededTime[0 .. 2])
    // if there are N consecutive balloons with same color, ans = sum(neededTime[0 .. n - 1]) - max(neededTime[0 .. n - 1])
    // we don't need to calculate the sum and subtract the max though. instead, we can either
    // 1. update neededTime in place to the max of neededTime[i] and neededTime[i - 1] (shown in below solution) or 
    // 2. store the current max time in a variable
    // why? let's say colors = "aaa" and neededTime = [1,2,1]
    // we first compare neededTime[0] and neededTime[1] and decide to remove the first balloon (neededTime[0] < neededTime[1])
    // now colors = "_aa" and neededTime = [_,2,1] and the current max time is 2
    // then compare neededTime[1] and neededTime[2] and decide to remove the last balloon, (neededTime[2] < neededTime[1])
    // now colors = "_a_" and neededTime = [_,2,_]. we remove all balloons but the one with maximum neededTime
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        for (int i = 1; i < n; i++) {
            // if the i-th balloon has the same color as (i - 1)th one
            // e.g. aba[a]c and i = 3 (0-based)
            if (colors[i] == colors[i - 1]) {
                // then we remove the one with less time
                // e.g. in above example, we remove the balloon at index 2 
                // with neededTime[2] since neededTime[2] < neededTime[3] 
                ans += min(neededTime[i], neededTime[i - 1]);
                // update the max neededTime inplace 
                // or alternatively you can store it in a variable
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return ans;
    }
};