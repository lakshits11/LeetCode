class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            // We can also do => TreeNode* temp = s.top()
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
        }
        return ans;
    }
};