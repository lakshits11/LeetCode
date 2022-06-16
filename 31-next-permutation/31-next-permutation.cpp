class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        int n = arr.size();
        if(n==0 || n==1) return;
        int i = n - 2;
        while(i>=0 && arr[i] >= arr[i+1])  i--;
        if(i>=0)
        {
            int j = n-1;
            while(arr[j]<=arr[i])   j--;
            swap(arr[j], arr[i]);
        }
        reverse(arr.begin()+i+1, arr.end());
    }
};