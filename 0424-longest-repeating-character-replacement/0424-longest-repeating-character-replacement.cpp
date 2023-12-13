/*
In case anyone is confused by this solution, here's another way of explaining it:

end-start+1 = size of the current window
maxCount = largest count of a single, unique character in the current window

The main equation is: end-start+1-maxCount

When end-start+1-maxCount == 0, then then the window is filled with only one character
When end-start+1-maxCount > 0, then we have characters in the window that are NOT the character that occurs the most. end-start+1-maxCount is equal to exactly the # of characters that are NOT the character that occurs the most in that window. Example: For a window "xxxyz", end-start+1-maxCount would equal 2. (maxCount is 3 and there are 2 characters here, "y" and "z" that are not "x" in the window.)

We are allowed to have at most k replacements in the window, so when end-start+1-maxCount > k, then there are more characters in the window than we can replace, and we need to shrink the window.

If we have window with "xxxy" and k = 1, that's fine because end-start+1-maxCount = 1, which is not > k. maxLength gets updated to 4.

But if we then find a "z" after, like "xxxyz", then we need to shrink the window because now end-start+1-maxCount = 2, and 2 > 1. The window becomes "xxyz".

maxCount may be invalid at some points, but this doesn't matter, because it was valid earlier in the string, and all that matters is finding the max window that occurred anywhere in the string. Additionally, it will expand if and only if enough repeating characters appear in the window to make it expand. So whenever it expands, it's a valid expansion.

Hope that helps.

P.S. Yes, as several other people mentioned already, the while should be replaced with if. The time complexity is exactly the same, because the while-loop only runs once anyway.

*/

/*

The problem says that we can make at most k changes to the string (any character can be replaced with any other character). So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. The answer to this is

length of the entire string - number of times of the maximum occurring character in the string

Given this, we can apply the at most k changes constraint and maintain a sliding window such that

(length of substring - number of times of the maximum occurring character in the substring) <= k

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int ans = -1;
        int end=0,start=0,maxCount=INT_MIN;
        for(end=0;end<s.size();++end)
        {
            maxCount = max(maxCount, ++counts[s[end]-'A']);
            while(end-start+1 - maxCount > k)
            {
                --counts[s[start++]-'A'];
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};