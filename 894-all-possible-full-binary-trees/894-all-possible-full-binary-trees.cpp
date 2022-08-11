class Solution {
private:
    unordered_map<int, vector<TreeNode*>> u;

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        
        if(n<1 || n%2 == 0)
            return ans;
        if(u.find(n) != u.end())
            return u[n];
        if(n==1)
        {
            ans.push_back(new TreeNode(0));
            return u[1] = ans;
        }
        
        for(int i = 1; i < n; i+=2)
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);
            
            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k < right.size(); k++)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        
        return u[n] = ans;
    }
};