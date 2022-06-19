class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int qlen = q.size();
            vector<int> temp(qlen);
            for (int i = 0; i < qlen; i++)
            {
                TreeNode *t = q.front();
                q.pop();

                int index = leftToRight ? i : (qlen - i - 1);
                temp[index] = t->val;

                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }

            // after this level, we need to flip  boolean 'leftToRight'
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }

        return ans;
    }
};