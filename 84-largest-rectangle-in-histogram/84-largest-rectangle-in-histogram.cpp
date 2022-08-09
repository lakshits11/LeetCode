class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        stack<int> st;
        int maxA = 0;
        int n = ht.size();
        for(int i = 0; i <= n; i++)
        {
            // either we are at last element, or st.top() has greater element than current element
            while(!st.empty() && (i==n || ht[st.top()] >= ht[i]))
            {
                int height = ht[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};