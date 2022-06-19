class Solution
{
public:
    TreeNode *build(vector<int> &pr, int l, int r)
    {
        if (l > r)
            return NULL;
        TreeNode *node = new TreeNode(pr[l]);
        int i = l + 1;
        while (i <= r && pr[i] <= pr[l])
            i++;
        node->left = build(pr, l + 1, i - 1);
        node->right = build(pr, i, r);
        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &pr)
    {
        int sz = pr.size();
        return build(pr, 0, sz - 1);
    }
};