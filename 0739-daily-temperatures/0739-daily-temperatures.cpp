class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> ans(n, -1);
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && st.top().first<=temp[i])
                st.pop();
            if(!st.empty())
                ans[i] = st.top().second;
            else ans[i]=-1;
            
            st.push({temp[i], i});
        }
        for(int i=0;i<n;++i)
        {
            if(ans[i]!=-1)
                ans[i] = ans[i]-i;
            else ans[i]=0;
        }
        return ans;
    }
};