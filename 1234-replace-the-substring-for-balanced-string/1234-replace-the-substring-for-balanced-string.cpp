static const auto speedup = []() {
   std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();

/*
I found really hard to get the intution behind this problem .
The main Idea of the intution lies with the 2 facts:

The string is contains only "Q","W","R","S"
2.The len of the string is a mutlple of 4.
3.We are not looking for the replcement substring, just length is what we require.
Based on the above facts , we can come to a vague idea , where

The freq of all the char should be equal to the len(s)//4 .
If any of the char's freq is excess than the first condition, then its occupying some other char's position. (Remember the fact the string is contains only "Q","W","R","S" ) -->which means One char is overpowering the other char (For fun : No communism as one char is over eating the other char's quota :) )
Alright , now its time to eliminate this overpowering char .
The trick here is , you can eliminate this overpowering char with one condition , that is it should be contigous ,ie you cannot remove one occurance in front and some where else and replace the missing char , so if we are eliminating then it should be a substring!
Time to eliminate :
1.Start from the 0th index, keep moving forward and check if the condition is met , (ie there should not be any over powering char : One easy way to check is maxFreq of freqMap should be equal to len(s)//4)
2. Once the above condition is met , we have found some substring , say
"QRRRWERE" ---> R is over Powering (freq : 4)
From 0th index till 3rd "QRR" --> After eliminating this substring the overPowering R is now balanced ( maxFreq now is 2) , now we found some replacement .
Lets make it as minimal as possible, by shrinking the substring from left and keeping the condition (maxFreq==len(s)//4) ,
So "QRR" --->"RR" (Most optimal replacement) . Hence the answer is 2.
*/

class Solution
{
public:
    int balancedString(string s)
    {
        int n = s.size();
        unordered_map<char, int> count;
        for (char &c : s)
        {
            count[c]++;
        }
        int l = 0;
        int window = n;
        int m = n / 4;

        for (int r = 0; r < n; ++r)
        {
            count[s[r]]--;
            while (count['Q'] <= m && count['W'] <= m && count['E'] <= m && count['R'] <= m)
            {
                count[s[l]]++;
                window = min(window, r - l + 1);
                l++;

                if (l >= n) break;
            }
        }
        return window;
    }
};