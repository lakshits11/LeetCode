class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), ans=0;
        int i = 0, j = n-1;
        while(i<=j) 
        {
            ans++;
            if(people[i]+people[j]>limit) {
                j--;
            }
            else {
                i++;
                j--;
            }
        }
        return ans;
    }
};