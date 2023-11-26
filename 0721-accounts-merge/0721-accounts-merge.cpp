class Solution {
public:
    vector<int> parent;
    int findP(int u)
    {
        if(u==parent[u]) return u;
        return parent[u] = findP(parent[u]);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = accounts.size();
        parent = vector<int>(n, 0);
        unordered_map<string, int> emailId;
        // ek hi person ki email ids ko ek common parent ko assign kr rhe hai
        // emailId ek superior hashmap hai to group all similar emails together
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(emailId.find(mail) != emailId.end())
                {
                    // basically since we get a seen email id, that means wo pura accounts[i] ka same parent hoga.
                    // wo parent emailId[mail] ke parent ke baraabar hoga
                    int parent1 = findP(emailId[mail]);
                    int parent2 = findP(i);
                    parent[parent1] = parent2;
                }
                else 
                    emailId[mail] = parent[i];
            }
        }
        
        // sab ek hi parent waale accounts ke emails ko ek saath kr rhe
        unordered_map<int, vector<string>> newAccounts;
        for(auto &e : emailId)
        {
            newAccounts[findP(e.second)].push_back(e.first);
        }
        
        vector<vector<string>> ans;
        for(auto &a : newAccounts)
        {
            auto &emails = a.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[a.first][0]);
            ans.push_back(emails);
        }
        return ans;
    }
};