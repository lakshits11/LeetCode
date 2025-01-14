class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> a(n, 0);
        vector<int> ans;
        int cmn = 0;
        for(int i=0;i<A.size();i++)
        {
            a[A[i]-1]++;
            if(a[A[i]-1] == 2) cmn++;
            a[B[i]-1]++;
            if(a[B[i]-1] == 2) cmn++;
            ans.push_back(cmn);
        }
        return ans;
    }
};