class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minn = arr[0];
        int maxx = 0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<minn)
                minn = arr[i];
            if((arr[i]-minn) > maxx)
                maxx = arr[i]-minn;
        }
        return maxx ;
    }
};