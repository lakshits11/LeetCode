class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> nextGreater(n, -1);
        for(int i=n-1; i>=0; i--) {
            while(true) {
                if(s.empty()){
                    s.push(i);
                    nextGreater[i] = 0;
                    break;
                }else if(temperatures[s.top()] <= temperatures[i]){
                    s.pop();
                }else if(temperatures[s.top()] > temperatures[i]){
                    nextGreater[i] = s.top()-i;
                    s.push(i);
                    break;
                }
            }
        }
        return nextGreater;
    }
};