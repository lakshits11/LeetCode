// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/solutions/4778582/c-100-faster-easy-step-by-step-explanation

#define ll long long

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>> &b) {
        ll area = 0;
        for(int i = 0; i < a.size();++i)
        {
            for(int j = i+1; j < b.size(); ++j)
            {
                ll minX = max(a[i][0], a[j][0]);
                ll maxX = min(b[i][0], b[j][0]);
                ll minY = max(a[i][1], a[j][1]);
                ll maxY = min(b[i][1], b[j][1]);

                if(minX<maxX && minY<maxY)
                {
                    long long s = min(maxX-minX, maxY-minY);
                    area = max(area, s*s);
                }
            }
        }
        return area;
    }
};