// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // count frequency of each character in a word
    vector<int> countFreq(string &word)
    {
        vector<int> freq(26);
        for (auto &c : word)
            freq[c - 'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        vector<int> Maxfreq(26); // maintains minimum freq of each char required for a word to be universal word
        vector<string> ans;
        for (auto &word : B)
        {
            vector<int> freq = countFreq(word);
            for (int i = 0; i < 26; i++)
                Maxfreq[i] = max(Maxfreq[i], freq[i]);
        }
        for (auto &word : A)
        {
            vector<int> freq = countFreq(word);
            int i = 0;
            for (; i < 26; i++)
                if (freq[i] < Maxfreq[i])
                    break;
            if (i == 26)
                ans.push_back(word);
        }
        return ans;
    }
};