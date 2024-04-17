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
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        queue<pair<TreeNode*, string>> nodeQueue;

        // Add root node to queue along with its value converted to a character
        nodeQueue.push({root, string(1, root->val + 'a')});

        // Perform BFS traversal until queue is empty
        while (!nodeQueue.empty()) {

            // Pop the leftmost node and its corresponding string from queue
            auto[node, currentString] = nodeQueue.front();
            nodeQueue.pop();

            // If current node is a leaf node
            if (!node->left && !node->right) {

                // Update smallest_string if it's empty or current string is smaller
                if (smallestString.empty()) {
                    smallestString = currentString;
                } else {
                    smallestString = min(smallestString, currentString);
                }
            }

            // If current node has a left child, append it to queue
            if (node->left) {
                nodeQueue.push({node->left, char(node->left->val + 'a') + currentString});
            }

            // If current node has a right child, append it to queue
            if (node->right) {
                nodeQueue.push({node->right, char(node->right->val + 'a') + currentString});
            }
        }

        return smallestString;
    }
};