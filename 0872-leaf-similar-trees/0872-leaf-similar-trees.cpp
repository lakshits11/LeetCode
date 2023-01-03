class Solution
{
public:
    vector<int> v1, v2;

    void traversal1(TreeNode* root)
    {
        if(root==NULL)  return;
        traversal1(root->left);
        if(root->left==NULL and root->right==NULL)
        {
            v1.push_back(root->val);
        }
        traversal1(root->right);
    }

    void traversal2(TreeNode* root)
    {
        if(root==NULL)  return;
        traversal2(root->left);
        if(root->left==NULL and root->right==NULL)
        {
            v2.push_back(root->val);
        }
        traversal2(root->right);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        traversal1(root1);
        traversal2(root2);
        if(v1==v2){
            return true;
        }
        return false;
    }
};