class Solution {
private:
    static bool comp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int n = pairs.size();
        int count = 0;
        vector<int> temp = pairs[0];
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || pairs[i][0] > temp[1])
            {
                temp = pairs[i];
                count++;
            }
        }
        return count;
    }
};