class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> ans;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while(i<a.size() && j<b.size())
        {
            if(a[i]==b[j])
            {
                ans.push_back(a[i]);
                i++;j++;
            }
            else if(a[i]>b[j])
                j++;
            else i++;
        }
        return ans;
    }
};