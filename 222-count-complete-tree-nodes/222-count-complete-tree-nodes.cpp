class Solution
{
public:
    int findHeightLeft(TreeNode *root)
    {
        int ht = 0;
        while (root)
        {
            ht++;
            root = root->left;
        }
        return ht;
    }
    int findHeightRight(TreeNode *root)
    {
        int ht = 0;
        while (root)
        {
            ht++;
            root = root->right;
        }
        return ht;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
