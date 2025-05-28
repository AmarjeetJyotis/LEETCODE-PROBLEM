class Solution {
public:
    string truncateSentence(string s, int k) {
        string str = "";
        string ans = "";
        int i = 0;

        while(i<s.length()){
            if(s[i] != ' '){
                str += s[i];
            }
            else{
                if(k>1){
                    ans = ans + str +" ";
                    str = "";
                    k--;
                }
                else{
                    break;
                }
            }
            i++;
        }
        ans += str;

        return ans;
    }
};