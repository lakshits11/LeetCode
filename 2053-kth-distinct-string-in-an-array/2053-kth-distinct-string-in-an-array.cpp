class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> u;
        int count = 0;
        for(string ss : arr)
        {
            u[ss]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(u[arr[i]] == 1){
                count++;
                if(count==k)
                    return arr[i];
            }
        }
        return "";
    }
};