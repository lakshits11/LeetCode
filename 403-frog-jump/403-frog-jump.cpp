class Solution {
public:
    
    /*
    // RECURSIVE FUNCTION
    bool f(vector<int> &stones, int lastIndex, int currIndex, int &n)
    {
        // it means we have reached to end to array
        if(currIndex==n)
            return true;
        
        int lastJump = stones[currIndex] - stones[lastIndex];
        
        // nextIndex will be the currentIndex+1
        int nextIndex = currIndex+1;
        
        // we will call recursive function and check and then increment it
        while(nextIndex < n && stones[nextIndex] <= stones[currentIndex] + lastJump + 1)
        {
            int nextJump = stones[nextIndex] - stones[currIndex];
            int jump = nextJump - lastJump;
            
            if(jump>=-1 && jump<=1){
                if(f(stones, currIndex, nextIndex, n)){
                    return true;
                }
            }
            
            nextIndex++;
        }
        
        return false;
        
    }
    // now here the recursive function, there will be many same combinations of lastIndex and currIndex, so we maintain a 2d array to store if we have already calculated that value or not.
    */
    
    // MEMOIZATION
    bool f(vector<int> &stones, int lastIndex, int currIndex, int &n, vector<vector<bool>> &dp)
    {
        // it means we have reached to end to array
        if(currIndex==n-1)
            return true;
        
        // it measn we have already calculated these values and they didnt reached to last stone
        // thats why we are again here, so we return false
        if(dp[lastIndex][currIndex])
            return false;
        
        int lastJump = stones[currIndex] - stones[lastIndex];
        
        // nextIndex will be the currentIndex+1
        int nextIndex = currIndex+1;
        
        // we will call recursive function and check and then increment it
        while(nextIndex < n && stones[nextIndex] <= stones[currIndex] + lastJump + 1)
        {
            int nextJump = stones[nextIndex] - stones[currIndex];
            int jump = nextJump - lastJump;
            
            if(jump>=-1 && jump<=1){
                if(f(stones, currIndex, nextIndex, n, dp)){
                    return true;
                }
            }
            
            nextIndex++;
        }
        dp[lastIndex][currIndex] = true;
        
        return false;
        
    }
    
    
    bool canCross(vector<int>& stones) {
        ios_base::sync_with_stdio(0);
        if(stones[1]!=1)
            return false;
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        return f(stones, 0, 1, n, dp);
    }
};