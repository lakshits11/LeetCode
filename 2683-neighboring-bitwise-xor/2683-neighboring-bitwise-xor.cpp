class Solution {
public:
    bool doesValidArrayExist(vector<int>& a) {
        return accumulate(a.begin(), a.end(), 0)%2==0;
    }
};