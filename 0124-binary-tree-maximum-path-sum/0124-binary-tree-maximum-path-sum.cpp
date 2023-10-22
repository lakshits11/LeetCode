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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        fun(root, maxi);
        return maxi;
    }
    
    int fun(TreeNode* root, int &maxi)
    {
        if(root==NULL) return 0;
        int left = max(0, fun(root->left, maxi));
        int right = max(0, fun(root->right, maxi));
        maxi = max(maxi, root->val + left + right);
        return max(left, right) + root->val;
        
    }
};