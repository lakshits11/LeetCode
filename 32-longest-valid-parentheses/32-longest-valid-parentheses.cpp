class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.length();
        int maxAns = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                {
                    maxAns = max(maxAns, i-st.top());
                }
            }
        }
        return maxAns;
    }
};