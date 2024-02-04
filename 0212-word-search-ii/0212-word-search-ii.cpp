// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *arr[26];
    bool isEnd;
    string *word;

    TrieNode()
    {
        isEnd = false;
        memset(arr, 0, sizeof(arr));
        word = nullptr;
    }
};

int dir[5] = {0, 1, 0, -1, 0};
class Solution
{
public:
    TrieNode *root;
    vector<string> ans;
    void addNode(string &s)
    {
        TrieNode *temp = root;
        for (int i = 0; i < s.size(); ++i)
        {
            if (temp->arr[s[i] - 'a'] == NULL)
                temp->arr[s[i] - 'a'] = new TrieNode();
            temp = temp->arr[s[i] - 'a'];
        }
        temp->isEnd = true;
        temp->word = &s;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *curr)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#' || curr->arr[board[i][j] - 'a'] == NULL)
            return;
        char originalChar = board[i][j];
        curr = curr->arr[originalChar - 'a'];
        if (curr->isEnd)
        {
            ans.push_back(*curr->word);
            curr->word = nullptr;
            curr->isEnd = false;
        }
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k)
            dfs(board, i + dir[k], j + dir[k + 1], curr);
        board[i][j] = originalChar;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        root = new TrieNode();
        for (string &s : words)
            addNode(s);
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                dfs(board, i, j, root);
        return ans;
    }
};