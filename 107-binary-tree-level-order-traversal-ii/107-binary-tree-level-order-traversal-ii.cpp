class Solution {
public:
    int depth(TreeNode* root)
    {
        if(root==NULL)  return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    void levelO(vector<vector<int>> &ans, TreeNode* node, int level)
    {
        if(node==NULL)  return;
        ans[level].push_back(node->val);
        levelO(ans, node->left, level-1);
        levelO(ans, node->right, level-1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        int d = depth(root);
        vector<vector<int>> ans(d, vector<int> {});
        levelO(ans, root, d-1);
        return ans;
    }
};