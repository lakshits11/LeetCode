class Solution {
public:
    string intToRoman(int N) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string ans = "";
        for(int i=0; N; ++i)
        {
            while(N>=val[i]){
                ans+=rom[i];
                N-=val[i];
            }
        }
        return ans;
        
    }
};