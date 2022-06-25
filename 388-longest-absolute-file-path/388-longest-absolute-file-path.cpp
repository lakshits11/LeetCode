class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string data;
        // Map stores the len upto previous directory for the current explored path
        unordered_map<int, int> u;
        int res = 0;
        while(getline(ss, data, '\n'))
        {
            int numTabs = 0;
            while(data[numTabs]=='\t') numTabs++;
            
            // num tabs
            if(numTabs==0)
                u[numTabs] = data.size();
            
            else {
                // length upto previous dir + len("/") + no of chars after tabs for current filename/ dirname
                u[numTabs] = u[numTabs-1] + 1 + data.substr(numTabs).size();
            }
            
            
            if(data.find('.') != string::npos)
                res = max(res, u[numTabs]);
        }
        
        return res;
    }
};