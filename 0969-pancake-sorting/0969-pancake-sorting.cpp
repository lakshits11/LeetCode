class Solution {
private:
    void flip(vector<int> &arr, int k)
    {
        reverse(arr.begin(), arr.begin()+k);
    }
    int findv(vector<int> &arr, int target)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == target) return i;
        }
        return -1;
    }
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for(int valueToSort = arr.size(); valueToSort > 0; valueToSort--)
        {
            int ind = findv(arr, valueToSort);
            if(ind == valueToSort - 1) continue;
            cout << "ind: " << ind << ", count: " << arr.size() - valueToSort << "\n";
            if(ind != 0)
            {
                ans.push_back(ind+1);
                flip(arr, ind+1);
            }
            ans.push_back(valueToSort);
            flip(arr, valueToSort);
        }
        return ans;
    }
};