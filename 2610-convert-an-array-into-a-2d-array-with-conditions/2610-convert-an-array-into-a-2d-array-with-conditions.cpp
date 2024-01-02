class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int count[201] = {};
        memset(count, 0, sizeof(count));
        for(int &i:nums)
        {
            ++count[i];
        }
        vector<vector<int>> ans;
        vector<int> temp;
        while(true)
        {
            for(int i=1;i<201;i++)
            {
                if(count[i]>0){
                    temp.push_back(i);
                    --count[i];
                }
            }
            if(temp.size()==0) return ans;
            ans.push_back(temp);
            temp={};
        }
        return ans;
    }
};