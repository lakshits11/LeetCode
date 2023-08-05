class Solution
{
public:
    TreeNode *copy_tree(TreeNode *root, int inc)
    {
        if (!root)
            return nullptr;
        TreeNode *new_root = new TreeNode(root->val + inc);
        new_root->left = copy_tree(root->left, inc);
        new_root->right = copy_tree(root->right, inc);
        return new_root;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        ios_base::sync_with_stdio(false);
        vector<vector<TreeNode *>> tb(n + 1);
        tb[0].push_back(nullptr);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                for (auto l_it = tb[j - 1].begin(); l_it != tb[j - 1].end(); ++l_it)
                {
                    for (auto r_it = tb[i - j].begin(); r_it != tb[i - j].end(); ++r_it)
                    {
                        tb[i].push_back(new TreeNode(j));
                        tb[i].back()->left = copy_tree(*l_it, 0);
                        tb[i].back()->right = copy_tree(*r_it, j);
                    }
                }
            }
        }

        return tb[n];
    }
};