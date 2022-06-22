class Solution
{
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentt)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                parentt[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                parentt[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // Map to keep track of parents
        unordered_map<TreeNode *, TreeNode *> parentt;
        markParents(root, parentt);

        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        q.push(target);
        vis[target] = true;
        int curr_level = 0;

        while (!q.empty())
        {
            int qlen = q.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < qlen; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                if (current->left && !vis[current->left])
                {
                    q.push(current->left);
                    vis[current->left] = true;
                }
                if (current->right && !vis[current->right])
                {
                    q.push(current->right);
                    vis[current->right] = true;
                }
                if (parentt[current] && !vis[parentt[current]])
                {
                    q.push(parentt[current]);
                    vis[parentt[current]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};