class Solution {
private:
    string reverse(string t){
        int s = 0, e = t.length() - 1;
        while(s < e){
            swap(t[s++], t[e--]);
        }
        return t;
    }
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<string> stk;
        string t = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                stk.push(t);
                stk.push("(");
                t = "";
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                t += s[i];
            }
            else if(s[i] == ')'){
                stk.push(t);
                t = "";
                while(!stk.empty()){
                    if(stk.top() == "("){
                        stk.pop();
                        stk.push(reverse(t));
                        t = "";
                        break;
                    }
                    else{
                        t = stk.top() + t;
                    }
                    stk.pop();
                }
            }
            if(i == n - 1 && s[i] >= 'a' && s[i] <= 'z') stk.push(t);
        }
        t = "";
        while(!stk.empty()){
            t = stk.top() + t;
            stk.pop();
        }
        return t;
    }
};