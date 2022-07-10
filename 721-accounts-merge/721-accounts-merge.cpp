class Solution
{
private:
    vector<int> parent;
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        parent = vector<int>(n);
        unordered_map<string, int> emailId;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initialise union find
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (emailId.find(accounts[i][j]) != emailId.end())
                    parent[findParent(emailId[accounts[i][j]])] = findParent(i);
                else
                    emailId[accounts[i][j]] = parent[i];
            }
        }

        unordered_map<int, vector<string>> newAccounts;
        for (auto &e : emailId)
            newAccounts[findParent(e.second)].push_back(e.first);
        vector<vector<string>> ans;
        for (auto &a : newAccounts)
        {
            auto &emails = a.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[a.first][0]);
            ans.emplace_back(emails);
        }
        return ans;
    }
};