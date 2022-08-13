class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> mp;
        int count = 0;
        for(char &c : tasks)
        {
            mp[c]++;
            count = max(count, mp[c]);
        }
        
        int ans = (count-1)*(n+1);
        for(pair<int, int> x : mp)
        {
            if(x.second == count)
                ans++;
        }
        return max((int)tasks.size(), ans);
    }
};