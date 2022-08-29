class Solution {
public:
    int specialArray(vector<int>& arr)
    {
        int temp[1001] = {};
        for(int i : arr)
        {
            temp[i]++;
        }
        int ans = arr.size();
        
        for(int i = 0; i < 1001; i++)
        {
            if(i == ans)
                return i;
            ans -= temp[i];
        }
        
        return -1;
    }
};