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
 static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<string> ans;

    void rec(TreeNode* root, string temp)
    {
        if(root == NULL) return;
        temp += to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }
        temp+="->";
        rec(root->left, temp);
        rec(root->right, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ans;
        rec(root, "");
        return ans;
    }
};