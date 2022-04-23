class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1]++;
        for(int i=1;i<=n;i++){
            if(digits[n-i]>9){
                digits[n-i]=0;
                if(i==n){
                    digits.insert(digits.begin(), 1);
                }
                else{
                    digits[n-i-1]++;
                }
            }
        }
        return digits;
    }
};