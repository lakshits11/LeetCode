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
    void inorder(TreeNode* root, vector<int> &vv)
    {
        if(root==NULL)  return;
        inorder(root->left, vv);
        if(root->left == NULL && root->right == NULL)
            vv.push_back(root->val);
        inorder(root->right, vv);
    }
        
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        inorder(root1, l1);
        inorder(root2, l2);
        return l1==l2;
    }
};