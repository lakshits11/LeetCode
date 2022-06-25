// class Solution {
// public:
//     string decodeString(string s) {
//         stack<string> st;
//         string ans;
//         for(int i=0;i<s.size();++i)
//         {
//             if(s[i]!=']')
//             {
//                 if(isdigit[s[i]])
//                     st.push(s[i]+'0');
//                 else
//                     st.push(s[i]);
//             }
//             else
//             {
//                 string temp = "";
//                 while(st.top() != '[')
//                 {
//                     temp.insert(0, 1, st.top());
//                     st.pop();
//                 }
//                 st.pop();
//                 string k = "";
//                 while(!st.empty() && isdigit(st.top()))
//                 {
//                     k.insert(0,1,st.top());
//                     st.pop();
//                 }
//                 int x = stoi(k);
//                 k = temp;
//                 while(x--)  temp.append(k);
//                 st.push(temp);
//             }
//         }
//         while(!s.empty())
//         {
//             ans.push_back(s.top());
//         }
//     }
// };

class Solution {
    string decodeString(string& s, int& i) {
        string result;
        while(i < s.length() && s[i] != ']'){
            if(isdigit(s[i])){
                int k = 0;
                while(i < s.length() && isdigit(s[i]))
                    k = k*10 + s[i++] - '0';
                i++;
                string r = decodeString(s, i);
                while(k-- > 0)
                    result += r;
                i++;
            } else
                result += s[i++];
        }
        return result;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};