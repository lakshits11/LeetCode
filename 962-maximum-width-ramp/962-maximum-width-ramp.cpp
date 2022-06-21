class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        int rMax[n];
        rMax[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rMax[i] = max(rMax[i + 1], A[i]);
        }
        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            while (left < right && A[left] > rMax[right]) {
              left++;
            }
            ans = max(ans, right - left);
            right++;
        }
        return ans;
    }
};