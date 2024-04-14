class Solution {
public:
    int sum = 0;
    void traverse(TreeNode* root, int nodePoint) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(nodePoint == 1) {
                sum += root->val;
            }
        }
        if(root->left != NULL) {
            traverse(root->left, 1);
        }
        if(root->right != NULL) {
            traverse(root->right, 0);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root, 0);
        return sum;
    }
};