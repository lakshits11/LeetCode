class Solution {
public:
    static const bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int ts) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for(int i=0;i<boxTypes.size();i++)
        {
            if(boxTypes[i][0]<ts){
                ans += boxTypes[i][0]*boxTypes[i][1];
                cout << ans << "\n";
                ts-=boxTypes[i][0];
            }
            else if(ts>0){
                ans += ts*boxTypes[i][1];
                cout << ans << "\n";
                break;
            }
            if(ts==0)
            break;
        }
        return ans;
    }
};