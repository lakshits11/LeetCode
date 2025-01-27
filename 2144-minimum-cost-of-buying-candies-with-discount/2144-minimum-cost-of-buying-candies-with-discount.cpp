class Solution {
public:
    // int minimumCost(vector<int>& cost) {
    //     if(cost.size()==1) return cost[0];
    //     sort(cost.begin() , cost.end(), greater<int>());
    //     int ans=0;
    //     int i;
    //     for(i=0;i<cost.size()-2;i+=3)
    //     {
    //         ans += cost[i]+cost[i+1];
    //     }
    //     while(i<cost.size())
    //         ans+=cost[i++];
    //     return ans;
    // }



    int minimumCost(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = 0; i < A.size(); ++i)
            if (i % 3 != n % 3)
                res += A[i];
        return res;
    }
};