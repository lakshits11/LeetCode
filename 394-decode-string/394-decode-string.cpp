// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        stack<int> countStack;
        stack<string> wordStack;
        int number = 0;
        string word = "";
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (isdigit(c))
            {
                number = number * 10 + (c - '0');
            }
            else if (isalpha(c))
            {
                word.push_back(c);
            }
            else if (c == '[')
            {
                countStack.push(number);
                wordStack.push(word);
                word = "";
                number = 0;
            }
            else
            {
                int count = countStack.top();
                countStack.pop();
                string temp = wordStack.top();
                wordStack.pop();
                for (int i = 0; i < count; i++)
                {
                    temp.append(word);
                }
                word = temp;
            }
        }
        return word;
    }
};