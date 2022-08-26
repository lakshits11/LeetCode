class Solution
{
private:
    unordered_map<long long, long long> u;
    long long ans = 0;
    void pre(TreeNode *root, long long sum, long long k)
    {
        if (root == NULL)
            return;
        sum += root->val;
        if (sum == k)
            ans++;
        if (u.find(sum - k) != u.end())
            ans += u[sum-k];
        u[sum]++;
        pre(root->left, sum, k);
        pre(root->right, sum, k);
        u[sum]--;
    }

public:
    int pathSum(TreeNode *root, int ts)
    {
        if (root == NULL)
            return 0;
        long long sum = 0;
        long long k = ts;
        pre(root, sum, k);
        return ans;
    }
};