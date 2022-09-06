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
    bool isLeaf(TreeNode* root)
    {
        if(!root) return false;
        return !root->left && !root->right;
    }
    TreeNode* pruneTree(TreeNode* root)
    {
        if(root==NULL) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(isLeaf(root) && root->val==0)
            return NULL;
        return root;
        
    }
};