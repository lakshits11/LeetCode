class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rect) {
        int maxLen = INT_MIN;
        for(int i = 0; i < rect.size(); i++)
        {
            maxLen = max(min(rect[i][0], rect[i][1]), maxLen);
        }
        int count = 0;
        for(int i = 0; i < rect.size(); i++)
        {
            if(maxLen == min(rect[i][0], rect[i][1])) count++;
        }
        return count;
    }
};