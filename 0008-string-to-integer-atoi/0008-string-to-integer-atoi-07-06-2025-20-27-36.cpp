static const auto speedup = []() -> int {
   std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();

class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int n = s.size();
        int ans = 0, ind = 0;

        // 1. Discard all spaces from beginning of string
        while (ind < n && s[ind] == ' ')
            ind++;

        // 2. Decide sign of answer (positive or negative)
        if (ind < n && s[ind] == '+')
        {
            sign = 1;
            ind++;
        }
        else if (ind < n && s[ind] == '-')
        {
            sign = -1;
            ind++;
        }

        // 3. Traverse remaining string and stop when you encounter a non digit char.
        //    End of string is also considered a non digit char
        while (ind < n && isdigit(s[ind]))
        {
            int digit = s[ind] - '0';

            // 4. Check overflow and underflow conditions
            /*
                At each step we are 10xing the ans and adding digit
                In C++, integers are stored in 32 bits. So integer range is -2^31 to 2^31-1
            */
            if ((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = 10 * ans + digit;
            ind++;
        }

        return sign * ans;
    }
};