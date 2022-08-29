/*

-1 => you need a camera
0  => you have a camera
1  => you are covered

*/

class Solution {
private:
    int camera = 0;
    
    int f(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        int lchild = f(root->left);
        int rchild = f(root->right);
        
        if(lchild == -1 || rchild == -1)
        {
            camera++;
            return 0;
        }
        
        if(lchild == 0 || rchild == 0)
            return 1;
        
        return -1;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        if(f(root) == -1)
            camera++;
        return camera;
    }
};