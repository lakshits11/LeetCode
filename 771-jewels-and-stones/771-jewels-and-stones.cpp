class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> v1(255,0);
        int count=0;
        for(char i : jewels)
        {
            v1[i-'A'] = 1;
        }
        for(char i : stones)
        {
            if(v1[i-'A'] == 1)
                count+=1;
        }
        return count;
    }
};