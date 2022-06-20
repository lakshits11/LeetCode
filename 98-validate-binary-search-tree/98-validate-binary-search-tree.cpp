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
    long long INF = 100000000000;
    bool valid(TreeNode* root, long long left, long long right)
    {
        if(root==NULL)  return true;
        if(root->val >= right || root->val <= left)
            return false;
        
        return valid(root->left, left, root->val) &&
            valid(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        return valid(root, -INF, INF);
    }
};





