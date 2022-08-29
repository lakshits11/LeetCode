class Solution {
private:
    int steps = 0;
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l = f(root->left), r = f(root->right);
        steps += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        f(root);
        return steps;
    }
};