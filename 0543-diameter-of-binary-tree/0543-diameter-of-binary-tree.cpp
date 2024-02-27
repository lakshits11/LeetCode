static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution
{
public:
    int dfs(TreeNode *root, int& diameter)
    {
        if (root == NULL)
            return 0;
        
        int leftLen = dfs(root->left, diameter);
        int rightLen = dfs(root->right, diameter);
        diameter = max(diameter, leftLen+rightLen);

        return max(leftLen, rightLen)+1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter=0;
        dfs(root, diameter);
        return diameter;
    }
};