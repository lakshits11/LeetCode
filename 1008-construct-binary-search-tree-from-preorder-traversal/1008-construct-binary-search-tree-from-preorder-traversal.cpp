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
    TreeNode* bstFromPreorder(vector<int>& pr) {
        int size = pr.size();
        return buildIt(pr,0,size-1);
    }
    TreeNode*buildIt(vector<int>&pr,int left,int right)
    {
        if(left>right)
            return NULL;
        TreeNode*t = new TreeNode();
        t->val =  pr[left];
        int i=left+1;
        while(i<pr.size() && pr[i]<=pr[left])
            i++;
        t->left = buildIt(pr,left+1,i-1);
        t->right = buildIt(pr,i,right);
        return t;
        
        
    }
};