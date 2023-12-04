class Solution {
public:
    string largestGoodInteger(string nums) {
//         int arr[10];
//         memset(arr, 0, sizeof(arr));
//         for(int i=0;i<num.size();++i)
//         {
//             arr[num[i]-'0']++;
//         }
//         int ans = -1;
//         for(int i=0;i<10;i++)
//         {
            
//             if()
//         }
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        char res = 0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1] && nums[i]==nums[i-2])
                res = max(res, nums[i]);
        }
        return res==0 ? "" : string(3, res);
    }
};