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
    unordered_map<TreeNode*, int> u;

    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(u[root])
            return u[root];
        
        int robRoot = root->val;
        if(root->left){
            robRoot += rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            robRoot += rob(root->right->left)+rob(root->right->right);
        }
        
        int notRobRoot = rob(root->left) + rob(root->right);
        
        return u[root] = max(robRoot, notRobRoot);
    }
};