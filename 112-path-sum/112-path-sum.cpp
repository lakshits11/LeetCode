
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        if (root->val == targetSum and root->left==NULL and root->right==NULL)
            return true;

        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left or right;
    }
};