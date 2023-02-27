/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
    
    Node* helper(vector<vector<int>>& grid, int row, int col, int size) {
        if (size == 1) {
            return new Node(grid[row][col], true, nullptr, nullptr, nullptr, nullptr);
        }
        
        Node* topLeft = helper(grid, row, col, size / 2);
        Node* topRight = helper(grid, row, col + size / 2, size / 2);
        Node* bottomLeft = helper(grid, row + size / 2, col, size / 2);
        Node* bottomRight = helper(grid, row + size / 2, col + size / 2, size / 2);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) {
            if (topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
                return new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);
            }
        }
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};