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
    
    int mps(TreeNode* root, int &mx)
    {
        if(root==NULL)  return 0;
        int l = mps(root->left, mx);
        int r = mps(root->right, mx);
        if(l<0) l=0;if(r<0) r=0;
        mx = max(mx, l+r+root->val);
        return root->val + max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        mps(root, mx);
        return mx;
    }
};