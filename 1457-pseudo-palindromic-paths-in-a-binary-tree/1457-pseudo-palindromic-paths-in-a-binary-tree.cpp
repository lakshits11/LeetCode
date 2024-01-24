
class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root, int count = 0)
    {
        if (!root) return 0;
        // basically this is toggling the bit present at position root->val.
        count ^= 1 << (root->val-1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        // At the leaf node, check if the count has only one bit that is 1.
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
};