/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int qlen = q.size();
            vector<TreeNode *> rr;
            vector<int> temp;
            while (qlen--)
            {
                TreeNode *t = q.front();
                q.pop();
                rr.push_back(t);
                temp.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (level % 2)
            {
                int n = rr.size();
                reverse(temp.begin(), temp.end());
                for (int i = 0; i < n; ++i)
                {
                    rr[i]->val = temp[i];
                }
            }
            level = !level;
        }
        return root;
    }
};