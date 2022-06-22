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
    void ino(TreeNode* root, string temp, vector<string> &ans)
    {
        if(root==NULL)  return;
        temp += to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(temp);
            return;   
        }
        temp+="->";
        ino(root->left, temp, ans);
        ino(root->right, temp, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL)  return ans;
        ino(root, "", ans);
        return ans;
    }
};