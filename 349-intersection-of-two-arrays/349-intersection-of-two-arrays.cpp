class Solution {
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        /*
        FACEBOOK INTERVIEW QUESTION
        Given 2 sorted arrays, find their intersection in O(n) time and O(1) space.
        Here in below solution, if arrays were already sorted,
        Time complexity is O(N) and Space Complexity is O(1)
        */
        vector<int> ans;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;

        while(i<a.size() && j < b.size())
        {
            int left = a[i], right = b[j];
            if(left == right)
            {
                ans.push_back(right);
                while(i<a.size() && a[i] == left)
                    i++;
                while(j<b.size() && b[j] == right)
                    j++;
                continue;
            }
            if(left < right)
            {
                while(i<a.size() && a[i] == left)
                    i++;
            }
            else
                while(j<b.size() && b[j] == right)
                    j++;
        }
        return ans;

    }
};