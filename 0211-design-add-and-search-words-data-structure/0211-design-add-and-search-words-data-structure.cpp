// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *arr[26];
    bool isEnd;
};

class WordDictionary
{
private:
    Node *root;
    bool find(Node *curr, string word, int ind)
    {
        if (!curr)
            return false;
        char ch = word[ind];
        if (ind == word.size() - 1)
        {
            if (ch == '.')
            {
                for (int i = 0; i < 26; i++)
                {
                    if (curr->arr[i] != NULL && curr->arr[i]->isEnd == true)
                        return true;
                }
                return false;
            }
            else
            {
                if (curr->arr[ch - 'a'] != NULL && curr->arr[ch - 'a']->isEnd == true)
                    return true;
                return false;
            }
        }

        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (curr->arr[i] != NULL && find(curr->arr[i], word, ind + 1))
                    return true;
            }
            return false;
        }
        else
        {
            if (curr->arr[ch - 'a'] == NULL)
                return false;
            return find(curr->arr[ch - 'a'], word, ind + 1);
        }
    }

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (curr->arr[c - 'a'] == NULL)
                curr->arr[c - 'a'] = new Node();
            curr = curr->arr[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        return find(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */