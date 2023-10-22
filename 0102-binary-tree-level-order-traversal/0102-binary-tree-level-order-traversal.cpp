class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            while (n--)
            {
                TreeNode *tmp = q.front();
                q.pop();
                temp.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};