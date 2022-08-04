class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int arr[10000001];
        memset(arr, -1, sizeof(arr));
        int mini = INT_MAX;
        for(int i = 0; i < cards.size(); i++)
        {
            if(arr[cards[i]] == -1)
                arr[cards[i]] = i;
            else
            {
                mini = min(i - arr[cards[i]], mini);
                arr[cards[i]] = i;
            }
        }
        return mini==INT_MAX ? -1 : mini+1;
    }
};