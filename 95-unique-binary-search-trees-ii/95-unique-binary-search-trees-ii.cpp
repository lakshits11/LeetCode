class Solution {
private:
    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> ans;
        if(start > end)
        {
            ans.push_back(NULL);
            return ans;
        }
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> left =  helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            
            for(TreeNode* l : left)
            {
                for(TreeNode* r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n)
    {
        return helper(1, n);
    }
};