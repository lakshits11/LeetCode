/**************** CODE FOR FINDING NUMBER OF OPERATIONS REQUIRED ************************

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int op = 0, x=0;
        for(int i=0;i<target.size();i++)
        {
            op += (target[i]-x-1)*2 + 1;
            x = target[i];
        }
        return op;
    }
};
*/


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        for (int num : target) {
            while (i < num - 1) {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            ans.push_back("Push");
            i++;
        }
        return ans;
    }
};