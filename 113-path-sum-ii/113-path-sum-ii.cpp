class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> temp;
    void pre(TreeNode *root, int sum, int k)
    {
        if(root==NULL)
        {
            // temp.pop_back();
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if (sum == k && !root->left && !root->right)
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        pre(root->left, sum, k);
        pre(root->right, sum, k);
        temp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int k)
    {
        if (root == NULL)
            return ans;
        pre(root, 0, k);
        return ans;
    }
};