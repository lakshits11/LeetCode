class Solution {
public:
    vector<vector<int>> ans;
    void rec(int i, vector<int> &cand, int k, vector<int> &temp)
    {
        if(k == 0) {
            ans.push_back(temp);
            return;
        }
        if(i == cand.size()) return;

        // Exclude
        rec(i+1, cand, k, temp);
        
        // include
        if(k-cand[i]>=0) {
            temp.push_back(cand[i]);
            rec(i, cand,k-cand[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int k) {
        vector<int> temp;
        rec(0, cand, k, temp);
        return ans;
    }
};