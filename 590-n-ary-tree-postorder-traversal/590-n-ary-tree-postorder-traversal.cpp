/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    
    void post(Node* root)
    {
        if(root==NULL)  return;
        for(auto x : root->children)
        {
            post(x);
            ans.push_back(x->val);
        }
    }
    
    vector<int> postorder(Node* root) {
        if(root==NULL)  return ans;
        post(root);
        ans.push_back(root->val);
        return ans;
    }
};