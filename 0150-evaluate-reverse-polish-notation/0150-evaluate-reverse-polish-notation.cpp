class Solution
{
public:
    bool isdigitt(string x)
    {
        if(isdigit(x[0]))
            return true;
        else if(x[0]=='-' and x.length()>1)
            return true;
        return false;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (string x : tokens)
        {
            if (isdigitt(x))
                s.push(stoi(x));
            else
            {
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();
                if (x == "+")
                    s.push(val1 + val2);
                else if (x == "-")
                    s.push(val1 - val2);
                else if (x == "*")
                    s.push(val1 * val2);
                else if (x == "/")
                    s.push(val1 / val2);
            }
        }
        return s.top();
    }
};