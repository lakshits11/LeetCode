// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int cnt=0;
//         int i=0, j=nums.size()-1;
//         while(i<j)
//         {
//             if(nums[i]+nums[j]>k)
//                 j--;
//             else if(nums[i]+nums[j]<k)
//                 i++;
//             else
//             {
//                 cnt++;i++;j--;
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (int n : nums) {
            if (map[k - n] > 0) {
                res++;
                map[k - n]--;
            } else {
                map[n]++;
            }
        }
        return res;
    }
};