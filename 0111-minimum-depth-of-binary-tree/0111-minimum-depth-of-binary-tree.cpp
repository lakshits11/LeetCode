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
    int heightt(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int L = heightt(root->left);
        int R = heightt(root->right);
        return 1 + (L && R ? min(L,R) : max(L,R));
    }
    int minDepth(TreeNode* root) {
        // if(root==NULL)
        //     return 0;
        return heightt(root);
    }
};