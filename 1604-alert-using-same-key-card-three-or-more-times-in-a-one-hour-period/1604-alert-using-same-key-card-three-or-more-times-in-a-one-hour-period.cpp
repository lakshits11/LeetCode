class Solution {
public:
    // A -> keyName, b -> keyTime
    vector<string> alertNames(vector<string>& A, vector<string>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<string> res;
        unordered_map<string, vector<int>> u;
        for(int i = 0; i < A.size(); i++)
        {
            u[A[i]].push_back(stoi(B[i].substr(0, 2) + B[i].substr(3, 2)));
        }
        
        for(auto &[person, times] : u)
        {
            sort(times.begin(), times.end());
            for(int i = 2; i < times.size(); i++)
            {
                if(times[i] <= times[i-2] + 100)
                {
                    res.push_back(person);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
        
        
    }
};