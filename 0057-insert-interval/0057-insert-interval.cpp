class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& time) {
        arr.push_back({time[0], time[1]});
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i][0] <= ans.back().back())
                ans.back().back() = max(ans.back().back(), arr[i][1]);
            else ans.push_back(arr[i]);
        }
        return ans;
    }
};