static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

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
    int getNum(int &i, string &t)
    {
        string temp = "";
        while(i<t.size() && t[i]!='-')
        {
            temp+=t[i++];
        }
        return stoi(temp);
    }

    TreeNode* recoverFromPreorder(string t) {
        if(t.size() == 0) return nullptr;

        stack<pair<int, TreeNode*>> st;
        int i = 0;
        
        while(i<t.size())
        {
            int depth = 0;

            // calculate depth of next node
            while(i<t.size() && t[i] == '-')
            {   
                i++;
                depth++;
            }

            // Extract Number
            int num = getNum(i, t);
            
            // Create new node
            TreeNode* node = new TreeNode(num);

            // if stack is not empty, find correct parent
            while(!st.empty() && st.top().first >= depth)
                st.pop();
            
            // if stack is not empty, attach node to left or right child
            if(!st.empty())
            {
                TreeNode* parent = st.top().second;
                if(!parent->left) parent->left = node;
                else parent->right = node;
            }

            // push created node into stack
            st.push({depth, node});
        }

        // root is at bottom of stack
        while(st.size()>1) st.pop();

        return st.top().second;
    }
};