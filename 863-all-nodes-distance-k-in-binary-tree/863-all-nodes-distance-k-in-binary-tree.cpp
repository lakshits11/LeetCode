// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (!root)
            return ans;

        // node, parent
        unordered_map<TreeNode *, TreeNode *> u;
        queue<TreeNode *> q;
        set<TreeNode *> s;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == target)
                break;
            if (curr->left)
            {
                u[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                u[curr->right] = curr;
                q.push(curr->right);
            }
        }
        while(!q.empty()) q.pop();

        q.push(target);
        s.insert(target);
        while (k-- > 0)
        {
            if(q.empty()) return ans;
            int qlen = q.size();
            for(int i = 0; i < qlen; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left && s.find(curr->left) == s.end())
                {
                    q.push(curr->left);
                    s.insert(curr->left);
                }
                if (curr->right && s.find(curr->right) == s.end())
                {
                    q.push(curr->right);
                    s.insert(curr->right);
                }
                if (u.find(curr) != u.end() && s.find(u[curr]) == s.end())
                {
                    q.push(u[curr]);
                    s.insert(u[curr]);
                }
            }
        }
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};