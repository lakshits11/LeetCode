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
    bool f(int x, TreeNode* root)
    {
        if(root==NULL)
            return true;
        return (x==root->val && f(x, root->left) && f(x,root->right));
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        return f(root->val, root->left) && f(root->val, root->right);
        
    }
};