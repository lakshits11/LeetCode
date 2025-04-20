class Solution {
public:
    int numRabbits(vector<int>& arr) {
        if(arr.empty()) return 0;
        int ans = 0;
        unordered_map<int, int> u;
        for(int i : arr)
        {
            if(i == 0) ans++;
            else {
                if(u[i] == 0) ans += i+1;
                u[i]++;
                if(u[i]==i+1) u[i]=0;
            }
        }
        return ans;
    }
};