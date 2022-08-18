bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> st;
        for(int i : arr)
            st[i]++;
        vector<pair<int, int>> v;
        for(pair<int, int> x : st)
        {
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(), comp);
        int n = arr.size();
        int ans = 0;
        int curr = 0;
        for(pair<int, int> x : v)
        {
            curr += x.first;
            ans++;
            if(curr >= n/2)
                return ans;
        }
        return st.size();
    }
};