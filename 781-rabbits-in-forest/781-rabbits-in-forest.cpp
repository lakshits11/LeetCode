class Solution {
public:
    int numRabbits(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        unordered_map<int, int> m;
        int res = 0;
        for(int x : arr)
        {
            if(x == 0)
                res ++;
            else {
                if(m[x] == 0)
                    res += x+1;
                m[x]++;
                if(m[x] == x+1)
                    m[x] = 0;
            }
        }
        return res;
    }
};