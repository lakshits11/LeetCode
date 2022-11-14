class Solution {
public:
    int distributeCandies(vector<int>& can) {
        unordered_map<int, int> u;
        for(int i : can)
        {
            u[i]++;
        }
        int n = can.size()/2;
        int x = u.size();
        return min(n,x);
    }
};