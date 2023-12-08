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
    string t2s(TreeNode* root) {
        if(root==NULL) return "";
        if(!root->left && !root->right)
            return (to_string(root->val)+"");
        if(!root->right)
            return (to_string(root->val) + "("+ t2s(root->left) + ")");
        return (to_string(root->val) + "("+ t2s(root->left) + ")(" + t2s(root->right) + ")");
    }
    string tree2str(TreeNode* root)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        return t2s(root);
    }
};