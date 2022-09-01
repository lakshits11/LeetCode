class Solution {
private:
    int f(TreeNode* root, int ma)
    {
        if(root == NULL) return 0;
        int res = 0;
        if(root->val >= ma)
        {
            res = 1;
            ma = root->val;
        }
        res += f(root->left, ma);
        res += f(root->right, ma);
        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return f(root, -10000);
    }
};