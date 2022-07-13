/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> t;
            int qlen = q.size();
            while(qlen--)
            {
                TreeNode* temp = q.front();
                q.pop();
                t.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(t);
            
        }
        return ans;
    }
};