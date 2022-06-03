class Solution {
public:
    int jump(vector<int>& nums) {
	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
    
    // loop till last jump hasn't taken us till the end
	while(lastJumpedPos < n - 1) 
    {  
        // furthest index reachable on the next level from current level
		maxReachable = max(maxReachable, i + nums[i]);  
        // current level has been iterated & maxReachable position on next level has been finalised
		if(i == lastJumpedPos) 
        {			  
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level
	        // NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
	        // This ensures jumps will only store minimum jump required to reach lastJumpedPos
		}            
		i++;
	}
	return jumps;
}
};