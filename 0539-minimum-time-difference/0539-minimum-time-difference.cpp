class Solution {
public:
    int converter(string time)
    {
        return stoi(time.substr(0, 2))*60 + stoi(time.substr(3, 2));
    }
    int findMinDifference(vector<string>& t) {
        vector<int> tx(t.size());
        for(int i = 0; i < t.size(); i++)
        {
            tx[i] = converter(t[i]);
        }
        sort(tx.begin(), tx.end());
        int mini = INT_MAX;
        for(int i = 0; i < tx.size(); i++)
        {
            int a = tx[i], b = tx[(i+1)%tx.size()];
            mini = min(mini, min(abs(a-b), abs(1440-max(a,b)+min(a,b))));
        }
        return mini;
        
    }
};