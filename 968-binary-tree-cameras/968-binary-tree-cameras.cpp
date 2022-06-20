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
    int sum = 0;
    
    /*
    Conditions:
    0 => Node not monitored
    1 => Node monitored but dont have camera on itself
    2 => Node has camera on itself
    */
    
    int dfs(TreeNode* node)
    {
        if(node==NULL)  return 1;
        int left = dfs(node->left), right = dfs(node->right);
        
        // If atleast one child is not monitored, we need to place a camera there
        if(left==0 || right==0){
            sum++;
            return 2;
        }
        
        else if(left==2 || right==2)    return 1;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        // If root isn't monitored, we place an additional camera there
        if(dfs(root)==0)   sum++;
        return sum;
    }
};