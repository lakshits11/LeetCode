static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int maxRepOpt1(string &t) {
        vector<int> arr[26];
        for(int i=0;i<t.size();i++)
            arr[t[i]-'a'].push_back(i);
        int res = 0;
        
        for(int i=0;i<26;i++)
        {
            vector<int> &temp = arr[i];
            int curr = 1, prev = 0, sum = 0;
            for(int j=1; j < temp.size();++j)
            {
                if(temp[j] == temp[j-1]+1) ++curr;
                else if(temp[j] == temp[j-1]+2) {prev = curr;curr=1;}
                else {prev = 0;curr=1;}
                sum = max(sum, prev+curr);
            }
            // sum<temp.size() means ki abhi prev aur curr ke baad bhi aur elements remaining hai to:
            // 1. agar suppose prev aur curr ke beech ek element aata hai i.e. unke beech ka diff == 2, then sum<temp.size() ka matlab hai abhi aur instances of our current alphabet are remanining which can replace that beech waala element. So we added one to that
            // 2. else if sum==temp.size, i.e. all instances  of current element are covered, so no adding one
            res = max(res, sum+(sum<temp.size()?1:0));
        }
        
        
        return res;
    }
};