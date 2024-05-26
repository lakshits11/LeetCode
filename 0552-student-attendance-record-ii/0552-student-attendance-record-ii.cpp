static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store current sub-problem results.
        vector<vector<int>> dpCurrState = vector<vector<int>>(2, vector<int>(3, 0));
        // Cache to store next sub-problem results.
        vector<vector<int>> dpNextState = vector<vector<int>>(2, vector<int>(3, 0));

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dpCurrState[0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller sub-problem 
        // to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (int consecutiveLates = 0; consecutiveLates <= 2; ++consecutiveLates) {
                    // Store the count when 'P' is chosen.
                    dpNextState[totalAbsences][0] = (
                        dpNextState[totalAbsences][0] + 
                        dpCurrState[totalAbsences][consecutiveLates]
                    ) % MOD;
                    // Store the count when 'A' is chosen.
                    if (totalAbsences < 1) {
                        dpNextState[totalAbsences + 1][0] = (
                            dpNextState[totalAbsences + 1][0] + 
                            dpCurrState[totalAbsences][consecutiveLates]
                        ) % MOD;
                    }
                    // Store the count when 'L' is chosen.
                    if (consecutiveLates < 2) {
                        dpNextState[totalAbsences][consecutiveLates + 1] = (
                            dpNextState[totalAbsences][consecutiveLates + 1] + 
                            dpCurrState[totalAbsences][consecutiveLates]
                        ) % MOD;
                    }
                }
            }
            
            // Next state sub-problems will become current state sub-problems in next iteration.
            dpCurrState = dpNextState;
            // Next state sub-problem results will reset to zero.
            dpNextState = vector<vector<int>>(2, vector<int>(3, 0));
        }

        // Sum up the counts for all combinations of length 'n' with different absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (int consecutiveLates = 0; consecutiveLates <= 2; ++consecutiveLates) {
                count = (count + dpCurrState[totalAbsences][consecutiveLates]) % MOD;
            }
        }
        return count;
    }
};