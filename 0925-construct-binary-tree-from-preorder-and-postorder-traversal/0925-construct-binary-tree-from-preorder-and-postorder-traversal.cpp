// SEE NOTES FOR DETAILED SOLUTION

// or your posted solution

class Solution {
public:
    vector<int> ps;

    TreeNode* buildTree(int preStart, int preEnd, int postStart, int postEnd, vector<int>& pre)
    {
        if(preStart>preEnd || postStart>postEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preStart]); 
        if(preStart == preEnd)
            return root;

        int leftRootVal = pre[preStart+1];
        int leftRootIndexInPost = ps[leftRootVal];

        int leftSubTreeSize = leftRootIndexInPost - postStart + 1;

        // recursively build left and right subtree
        root->left = buildTree(preStart+1, preStart+leftSubTreeSize, postStart, leftRootIndexInPost, pre);
        root->right = buildTree(preStart+leftSubTreeSize+1, preEnd, leftRootIndexInPost+1, postEnd-1, pre);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        ps.resize(n+1, -1);
        for(int i=0;i<n;i++)
        {
            ps[post[i]] = i;
        }
        return buildTree(0, n-1, 0, n-1, pre);
    }
};