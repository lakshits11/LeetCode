// class Solution {
// public:
//     bool rec(string &s, int start, vector<int> &nums)
//     {
//         int n = s.size();
//         if(start >= n && nums.size()>=3) return true;

//         int maxSplitSize = (s[start]=='0') ? 1 : 10;

//         for(int i=1; i<=maxSplitSize && start+i <= s.size(); i++)
//         {
//             long long num = stoll(s.substr(start, i));
//             if(num > INT_MAX) return false;

//             int sz = nums.size();
//             if(sz>=2 && nums[sz-1]+nums[sz-2]<num) return false;

//             if(sz<=1 || nums[sz-1]+nums[sz-2]==num)
//             {
//                 nums.push_back(num);
//                 if(rec(s, start+i, nums)) return true;
//                 nums.pop_back();
//             }
//         }

//         return false;
//     }

//     vector<int> splitIntoFibonacci(string s) {
//         vector<int> nums;
//         rec(s, 0, nums);
//         return nums;
//     }
// };

class Solution {
public:

    bool backtrack(string &S, int start, vector<int> &nums){        
        int n = S.size();
	// If we reached end of string & we have more than 2 elements
	// in our sequence then return true
        if(start >= n && nums.size()>=3){
            return true;
        }
	// Since '0' in beginning is not allowed therefore if the current char is '0'
	// then we can use it alone only and cannot extend it by adding more chars at the back.
	// Otherwise we make take upto 10 chars (length of INT_MAX)
        int maxSplitSize = (S[start]=='0') ? 1 : 10;
	// Try getting a solution by forming a number with 'i' chars begginning with 'start'
        for(int i=1; i<=maxSplitSize && start+i<=S.size(); i++){
            long long num = stoll(S.substr(start, i));
            if(num > INT_MAX)
                return false;
            int sz = nums.size();
            
	// If fibonacci property is not satisfied then we cannot get a solution
            if(sz >= 2 && (long long)nums[sz-1] + (long long)nums[sz-2] < num)
                return false;
            if(sz<=1 || (long long)nums[sz-1] + (long long)nums[sz-2]==num){
                nums.push_back(num);
                if(backtrack(S, start+i, nums))
                    return true;
                nums.pop_back();                
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> nums;
	// Backtrack from 0th char
        backtrack(S, 0, nums);
        return nums;
    }
};