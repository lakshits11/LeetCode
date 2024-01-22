class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int x = -1, temp, n = arr.size();
        for(int i=n-1;i>=0;--i)
        {
            temp = arr[i];
            arr[i] = x;
            x = max(x, temp);
        }
        return arr;
    }
};