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
class FindElements {
public:
    vector<int> tt;
    void ino(TreeNode* root)
    {
        if(root==NULL)  return;
        ino(root->left);
        tt.push_back(root->val);
        ino(root->right);
    }
    void ff(TreeNode* root)
    {
        if(root==NULL)  return;
        if(root->val == -1)
            root->val = 0;
        if(root->left)
            root->left->val = 2*(root->val) + 1;
        if(root->right)
            root->right->val = 2*(root->val) + 2;
        ff(root->left);
        ff(root->right);
    }
    FindElements(TreeNode* root) {
        ff(root);
        ino(root);
        // for(int i=0;i<tt.size();i++)
        //     cout << tt[i] << " ";
        // cout << "\n";
        sort(tt.begin(), tt.end());
    }
    
    bool find(int target) {
        vector<int>::iterator low1 = lower_bound(tt.begin(), tt.end(), target);
        int x = low1-tt.begin();
        if(tt[x]==target)
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */