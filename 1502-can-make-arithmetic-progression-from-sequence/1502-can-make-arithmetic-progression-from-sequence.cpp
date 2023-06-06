class Solution {
    public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int difference = arr[1]-arr[0];
        for(int itr = 2; itr < arr.size(); itr++){
            if(arr[itr]-arr[itr-1] != difference) return false;
        }
        return true;
    }
};