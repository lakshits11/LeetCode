class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(int i=0;i<arr.size();++i)
        {
            int temp = arr[i]%k;
            if(temp<0) temp+=k;
            freq[temp]++;
        }
        if(freq[0]%2) return false;

        for(int i = 1; i <= k/2; ++i)
        {
            if(freq[i]!=freq[k-i]) return false;
        }

        return true;
    }
};