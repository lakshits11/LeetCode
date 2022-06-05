// class TextEditor {
// public:
//     string ans;
//     int cp = 0; // cursor position
//     TextEditor() {
//         ans = "|";
//         cout << "ans: " << ans << "\n";
//     }
//     void addText(string text) {
//         ans.insert(cp, text);
//         cp+=(text.length());
//         cout << "ans: " << ans << "\n";
        
//     }
//     int deleteText(int k) {
//         int anss = min(cp, k);
//         ans.erase(ans.begin()+cp-k, ans.begin()+cp);
//         cp-=k;
//         cout << "ans: " << ans << "\n"; 
//         return anss;
//     }
    
//     string cursorLeft(int k) {
//         if(cp==0)
//         {
//             k = min(k,10);
//             return ans.substr(cp,k);
//         }
        
//         // int ocp = cp;
//         auto x = ans.begin()+cp;
//         ans.erase(x);
//         cp = (cp - k)>=0 ? (cp-k) : 0;
//         ans.insert(cp, "|");
//         k = min(10,k);
//         return ans.substr(cp,k);
//         // return "abc";
//     }
    
//     string cursorRight(int k) {
//         cout << "ans: " << ans << "\n";
//         if(cp == ans.length()-1)
//         {
//             k = min(k,10);
//             return ans.substr(cp-k,k);
//         }
//         // int ocp = cp;
//         // ans.erase(ans.begin()+cp);
//         // ans.insert(cp+k, "|");
//         // cp += k;
//         // k = min(10,k);
//         // return ans.substr(ocp,k);
//         return "abc";
//     }
// };

// /**
//  * Your TextEditor object will be instantiated and called as such:
//  * TextEditor* obj = new TextEditor();
//  * obj->addText(text);
//  * int param_2 = obj->deleteText(k);
//  * string param_3 = obj->cursorLeft(k);
//  * string param_4 = obj->cursorRight(k);
//  */


class TextEditor {
    
    stack<char> left;
    stack<char> right;
public:
    TextEditor() {
    ios_base::sync_with_stdio(0);
        
    }
    
    void addText(string text) {
        for(auto &c : text){
            left.push(c);
        }
    }
    
    int deleteText(int k) {
        int cnt=0;
        while(!left.empty() and k>0){
            left.pop();
            cnt++;
            k--;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() and k>0){
            char c = left.top();left.pop();
            right.push(c);
            k--;
        }
		// returning the last min(10, len) characters to the left of the cursor
        return cursorShiftString();
    }
    
    string cursorRight(int k) {
        while(!right.empty() and k>0){
            char c = right.top();right.pop();
            left.push(c);
            k--;
        }
		// returning the last min(10, len) characters to the left of the cursor
        return cursorShiftString();
    }
    
	// function to return the last min(10, len) characters to the left of the cursor
    string cursorShiftString(){
        string rtn = "";
        int cnt=10;
        while(!left.empty() and cnt>0){
            char c = left.top();left.pop();
            rtn += c;
            cnt--;
        }
        reverse(rtn.begin(),rtn.end());
        for(int i=0;i<rtn.size();i++){
            left.push(rtn[i]);
        }
        return rtn;
    }
};