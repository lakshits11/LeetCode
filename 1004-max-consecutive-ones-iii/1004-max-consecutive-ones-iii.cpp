class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flip = 0;
        int ans = 0;
        int i = 0;  // help to move forward
        int j = 0;  // helper in unflipping
        
        while(i < nums.size())
        {
            if(nums[i] == 0)
                flip++;
            while(flip > k)
            {
                // unflip previous elements
                if(nums[j] == 0)
                    flip--;
                j++;
            }
            ans = max(ans, (i-j+1));
            i++;
        }
        return ans;
   
    }
};