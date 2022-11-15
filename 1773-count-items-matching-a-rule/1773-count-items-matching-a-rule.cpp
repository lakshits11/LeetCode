class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> u;
        u["type"] = 0;
        u["color"] = 1;
        u["name"] = 2;
        int count = 0;
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i][u[ruleKey]] == ruleValue)
                count++;
        }
        return count;
    }
};