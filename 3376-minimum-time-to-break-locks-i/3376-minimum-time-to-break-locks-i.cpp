class Solution {
public:
    // Recursive function to solve the problem
    int solve(int mask, int x, int K, vector<int>& nums, int n) {
        // If all tasks are completed, return 0
        if (mask == (1 << n) - 1) {
            return 0;
        }

        int mini = INT_MAX;
        
        // Explore all tasks
        for (int i = 0; i < n; i++) {
            // If task i is not completed (not in the mask)
            if (!(mask & (1 << i))) {
                // Calculate time required to complete task i
                int time = (nums[i] + x - 1) / x;
                
                // Recursively compute the minimum time for the next task
                mini = min(mini, time + solve(mask | (1 << i), x + K, K, nums, n));
            }
        }

        return mini;
    }

    // Function to find the minimum time to complete all tasks
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();  // Number of tasks
        int x = 1;  // Initial value of x
        return solve(0, x, K, strength, n);  // Start with no tasks completed
    }
};