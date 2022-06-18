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
    int maxDepth(Node* root) {
        if(root==NULL)  return 0;
        int temp = 0;
        for(Node* x : root->children)
        {
            temp = max(temp, maxDepth(x));
        }
        return 1+temp;
    }
};