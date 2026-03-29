class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        stack<int> st;
        int maxArea = 0;
        int n = h.size();

        for (int i = 0; i <= n; i++)
        {
            int currHeight = (i == n) ? 0 : h[i];

            // we have found the right boundary for all the elements present in stack
            // stack contains elements in increasing order from bottom to top
            // rightBoundary = i;
            // and since stack contains elements in increasing order, left boundary will be the next top element of stack after popping the current top one
            while (!st.empty() && currHeight < h[st.top()])
            {
                int topIndex = st.top();
                st.pop();
                int ht = h[topIndex];

                int leftBoundary = st.empty() ? -1 : st.top();
                int width = i - leftBoundary - 1;

                maxArea = max(maxArea, width * ht);
            }

            if (i < n)
                st.push(i);
        }

        return maxArea;
    }
};