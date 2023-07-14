class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> length;
        int result = 1;
        for(int &i : arr)
        {
            result = max(result, length[i]=1+length[i-difference]);
        }
        return result;
    }
};