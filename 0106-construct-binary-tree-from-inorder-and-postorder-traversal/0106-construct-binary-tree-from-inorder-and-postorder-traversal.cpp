class Solution
{
public:
    TreeNode *build(vector<int> &post, int ps, int pe, vector<int> &ino, int is, int ie, unordered_map<int, int> &inMap)
    {
        if (pe < ps || is > ie)
            return NULL;
        TreeNode *root = new TreeNode(post[pe]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - is;

        root->left = build(post, ps, ps + numsLeft - 1, ino, is, inRoot - 1, inMap);
        root->right = build(post, ps + numsLeft, pe - 1, ino, inRoot + 1, ie, inMap);
        return root;
    }

    TreeNode *buildTree(vector<int> &ino, vector<int> &post)
    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < ino.size(); i++)
            inMap[ino[i]] = i;

        TreeNode *root = build(post, 0, post.size() - 1, ino, 0, ino.size() - 1, inMap);
        return root;
    }
};