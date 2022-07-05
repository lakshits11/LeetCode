class Solution {
private:
    vector<vector<int>> vis;
    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int i)
    {
        if(i == word.size())
            return true;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || word[i]!=board[r][c] || vis[r][c]==1)
            return false;
        vis[r][c] = 1;
        bool res = dfs(board, word, r+1, c, i+1) ||
            dfs(board, word, r-1, c, i+1) ||
            dfs(board, word, r, c+1, i+1) ||
            dfs(board, word, r, c-1, i+1) ;
        vis[r][c] = 0;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        vis.resize(board.size(), vector<int>(board[0].size(), 0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};