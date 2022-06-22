class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        // map of vertical -> level -> node
        map<int, map<int, multiset<int>>> mp;

        // queue of {node, vertical, level}
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(temp->val);
            if (temp->left)
                q.push({temp->left, {x - 1, y + 1}});
            if (temp->right)
                q.push({temp->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        // mp is <vertical, map>
        for (auto p : mp)
        {
            vector<int> col;
            // p.second => map<level, multiset>
            for (auto q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};