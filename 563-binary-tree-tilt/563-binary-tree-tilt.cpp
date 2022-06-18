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
    int diff = 0;
    int sumtotal(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        int l = sumtotal(root->left);
        int r = sumtotal(root->right);
        diff += abs(l-r);
        return root->val + l + r;
    }
    int findTilt(TreeNode* root) {
        sumtotal(root);
        return diff;
    }
};