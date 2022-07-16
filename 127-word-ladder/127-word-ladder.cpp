class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int changes = 1;
        
        unordered_set<string> vis;
        vis.insert(beginWord);
        
        while(!q.empty())
        {
            int qlen = q.size();
            for(int i=0; i<qlen; ++i)
            {
                string temp = q.front();
                q.pop();
                if(temp == endWord)
                    return changes;
                for(int j=0; j<temp.size(); ++j)
                {
                    for(char k='a'; k<='z'; ++k)
                    {
                        string temp2 = temp;
                        temp2[j] = k;
                        if(st.find(temp2) != st.end() && vis.find(temp2)==vis.end())
                        {
                            q.push(temp2);
                            vis.insert(temp2);
                        }
                    }
                }
                
            }
            changes++;
        }
        return 0;
    }
};