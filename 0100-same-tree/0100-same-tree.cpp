static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((!p&&q) || (p&&!q)) return false;
        if(p->val!=q->val) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};