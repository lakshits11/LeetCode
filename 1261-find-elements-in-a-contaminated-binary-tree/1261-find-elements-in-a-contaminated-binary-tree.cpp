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
    unordered_set<int> s;
    void rec(TreeNode* root, int val)
    {
        if(root == NULL) return;
        // root->val = val;
        s.insert(val);
        if(root->left) rec(root->left, 2*val+1);
        if(root->right) rec(root->right, 2*val+2);
    }
    FindElements(TreeNode* root) {
        rec(root, 0);
    }
    
    bool find(int k) {
        if(s.find(k)!=s.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */