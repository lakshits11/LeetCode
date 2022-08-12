class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int avg = accumulate(arr.begin(), arr.end(), 0);
        if(avg % 3 != 0)
            return false;
        avg /= 3;
        int sum = 0, cnt = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum += arr[i];
            if(sum == avg)
            {
                cnt++;
                sum = 0;
            }
            if(cnt==3)
                return true;
        }
        return false;;
        
    }
};