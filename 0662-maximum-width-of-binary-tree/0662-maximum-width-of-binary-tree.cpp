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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int sz = q.size();
            int mini = q.front().second;
            int f, l;
            for(int i=0;i<sz;i++)
            {
                long currId = q.front().second - mini;
                TreeNode* curr = q.front().first;
                q.pop();
                if(i==0) f=currId;
                if(i==sz-1) l=currId;
                if(curr->left) q.push({curr->left, currId*2+1});
                if(curr->right) q.push({curr->right, currId*2+2});
            }
            ans=max(ans, l-f+1);
        }
        return ans;
    }
};